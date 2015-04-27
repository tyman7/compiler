// Tyler Amundson
#include "IOMngr.h"
#include <string.h>

FILE *as;
FILE *al;
int linecount;
char current[MAXLINE];
int curCol;
int totalLine;

bool
OpenFiles(const char *ASourceName, const char *AListingName){
	getlineCount(ASourceName);
    as = fopen(ASourceName, "r");
	curCol = 0;
    linecount = 0;
	if(AListingName == NULL){
		al = NULL;
	}
	else {
		al = fopen(AListingName, "w+");
		if(al == NULL){
			return false;
		}
	}
	if(as == NULL ){
		return false;
	}
	else{
		return true;
	}
}

void
CloseFiles(){
	fclose(as);
	if(al != NULL){
		fclose(al);
	}
}


void
getlineCount(const char* fname){
    FILE* myfile = fopen(fname, "r");
    int ch, numlines = 0;

    do{
        ch = fgetc(myfile);
        if(ch == '\n')
            numlines++;
    }while(ch != EOF);

    if(ch!= '\n' && numlines != 0)
        numlines++;
    fclose(myfile);
    totalLine = numlines;
}


char
GetSourceChar(){
    char c;
    int length = strlen(current);
    if(curCol == length || length == 0){
        char next;
        int i = 0;
        curCol = 0;
        linecount ++;
        if(feof(as)){
            return EOF;
        }
        memset(&current[0],0,sizeof(current));
        next = fgetc(as);
        while(next != EOF && next != '\n'){
            current[i++] = next;
            next = fgetc(as);
        }
        current[i] = '\n';
        if(al != NULL && linecount < totalLine ){
            fprintf(al, "%d. %s", linecount, current);
        }
    }
    c = current[curCol++];
    return c;
}


void WriteIndicator(int Ac){
    int Acolumn = Ac;	
    if(al == NULL){
	/*	printf("%d. %s", linecount, current);
		printf(" ");
		while(Acolumn > 0){
			printf(" ");
			Acolumn = Acolumn -1;
		}
		printf("^\n");
        */
	}
	else {
		fprintf(al, " ");
		while(Acolumn > 0){
			fprintf(al, " ");
			Acolumn = Acolumn - 1;
		}
		fprintf(al, "^\n");
	}
}

void WriteMessage(const char * Amessage){
    if(al == NULL) {
        printf("%s\n", Amessage);
    }
    else {
        fprintf(al, "%s\n", Amessage);
    }
}
int GetCurrentLine(){
    return linecount;
}

int GetCurrentColumn(){
    return curCol;
}



