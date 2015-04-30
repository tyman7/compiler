/* Semantics.h
   The action and supporting routines for performing semantics processing.
*/

/* Semantic Records */

#define TYPE_BOOL 0
#define TYPE_INT 1
#define TYPE_STR 2

struct Vtype {
    int Type;
    int Size;
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

struct BExprRes {
  char * Label;
  struct InstrSeq * Instrs;
};


/* Semantics Actions */
extern struct ExprRes * doBoolLit(int bol);
extern struct ExprRes *  doIntLit(char * digits);
extern struct ExprRes *  doRval(char * name);
extern struct InstrSeq *  doAssign(char * name,  struct ExprRes * Res1);
extern struct ExprRes *  doAdd(struct ExprRes * Res1,  struct ExprRes * Res2);
extern struct ExprRes * doBinaryMinus(struct ExprRes * Res1, struct ExprRes * Res2);
extern struct ExprRes *  doMult(struct ExprRes * Res1,  struct ExprRes * Res2);
extern struct InstrSeq *  doPrint(struct ExprRes * Expr);

extern struct InstrSeq * doIf(struct ExprRes *bRes, struct InstrSeq * seq);
extern struct ExprRes * doDivide(struct ExprRes * Res1, struct ExprRes * Res2);
extern struct ExprRes * doMod(struct ExprRes * Res1, struct ExprRes * Res2);
extern struct ExprRes * doNeg(struct ExprRes * Res1);
extern struct ExprRes * doPower(struct ExprRes * Res1, struct ExprRes *Res2);
extern struct ExprRes * doRelOp(struct ExprRes * Res1, struct ExprRes * Res2, int op);
extern struct ExprRes * doNot(struct ExprRes * Res);

extern void IntDec(char* VarName);
extern void BoolDec(char * VarName);
extern void TypeError();
extern void	Finish(struct InstrSeq *Code);
