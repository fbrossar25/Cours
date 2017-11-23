%{
  #include <stdlib.h>
  #include <string.h>
  #include "y.tab.h"
%}

identifier [a-zA-Z_][0-9a-zA-Z_]*
number     [1-9][0-9]*

%%

{identifier} { return IDENTIFIER; }
{number}     { return NUMBER; }
[()+*]       { return yytext[0]; }
\n           { return yytext[0]; }
.            { printf("[Lex] Unknown character: %s\n", yytext); }

%%
