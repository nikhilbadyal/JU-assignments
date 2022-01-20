%{
     #include<stdio.h>
#include<stdlib.h>
%}

%%
"Morning, I am "[a-zA-Z]+ {
                     printf("Good Morning, %s. How are you?",yytext+13);
         exit(0);
      }

"Afternoon, I am "[a-zA-Z]+ {
                     printf("Good Afernoon, %s. How are you?",yytext+15);
         exit(0);
      }
\n     ;
.*     {printf("not accepted");exit(1); ;
%%
int yywrap(void)  
{
     return 1;
}
int main(int argc, char*argv[]) 
{
    yylex();
  
     return 0;
}