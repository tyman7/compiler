%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SymTab.h"
#include "IOMngr.h"
#include "Semantics.h"
#include "CodeGen.h"

int yyerror(char* s);
extern int yylex();	/* The next token function. */
extern char *yytext;   /* The matched token text.  */
extern int yyleng;      /* The token text length.   */
extern int yyparse();
void dumpTable();

extern struct SymTab *table;
extern struct SymEntry *entry;

%}


%union {
  long val;
  char * string;
  struct ExprRes * ExprRes;
  struct InstrSeq * InstrSeq;
  struct BExprRes * BExprRes;
}

%type <string> Id
%type <ExprRes> Factor
%type <ExprRes> Term
%type <ExprRes> CTerm
%type <ExprRes> BTerm
%type <ExprRes> ATerm
%type <ExprRes> OTerm
%type <ExprRes> Expr
%type <InstrSeq> PExpr 
%type <InstrSeq> StmtSeq
%type <InstrSeq> Stmt

%type <ExprRes> NegTerm
%type <ExprRes> ExpTerm

%token Ident 		
%token IntLit 	
%token Int
%token Bool
%token Write
%token IF
%token EQ	
%token GTEQ
%token LTEQ
%token NEQ
%token Tru
%token Fal
%token AND
%token OR
%token WriteSp
%token WriteLn
%token STR


%%

Prog			:	Declarations StmtSeq						        {Finish($2); };
Declarations	:	Dec Declarations							        { };
Declarations	:											            { };
Dec		    	:	Int Id ';'                                       	{IntDec($2); };
Dec             :   Bool Id ';'                                         {BoolDec($2); };          
StmtSeq 		:	Stmt StmtSeq								        {$$ = AppendSeq($1, $2); };
StmtSeq	    	:											            {$$ = NULL; };
Stmt			:	Write PExpr ';'								        {$$ = $2; };
Stmt            :   WriteSp Expr ';'                                    {$$ = doPrintsp($2); };
Stmt            :   WriteLn ';'                                         {$$ = doPrintln();};
Stmt			:	Id '=' Expr ';'							        	{$$ = doAssign($1, $3); };
Stmt			:	IF '(' Expr ')' '{' StmtSeq '}'	    		    	{$$ = doIf($3, $6); };
PExpr           :   Expr ',' PExpr                                      {$$ = doPrintSeq($1, $3); };
PExpr           :   Expr                                                {$$ = doPrint($1); };
Expr            :   Expr OR OTerm                                       {$$ = doOr($1, $3); };
Expr            :   OTerm                                               {$$ = $1; };
OTerm           :   OTerm AND ATerm                                     {$$ = doAnd($1, $3); };
OTerm           :   ATerm                                               {$$ = $1; };
ATerm           :   ATerm NEQ BTerm                                     {$$ = doRelOp($1, $3, 3); };
ATerm	    	:	ATerm EQ BTerm							        	{$$ = doRelOp($1, $3, 0); };
ATerm           :   BTerm                                               { $$ = $1; };
BTerm           :   BTerm GTEQ CTerm                                    {$$ = doRelOp($1, $3, 1); };
BTerm           :   BTerm LTEQ CTerm                                    {$$ = doRelOp($1, $3, 2); };
BTerm           :   BTerm NEQ CTerm                                     {$$ = doRelOp($1, $3, 3); };
BTerm           :   BTerm '<' CTerm                                     {$$ = doRelOp($1, $3, 4); };
BTerm           :   BTerm '>' CTerm                                     {$$ = doRelOp($1, $3, 5); };
BTerm           :   CTerm                                               {$$ = $1; };

CTerm			:	CTerm '+' Term							        	{$$ = doAdd($1, $3); };
CTerm           :   CTerm '-' Term                                      {$$ = doBinaryMinus($1, $3); };
CTerm			:	Term								            	{$$ = $1; };
Term	    	:	Term '*' ExpTerm							        { $$ = doMult($1, $3); };
Term            :   Term '/' ExpTerm                                    { $$ = doDivide($1, $3); };
Term            :   Term '%' ExpTerm                                    { $$ = doMod($1, $3); };                
Term            :   ExpTerm                                             { $$ = $1; };
ExpTerm         :   NegTerm '^' ExpTerm                                 { $$ = doPower($1, $3); };
ExpTerm         :   NegTerm                                             { $$ = $1; };
NegTerm         :   '-' Factor                                          { $$ = doNeg($2); };
NegTerm         :   '!' Factor                                          { $$ = doNot($2); };
NegTerm         :   Factor                                              { $$ = $1; };
Factor          :   Tru                                                 { $$ = doBoolLit(1); };
Factor          :   Fal                                                 { $$ = doBoolLit(0); };
Factor          :   STR                                                 { $$ = doStrLit(yytext ); };
Factor		    :	IntLit								            	{ $$ = doIntLit(yytext); };
Factor          :   '(' Expr ')'                                        { $$ = $2; };
Factor		    :	Ident								            	{ $$ = doRval(yytext); };
Id			    : 	Ident								            	{ $$ = strdup(yytext); };
 
%%

int
yyerror(char *s)  {
  WriteIndicator(GetCurrentColumn());
  WriteMessage("Illegal Character in YACC");
  return 1;
}
