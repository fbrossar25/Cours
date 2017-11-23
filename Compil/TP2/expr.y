%{
  #include <stdio.h>
  #include <stdlib.h>

  void yyerror(char*);
  int yylex();
%}

%token IDENTIFIER
%token NUMBER

%left '+'
%left '*'

%%

axiom:
    expression '\n'
    { 
      printf("Match :-) !\n");
      return 0;
    }
  ;

expression:
    expression '+' expression
    { 
      printf("expression -> expression + expression\n");
    }
  | expression '*' expression
    {
      printf("expression -> expression * expression\n");
    }
  | '(' expression ')'
    {
      printf("expression -> ( expression )\n");
    }
  | IDENTIFIER
    {
      printf("expression -> IDENTIFIER (%s)\n", "???");
    }
  | NUMBER
    {
      printf("expression -> NUMBER (%d)\n", 42);
    }
  ;

%%

void yyerror (char *s) {
    fprintf(stderr, "[Yacc] error: %s\n", s);
}

int main() {
  printf("Enter an arithmetic expression:\n");
  yyparse();
  printf("-----------------\nSymbol table:\n");
  printf("-----------------\nQuad list:\n");

  return 0;
}
