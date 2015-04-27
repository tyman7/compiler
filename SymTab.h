#ifndef SYMTAB_H
#define SYMTAB_H
#include <stdbool.h>


struct SymTab {
    int Size;
    struct SymEntry **Contents;
};

struct SymEntry {
    char *Name;
    void *Attributes;
    struct SymEntry *Next;
};

struct SymTab * CreateSymTab(int Size);

void DestroySymTab(struct SymTab *ATable);

bool EnterName(struct SymTab *ATable,
          const char *Name,
          struct SymEntry **AnEntry);

struct SymEntry * FindName(struct SymTab *ATable, const char *Name);

void SetAttr(struct SymEntry *AnEntry, void *Attributes);

void  * GetAttr(struct SymEntry *AnEntry);

const char * GetName(struct SymEntry *AnEntry);

struct SymEntry * FirstEntry(struct SymTab *ATable);
    
struct SymEntry * NextEntry(struct SymTab *ATable, struct SymEntry *AnEntry);

#endif /* SYMTAB_H */
