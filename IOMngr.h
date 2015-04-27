#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXLINE 1024

bool
OpenFiles(const char * ASourceName, const char * AlistingName);

void
CloseFiles();

char
GetSourceChar();

void 
WriteIndicator(int AColumn);

void
WriteMessage(const char * AMesssage);

int
GetCurrentLine();

int
GetCurrentColumn();

void
getlineCount(const char * ASourceName);
