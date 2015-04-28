/* Semantics.c
   Support and semantic action routines.
   
*/

#include <strings.h>
#include <stdlib.h>

#include "CodeGen.h"
#include "Semantics.h"
#include "SymTab.h"
#include "IOMngr.h"

extern struct SymTab *table;

/* Semantics support routines */

struct ExprRes *  doIntLit(char * digits)  { 

   struct ExprRes *res;
  
  res = (struct ExprRes *) malloc(sizeof(struct ExprRes));
  res->Reg = AvailTmpReg();
  res->Instrs = GenInstr(NULL,"li",TmpRegName(res->Reg),digits,NULL);

  return res;
}

struct ExprRes *  doRval(char * name)  { 

   struct ExprRes *res;
  
   if (!FindName(table, name)) {
		WriteIndicator(GetCurrentColumn());
		WriteMessage("Undeclared variable");
   }
  res = (struct ExprRes *) malloc(sizeof(struct ExprRes));
  res->Reg = AvailTmpReg();
  res->Instrs = GenInstr(NULL,"lw",TmpRegName(res->Reg),name,NULL);

  return res;
}

struct ExprRes *  doAdd(struct ExprRes * Res1, struct ExprRes * Res2)  { 

   int reg;
   
  reg = AvailTmpReg();
  AppendSeq(Res1->Instrs,Res2->Instrs);
  AppendSeq(Res1->Instrs,GenInstr(NULL,"add",
                                       TmpRegName(reg),
                                       TmpRegName(Res1->Reg),
                                       TmpRegName(Res2->Reg)));
  ReleaseTmpReg(Res1->Reg);
  ReleaseTmpReg(Res2->Reg);
  Res1->Reg = reg;
  free(Res2);
  return Res1;
}

struct ExprRes * doBinaryMinus(struct ExprRes * Res1, struct ExprRes * Res2){
    int reg;
    
    reg = AvailTmpReg();
    AppendSeq(Res1->Instrs, Res2->Instrs);
    AppendSeq(Res1->Instrs, GenInstr(NULL,"sub",
                                               TmpRegName(reg),
                                               TmpRegName(Res1->Reg),
                                               TmpRegName(Res2->Reg)));
    ReleaseTmpReg(Res1->Reg);
    ReleaseTmpReg(Res2->Reg);
    Res1->Reg = reg;
    free(Res2);
    return Res1;
}

struct ExprRes * doNeg(struct ExprRes * Res1){
    int reg;
    reg = AvailTmpReg();
    AppendSeq(Res1->Instrs, GenInstr(NULL, "sub",
                                                TmpRegName(reg),
                                                "$0",
                                                TmpRegName(Res1->Reg)));
    ReleaseTmpReg(Res1->Reg);
    Res1->Reg = reg;
   
    return Res1;
}

struct ExprRes * doPower(struct ExprRes * Res1, struct ExprRes * Res2) {
    int reg;
    reg = AvailTmpReg();
    
    struct InstrSeq* iseq;
    int pow = AvailTmpReg();
    int current = AvailTmpReg();
    char * l1 = GenLabel();
    char * l2 = GenLabel();

    iseq = GenInstr(NULL, "move", TmpRegName(pow), "$0", NULL);
    AppendSeq(iseq, GenInstr(NULL, "addi", TmpRegName(current), "$0", "1"));
    AppendSeq(iseq, GenInstr(NULL, "beq", TmpRegName(Res2->Reg), "$0", l2));
    AppendSeq(iseq, GenInstr(l1, NULL, NULL, NULL, NULL));
    AppendSeq(iseq, GenInstr(NULL, "mul", TmpRegName(current), TmpRegName(current), TmpRegName(Res1->Reg)));
    AppendSeq(iseq, GenInstr(NULL, "addi", TmpRegName(pow), TmpRegName(pow), "1"));
    AppendSeq(iseq, GenInstr(NULL, "blt", TmpRegName(pow), TmpRegName(Res2->Reg), l1));
    AppendSeq(iseq, GenInstr(l2, NULL, NULL, NULL, NULL));

    AppendSeq(Res1->Instrs, Res2->Instrs);
    AppendSeq(Res1->Instrs, iseq);
    ReleaseTmpReg(Res1->Reg);
    ReleaseTmpReg(Res2->Reg);
    ReleaseTmpReg(pow);
    Res1->Reg = current;
    free(l1);
    free(l2);
    free(Res2);

    return Res1;
        
    

  }
struct ExprRes *  doMult(struct ExprRes * Res1, struct ExprRes * Res2)  { 

   int reg;
   
  reg = AvailTmpReg();
  AppendSeq(Res1->Instrs,Res2->Instrs);
  AppendSeq(Res1->Instrs,GenInstr(NULL,"mul",
                                       TmpRegName(reg),
                                       TmpRegName(Res1->Reg),
                                       TmpRegName(Res2->Reg)));
  ReleaseTmpReg(Res1->Reg);
  ReleaseTmpReg(Res2->Reg);
  Res1->Reg = reg;
  free(Res2);
  return Res1;
}

struct ExprRes * doDivide(struct ExprRes * Res1, struct ExprRes * Res2){
    int reg;

    reg = AvailTmpReg();
    AppendSeq(Res1->Instrs, Res2->Instrs);
    AppendSeq(Res1->Instrs, GenInstr(NULL,"div",
                                                TmpRegName(reg),
                                                TmpRegName(Res1->Reg),
                                                TmpRegName(Res2->Reg)));
    ReleaseTmpReg(Res1->Reg);
    ReleaseTmpReg(Res2->Reg);
    Res1->Reg = reg;
    free(Res2);
    return Res1;
}

struct ExprRes * doMod(struct ExprRes * Res1, struct ExprRes * Res2){
    int reg;

    reg = AvailTmpReg();

    AppendSeq(Res1->Instrs, Res2->Instrs);
    AppendSeq(Res1->Instrs, GenInstr(NULL,"rem",
                                                TmpRegName(reg),
                                                TmpRegName(Res1->Reg),
                                                TmpRegName(Res2->Reg)));
    ReleaseTmpReg(Res1->Reg);
    ReleaseTmpReg(Res2->Reg);
    Res1->Reg = reg;
    free(Res2);
    return Res1;
}

struct InstrSeq * doPrint(struct ExprRes * Expr) { 

  struct InstrSeq *code;
    
  code = Expr->Instrs;
  
    AppendSeq(code,GenInstr(NULL,"li","$v0","1",NULL));
    AppendSeq(code,GenInstr(NULL,"move","$a0",TmpRegName(Expr->Reg),NULL));
    AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));

    AppendSeq(code,GenInstr(NULL,"li","$v0","4",NULL));
    AppendSeq(code,GenInstr(NULL,"la","$a0","_nl",NULL));
   AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));

    ReleaseTmpReg(Expr->Reg);
    free(Expr);

  return code;
}

struct InstrSeq * doAssign(char *name, struct ExprRes * Expr) { 

  struct InstrSeq *code;
  

   if (!FindName(table, name)) {
		WriteIndicator(GetCurrentColumn());
		WriteMessage("Undeclared variable");
   }

  code = Expr->Instrs;
  
  AppendSeq(code,GenInstr(NULL,"sw",TmpRegName(Expr->Reg), name,NULL));

  ReleaseTmpReg(Expr->Reg);
  free(Expr);
  
  return code;
}

extern struct BExprRes * doBExpr(struct ExprRes * Res1,  struct ExprRes * Res2) {
	struct BExprRes * bRes;
	AppendSeq(Res1->Instrs, Res2->Instrs);
 	bRes = (struct BExprRes *) malloc(sizeof(struct BExprRes));
	bRes->Label = GenLabel();
	AppendSeq(Res1->Instrs, GenInstr(NULL, "bne", TmpRegName(Res1->Reg), TmpRegName(Res2->Reg), bRes->Label));
	bRes->Instrs = Res1->Instrs;
	ReleaseTmpReg(Res1->Reg);
  	ReleaseTmpReg(Res2->Reg);
	free(Res1);
	free(Res2);
	return bRes;
}

extern struct ExprRes * doRelOp(struct ExprRes * Res1, struct ExprRes * Res2, int op){
    
    struct InstrSeq * iseq;
    char * t_res = GenLabel();
    
    char * end = GenLabel();
    int reg = AvailTmpReg();

    if (op == 0 ){
        iseq = GenInstr(NULL, "beq", TmpRegName(Res1->Reg), TmpRegName(Res2->Reg), t_res);
    }
    else if (op == 1){
        iseq = GenInstr(NULL, "beq", TmpRegName(Res1->Reg), TmpRegName(Res2->Reg), t_res);
        AppendSeq(iseq, GenInstr(NULL, "bgt", TmpRegName(Res1->Reg), TmpRegName(Res2->Reg), t_res));
    }
    else if (op == 2) {
        iseq = GenInstr(NULL, "beq", TmpRegName(Res1->Reg), TmpRegName(Res2->Reg), t_res);
        AppendSeq(iseq, GenInstr(NULL, "blt", TmpRegName(Res1->Reg), TmpRegName(Res2->Reg), t_res));
    }
    else if (op == 3) {
        iseq = GenInstr(NULL, "bne", TmpRegName(Res1->Reg), TmpRegName(Res2->Reg), t_res);
    }
    else if (op == 4) {
        iseq = GenInstr(NULL, "blt", TmpRegName(Res1->Reg), TmpRegName(Res2->Reg),t_res);
    }
    else if (op == 5) {
        iseq = GenInstr(NULL, "bgt", TmpRegName(Res1->Reg), TmpRegName(Res2->Reg), t_res);
    }

    AppendSeq(iseq, GenInstr(NULL, "li", TmpRegName(reg), "0", NULL));
    AppendSeq(iseq, GenInstr(NULL, "b", end, NULL,NULL));
    AppendSeq(iseq, GenInstr(t_res, NULL,NULL,NULL,NULL));
    AppendSeq(iseq, GenInstr(NULL, "li", TmpRegName(reg), "1", NULL));
    AppendSeq(iseq, GenInstr(end, NULL,NULL,NULL,NULL));

    AppendSeq(Res1->Instrs, Res2->Instrs);
    AppendSeq(Res1->Instrs, iseq);
    ReleaseTmpReg(Res1->Reg);
    ReleaseTmpReg(Res2->Reg);
    free(t_res);
    free(end);
    free(Res2);
    Res1->Reg = reg;
    return Res1;
}


extern struct InstrSeq * doIf(struct ExprRes * bRes, struct InstrSeq * seq) {
	return NULL;
}

/*

extern struct InstrSeq * doIf(struct ExprRes *res1, struct ExprRes *res2, struct InstrSeq * seq) {
	struct InstrSeq *seq2;
	char * label;
	label = GenLabel();
	AppendSeq(res1->Instrs, res2->Instrs);
	AppendSeq(res1->Instrs, GenInstr(NULL, "bne", TmpRegName(res1->Reg), TmpRegName(res2->Reg), label));
	seq2 = AppendSeq(res1->Instrs, seq);
	AppendSeq(seq2, GenInstr(label, NULL, NULL, NULL, NULL));
	ReleaseTmpReg(res1->Reg);
  	ReleaseTmpReg(res2->Reg);
	free(res1);
	free(res2);
	return seq2;
}

*/
void							 
Finish(struct InstrSeq *Code)
{ struct InstrSeq *code;
  struct SymEntry *entry;
  struct Attr * attr;


  code = GenInstr(NULL,".text",NULL,NULL,NULL);
  AppendSeq(code,GenInstr(NULL,".globl","main",NULL,NULL));
  AppendSeq(code, GenInstr("main",NULL,NULL,NULL,NULL));
  AppendSeq(code,Code);
  AppendSeq(code, GenInstr(NULL, "li", "$v0", "10", NULL)); 
  AppendSeq(code, GenInstr(NULL,"syscall",NULL,NULL,NULL));
  AppendSeq(code,GenInstr(NULL,".data",NULL,NULL,NULL));
  AppendSeq(code,GenInstr(NULL,".align","4",NULL,NULL));
  AppendSeq(code,GenInstr("_nl",".asciiz","\"\\n\"",NULL,NULL));

 entry = FirstEntry(table);
 while (entry) {
	AppendSeq(code,GenInstr((char *) GetName(entry),".word","0",NULL,NULL));
        entry = NextEntry(table, entry);
 }
  
  WriteSeq(code);
  
  return;
}




