%{
#include "SymTab.h"
#include "IOMngr.h"
#include "y.tab.h"

#define YY_INPUT(buf,result,max_size) \
	{ int c = GetSourceChar(); \
          result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
        }

%}


letter [A-Za-z]
digit [0-9]

%%
call                            {return Call;}
return                          {return Return;}
while                           {return While;}
read                            {return Read;}
\"(\\.|[^"\\])*\"               {return STR;}
printsp                         {return WriteSp;}
println                         {return WriteLn;}
def                             {return Def;}
true                            {return Tru;}
false                           {return Fal;}
if				            	{return IF;}
else                            {return Else;}
int			    	           	{return Int;}
bool                            {return Bool;}
print				        	{return Write;}
{letter}({letter}|{digit})*	    {return Ident;}
{digit}{digit}*		            {return IntLit;}
\=\=					        {return EQ;}
\>\=                            {return GTEQ;}
\<\=                            {return LTEQ;}
\!\=                            {return NEQ;}
\&\&                            {return AND;}
\|\|                            {return OR;}
\[                              {return '[';}
\]                              {return ']';}
\<                              {return '<';}
\>                              {return '>';}
\=		               			{return '=';}
\-                              {return '-';}
\+			               		{return '+';}
\*		            			{return '*';}
\;			            		{return ';';}
\{			            		{return '{';}
\}			            		{return '}';}
\(			            		{return '(';}
\)			            		{return ')';}
\/                              {return '/';}
\%                              {return '%';}
\^                              {return '^';}
\!                              {return '!';}
\,                              {return ',';}
[ ]			                	{}
\t			                   	{}
\r			                	{}
\n			                	{}

.				{WriteIndicator(GetCurrentColumn());
				   WriteMessage("Illegal Character in lex");}

%%

int	
yywrap () {
    return 1;
}
			
	
