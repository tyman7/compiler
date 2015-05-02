/* Semantics.c
   Support and semantic action routines.
   
*/

#include <string.h>
#include <stdlib.h>
#include "CodeGen.h"
#include "Semantics.h"
#include "SymTab.h"
#include "IOMngr.h"

extern struct SymTab *table;

/* Semantics support routines */


//music - exposions in the sky
//drying of the lawns



struct ExprRes * doStrLit(char * str){
    struct ExprRes *res;
    struct StrLabels * strl;
    strl =  malloc(sizeof(struct StrLabels));
    strl->SLabel = GenLabel();
    strl->Str = strdup( str);
    strl->next = slabels;
    slabels = strl; 
    res = (struct ExprRes *) malloc(sizeof(struct ExprRes));
    res->Reg = AvailTmpReg();
    res->Instrs = GenInstr(NULL, "la", TmpRegName(res->Reg),strl->SLabel, NULL);
    res->Type = TYPE_STR;   
    return res;
}


struct ExprRes *  doIntLit(char * digits)  { 

   struct ExprRes *res;
  
  res = (struct ExprRes *) malloc(sizeof(struct ExprRes));
  res->Reg = AvailTmpReg();
  res->Instrs = GenInstr(NULL,"li",TmpRegName(res->Reg),digits,NULL);
  res->Type = TYPE_INT;
  return res;
}

struct ExprRes * doBoolLit(int bol){
    struct ExprRes *res;
    res = (struct ExprRes *) malloc(sizeof(struct ExprRes));
    res->Reg = AvailTmpReg();
    res->Type = TYPE_BOOL;
    if( bol ){
        res->Instrs = GenInstr(NULL,"li", TmpRegName(res->Reg),"1",NULL);
    }
    else {
        res->Instrs = GenInstr(NULL, "li", TmpRegName(res->Reg),"0",NULL);
    }
    return res;
}


struct ExprRes *  doRval(char * name)  { 
   struct ExprRes *res;
   struct SymEntry * e = FindName(table, name); 
   if (!e) {
		WriteIndicator(GetCurrentColumn());
		WriteMessage("Undeclared variable");
   }
   
  res = (struct ExprRes *) malloc(sizeof(struct ExprRes));
  res->Reg = AvailTmpReg();
  res->Instrs = GenInstr(NULL,"lw",TmpRegName(res->Reg),name,NULL);
  res->Type = ((struct Vtype *)e->Attributes)->Type;
  return res;
}

struct ExprRes * doOr(struct ExprRes * Res1, struct ExprRes * Res2){
    if(Res1->Type != TYPE_BOOL || Res2->Type != TYPE_BOOL){
        TypeError();
    }
    
    AppendSeq(Res1->Instrs, Res2->Instrs);
    AppendSeq(Res1->Instrs, GenInstr(NULL, "or", TmpRegName(Res1->Reg), TmpRegName(Res1->Reg), TmpRegName(Res2->Reg)));
    ReleaseTmpReg(Res2->Reg);
    free(Res2);
    return Res1;
}

struct ExprRes * doAnd(struct ExprRes * Res1, struct ExprRes * Res2){
    if(Res1->Type != TYPE_BOOL || Res2->Type != TYPE_BOOL){
        TypeError();
    }
    
    AppendSeq(Res1->Instrs, Res2->Instrs);
    AppendSeq(Res1->Instrs, GenInstr(NULL, "and", TmpRegName(Res1->Reg), TmpRegName(Res1->Reg), TmpRegName(Res2->Reg)));
    ReleaseTmpReg(Res2->Reg);
    free(Res2);
    return Res1;
}



struct ExprRes *  doAdd(struct ExprRes * Res1, struct ExprRes * Res2)  { 
    if(Res1->Type != TYPE_INT || Res2->Type != TYPE_INT){
        TypeError();
    }
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
    if(Res1->Type != TYPE_INT || Res2->Type){
        TypeError();
    }

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

struct ExprRes * doNot(struct ExprRes * Res){
    if(Res->Type != TYPE_BOOL){
        TypeError();
    }
    char * fal = GenLabel();
    char * end = GenLabel();

    AppendSeq(Res->Instrs, GenInstr(NULL, "beq", "$0", TmpRegName(Res->Reg), fal));
    AppendSeq(Res->Instrs, GenInstr(NULL, "li", TmpRegName(Res->Reg), "0", NULL ));
    AppendSeq(Res->Instrs, GenInstr(NULL, "b", end, NULL,NULL));
    AppendSeq(Res->Instrs, GenInstr(fal, NULL, NULL, NULL, NULL));
    AppendSeq(Res->Instrs, GenInstr(NULL, "li", TmpRegName(Res->Reg), "1", NULL ));
    AppendSeq(Res->Instrs, GenInstr(end, NULL,NULL,NULL,NULL));
    
    return Res;

}

struct ExprRes * doNeg(struct ExprRes * Res1){
    if(Res1->Type != TYPE_INT){
        TypeError();
    }

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
    if(Res1->Type != TYPE_INT || Res2->Type != TYPE_INT){
        TypeError();
    }
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
    if(Res1->Type != TYPE_INT || Res2->Type != TYPE_INT){
        TypeError();
    }
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
    if(Res1->Type != TYPE_INT || Res2->Type != TYPE_INT){
        TypeError();
    }


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
    if(Res1->Type != TYPE_INT || Res2->Type != TYPE_INT){
        TypeError();
    }
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
struct InstrSeq * doPrintsp(struct ExprRes * Expr){
    if(Expr->Type != TYPE_INT){
        TypeError();
    }
    struct InstrSeq * code;
    code = Expr->Instrs;
    char * end = GenLabel();
    char * next = GenLabel();
    int i = AvailTmpReg();
    int one = AvailTmpReg();


    AppendSeq(code, GenInstr(NULL, "addi", TmpRegName(one), "$0", "1"));
    AppendSeq(code, GenInstr(NULL, "blt", TmpRegName(Expr->Reg), "$0", end));
    AppendSeq(code, GenInstr(NULL, "li", TmpRegName(i), "0", NULL));
    AppendSeq(code, GenInstr(next, NULL,NULL,NULL,NULL));
   
    AppendSeq(code, GenInstr(NULL, "li", "$v0", "4", NULL));
    AppendSeq(code, GenInstr(NULL, "la", "$a0", "_sp", NULL));
    AppendSeq(code, GenInstr(NULL, "syscall", NULL, NULL,NULL));

    AppendSeq(code, GenInstr(NULL, "addi", TmpRegName(i), TmpRegName(i), "1"));
    AppendSeq(code, GenInstr(NULL, "blt", TmpRegName(i), TmpRegName(Expr->Reg), next));
    
    AppendSeq(code, GenInstr(end, NULL,NULL,NULL,NULL));
    ReleaseTmpReg(i);
    ReleaseTmpReg(one);
    ReleaseTmpReg(Expr->Reg);
    free(Expr);
    free(end);
    free(next);
    
    return code;

}

struct InstrSeq * doPrintSeq(struct ExprRes * Expr, struct InstrSeq * Seq){
    struct InstrSeq * InSeq = doPrint(Expr);

    AppendSeq(InSeq, GenInstr(NULL, "li", "$v0", "4", NULL));
    AppendSeq(InSeq, GenInstr(NULL, "la", "$a0", "_sp", NULL));
    AppendSeq(InSeq, GenInstr(NULL, "syscall", NULL, NULL,NULL));

    AppendSeq(InSeq, Seq);
    return InSeq;

}

struct InstrSeq * doPrint(struct ExprRes * Expr) { 

   struct InstrSeq *code;
   
   code = Expr->Instrs;
   char * end = GenLabel();

   if (Expr->Type == TYPE_BOOL){
       
        char * fal = GenLabel();

        AppendSeq(code,GenInstr(NULL,"li","$v0","4",NULL));
        
        AppendSeq(code, GenInstr(NULL, "beq", "$0", TmpRegName(Expr->Reg), fal));

        AppendSeq(code,GenInstr(NULL,"la","$a0","_tru",NULL));
        AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));
        AppendSeq(code, GenInstr(NULL, "b", end, NULL, NULL));       
 
        AppendSeq(code, GenInstr(fal, NULL, NULL, NULL, NULL));
        AppendSeq(code,GenInstr(NULL,"la","$a0","_fal",NULL));
        AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));    
   
   }  
   else if(Expr->Type == TYPE_INT){

        AppendSeq(code,GenInstr(NULL,"li","$v0","1",NULL));
        AppendSeq(code,GenInstr(NULL,"move","$a0",TmpRegName(Expr->Reg),NULL));
        AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));
   }
   else if (Expr->Type == TYPE_STR){
        AppendSeq(code, GenInstr(NULL, "li", "$v0", "4", NULL));
        AppendSeq(code, GenInstr(NULL, "move", "$a0", TmpRegName(Expr->Reg), NULL));
        AppendSeq(code, GenInstr(NULL, "syscall", NULL, NULL, NULL));
   }    
    AppendSeq(code, GenInstr(end,NULL,NULL,NULL,NULL));   
    ReleaseTmpReg(Expr->Reg);
    free(Expr);

  return code;
}

struct InstrSeq * doPrintln(){
    struct InstrSeq * code;

    code = GenInstr(NULL,"li","$v0","4",NULL);
    AppendSeq(code,GenInstr(NULL,"la","$a0","_nl",NULL));
    AppendSeq(code,GenInstr(NULL,"syscall",NULL,NULL,NULL));
    return code;

}



struct InstrSeq * doAssign(char *name, struct ExprRes * Expr) { 

  struct InstrSeq *code;
  
   struct SymEntry * e = FindName(table,name);
   if (!e) {
		WriteIndicator(GetCurrentColumn());
		WriteMessage("Undeclared variable");
   }
   if( ((struct Vtype *)e->Attributes)->Type != Expr->Type){
       TypeError();
   }
 

  code = Expr->Instrs;
  
  AppendSeq(code,GenInstr(NULL,"sw",TmpRegName(Expr->Reg), name,NULL));

  ReleaseTmpReg(Expr->Reg);
  free(Expr);
  
  return code;
}

extern struct ExprRes * doRelOp(struct ExprRes * Res1, struct ExprRes * Res2, int op){
    printf("res1 = %d, res2 = %d", Res1->Type, Res2->Type);
    if(Res1->Type != TYPE_INT || Res2->Type != TYPE_INT){
        TypeError();
    }

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
    Res1->Type = TYPE_BOOL;
    return Res1;
}


extern struct InstrSeq * doIf(struct ExprRes * bRes, struct InstrSeq * seq) {
	return NULL;
}

void IntDec(char * VarName){
    struct Vtype * vtype = malloc(sizeof(struct Vtype ));
    struct SymEntry * e;
    vtype->Type = TYPE_INT;
    vtype->Size = 1;
    EnterName(table, VarName, &e);
    SetAttr(e,(void*)vtype);
}

void BoolDec(char * VarName){

    struct Vtype * vtype = malloc(sizeof(struct Vtype));
    struct SymEntry *e;
    vtype->Type = TYPE_BOOL;
    vtype->Size = 1;
    EnterName(table, VarName, &e);
    SetAttr(e, (void*)vtype);
}

void TypeError(){
    WriteIndicator(GetCurrentColumn());
    WriteMessage("Conflicting Types");
    exit(1);
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
  struct StrLabels * strlabel;

  code = GenInstr(NULL,".text",NULL,NULL,NULL);
  AppendSeq(code,GenInstr(NULL,".globl","main",NULL,NULL));
  AppendSeq(code, GenInstr("main",NULL,NULL,NULL,NULL));
  AppendSeq(code,Code);
  AppendSeq(code, GenInstr(NULL, "li", "$v0", "10", NULL)); 
  AppendSeq(code, GenInstr(NULL,"syscall",NULL,NULL,NULL));
  AppendSeq(code,GenInstr(NULL,".data",NULL,NULL,NULL));
  AppendSeq(code,GenInstr(NULL,".align","4",NULL,NULL));
  AppendSeq(code,GenInstr("_nl",".asciiz","\"\\n\"",NULL,NULL));
  AppendSeq(code,GenInstr("_tru",".asciiz","\"true\"",NULL,NULL));
  AppendSeq(code,GenInstr("_fal",".asciiz","\"false\"",NULL,NULL));
  AppendSeq(code,GenInstr("_sp", ".asciiz","\" \"",NULL,NULL));

 entry = FirstEntry(table);
 while (entry) {
	AppendSeq(code,GenInstr((char *) GetName(entry),".word","0",NULL,NULL));
        entry = NextEntry(table, entry);
 }
 strlabel = slabels;
 
 while( strlabel ){
     AppendSeq(code, GenInstr(NULL, ".align", "4", NULL, NULL));
     AppendSeq(code, GenInstr(strlabel->SLabel, ".asciiz", strlabel->Str, NULL, NULL));
     strlabel = strlabel->next;
 }

  WriteSeq(code);
  
  return;
}




