%{
	   #include<stdio.h>
	   int nlines=1,nwords=0,nchars=0;
%}

%%
\n 	   {nlines++; }
[^ \n\t]*  {nwords++, nchars=nchars+yyleng;}
. 	   ;
%%
int yywrap(void)  
{
	   return 1;
}
int main(int argc, char*argv[]) 
{
	  yyin=fopen("input1.txt","r");
 	  yylex();
 	  printf("No. of Lines are: %d\nNumber of Chars are: %d\nNumber of Words: %d",nlines,nchars,nwords);
 	  return 0;
} 