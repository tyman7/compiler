//Tyler Amundson
#include "SymTab.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



unsigned int
hash( const char *str, int size)
{
	unsigned int h = 0;
	while (*str)
		h =  *str++  + (h << 6) + (h << 16) - h;

	h = h % size; 
	return h;
}


struct SymTab*
CreateSymTab(int Size)
{
	struct SymTab *table;
	table = (struct SymTab *) malloc(sizeof(struct SymTab));
	table->Size = Size;
	table->Contents = (struct SymEntry **) malloc(Size * sizeof(struct SymEntry * ));
	int i;
	for(i=0; i < Size; i++){
		table->Contents[i] = NULL;
	}
	return table;
}

struct SymEntry*
FirstEntry(struct SymTab *ATable){
	int size = ATable->Size;
	int i;
	for(i = 0; i < size; i++){
		if(ATable->Contents[i] != NULL) return ATable->Contents[i];
	}
	return NULL;
}

struct SymEntry*
NextEntry(struct SymTab *ATable, struct SymEntry *AnEntry){
    if(AnEntry->Next != NULL){
        return AnEntry->Next;
    }
    unsigned int i  = 1 + hash(GetName(AnEntry), ATable->Size);
    for(; i < ATable->Size; i++){
        if(ATable->Contents[i] != NULL){
            return ATable->Contents[i];
        }
    }
    return NULL;
}


bool EnterName(struct SymTab *ATable, const char *Name, struct SymEntry **AnEntry){
    struct SymEntry *Entry;
    Entry = FindName(ATable, Name);
    int Size = ATable->Size;
    int i;
    if(Entry){
        if(AnEntry){
            *AnEntry = Entry;
        }
        return false;;
    }
    else {
        unsigned int index = hash(Name, ATable->Size);
        struct SymEntry *Entry;
        Entry = malloc(sizeof(struct SymEntry));
        *AnEntry = Entry;
        Entry->Name = malloc(strlen(Name) +1);
        Entry->Attributes = NULL;
        Entry->Next = ATable->Contents[index];
        ATable->Contents[index] = Entry;
        for(i = 0; i < strlen(Name) + 1; i++){
            Entry->Name[i] = Name[i];
        }
        return true;
    }
}




struct SymEntry*
FindName(struct SymTab *ATable, const char * Name)
{
	struct SymEntry *p = NULL;
	struct SymEntry *n;
	unsigned int index = hash(Name, ATable->Size);
	n = ATable->Contents[index];
	while(n != NULL){
		if(strcmp(n->Name, Name) == 0) return n;
		
		n = n->Next;
	}
	return p;
}

void
DestroySymTab(struct SymTab *ATable){
	int i;
	int size = ATable->Size;
	struct SymEntry *e;
	for(i = 0; i < size; i++){
		e = ATable->Contents[i];
		while(e != NULL){
			struct SymEntry *n = e;
			e = e->Next;
			free(n->Name);
			free(n);
		}
	}
	free(ATable->Contents);
	free(ATable);
}

void
SetAttr(struct SymEntry *AnEntry, void *Attributes){
	AnEntry->Attributes = Attributes;
}

void *
GetAttr(struct SymEntry *AnEntry){
	return AnEntry->Attributes;
}

const char*
GetName(struct SymEntry *AnEntry){
	return AnEntry->Name;
}


