#include <stdio.h>
#include "Semantics.h"
#include "CodeGen.h"
#include "SymTab.h"
#include "IOMngr.h"

extern int yyparse();

struct SymTab *table;
struct SymTab *ProcSymTab;
struct SymEntry *entry;
struct StrLabels * slabels;
struct SymTab *locTable;

int StackPointer= 0;
int inProc =0;
int global =0;
FILE *aFile;

int main(int argc, char * argv[]) {
	table = CreateSymTab(33);
    ProcSymTab = CreateSymTab(33);
    locTable = NULL;

	//assumes there is a listing file
	slabels = NULL;
    OpenFiles(argv[1], argv[2]);
	if (argc == 4) 
		aFile = fopen(argv[3], "w");
	else
		aFile = stdout;

	yyparse();
}

