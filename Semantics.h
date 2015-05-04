/* Semantics.h
   The action and supporting routines for performing semantics processing.
*/

/* Semantic Records */

#define TYPE_BOOL 0
#define TYPE_INT 1
#define TYPE_STR 2
#define TYPE_INTARR 3
#define TYPE_BOOLARR 4

extern struct StrLabels * slabels; 

struct Vtype {
    int Type;
    int Size;
    int Local;
    int StackIndex;
};

struct IdList {
  struct SymEntry * TheEntry;
  struct IdList * Next;
};

struct ExprRes {
  int Type;
  int Reg;
  struct InstrSeq * Instrs;
};

struct ExprResList {
	struct ExprRes *Expr;
	struct ExprResList * Next;
};

struct StrLabels {
    char * Str;
    char * SLabel;
    struct StrLabels * next;
};

struct BExprRes {
  char * Label;
  struct InstrSeq * Instrs;
};


/* Semantics Actions */
extern struct ExprRes * doBoolLit(int bol);
extern struct ExprRes *  doIntLit(char *  digits);
extern struct ExprRes *  doRval(char * name);
extern struct InstrSeq *  doAssign(char * name,  struct ExprRes * Res1);
extern struct ExprRes *  doAdd(struct ExprRes * Res1,  struct ExprRes * Res2);
extern struct ExprRes * doBinaryMinus(struct ExprRes * Res1, struct ExprRes * Res2);
extern struct ExprRes *  doMult(struct ExprRes * Res1,  struct ExprRes * Res2);
extern struct InstrSeq *  doPrint(struct ExprRes * Expr);

extern struct InstrSeq * doIf(struct ExprRes *bRes, struct InstrSeq * seq);
extern struct InstrSeq * doIfElse(struct ExprRes * res, struct InstrSeq *iseq, struct InstrSeq * eseq);
extern struct ExprRes * doDivide(struct ExprRes * Res1, struct ExprRes * Res2);
extern struct ExprRes * doMod(struct ExprRes * Res1, struct ExprRes * Res2);
extern struct ExprRes * doNeg(struct ExprRes * Res1);
extern struct ExprRes * doPower(struct ExprRes * Res1, struct ExprRes *Res2);
extern struct ExprRes * doRelOp(struct ExprRes * Res1, struct ExprRes * Res2, int op);
extern struct ExprRes * doNot(struct ExprRes * Res);
extern struct ExprRes * doOr(struct ExprRes * Res1, struct ExprRes * Res2);
extern struct ExprRes * doAnd(struct ExprRes * Res1, struct ExprRes * Res2);

extern struct InstrSeq * doWhile(struct ExprRes * res, struct InstrSeq *seq);

extern struct InstrSeq * doPrintsp(struct ExprRes *Expr);
extern struct InstrSeq * doPrintln();
extern struct InstrSeq * doPrintSeq(struct ExprRes *Expr, struct InstrSeq * Seq);
extern struct ExprRes * doStrLit(char * str);

extern struct InstrSeq * doArrayAssign(char * name, struct ExprRes * index, struct ExprRes * val);
extern struct InstrSeq * doArrayRead(char * VarName, struct ExprRes * index);
extern struct InstrSeq * doRead(char * VarName);
extern struct ExprRes * doArrayRval(char * name, struct ExprRes * index);

extern void FuncInit(char *name, int type);
extern struct InstrSeq *FuncDec(char *name, struct InstrSeq *code);
extern struct ExprRes *doFuncCall(char *name);
extern struct InstrSeq *doFuncStmt(char *name);
extern struct InstrSeq *doReturn(struct ExprRes *val);

extern void IntArrDec(char * VarName, char * Size);
extern void BoolArrDec(char * VarName, char * Size);
extern void IntDec(char* VarName);
extern void BoolDec(char * VarName);
extern void TypeError();
extern void	Finish(struct InstrSeq *Code);




