%{
  #include <stdio.h>
  #include <stdlib.h>

  #include "symbol.h"
  #include "quad.h"

  void yyerror(char*);
  int yylex();

  struct symbol *tds = NULL;
  struct quad* code = NULL;
%}

%union{
  char* string;
	int value;
	struct{
		struct symbol* result;
    struct quad* code;
	} codegen;
}

%token <string> IDENTIFIER
%token <value> NUMBER
%type  <codegen> expr

%left '+'
%left '*'

%%

axiom:
    expr '\n'
    { 
      printf("Match :-) !\n");
      code = $1.code;
      return 0;
    }
  ;

expr:
    expr '+' expr
    { 
      printf("expr -> expr + expr\n");
      $$.result = symbol_newtemp(&tds);
    }
  | expr '*' expr
    {
      printf("expr -> expr * expr\n");
      $$.result = symbol_newtemp(&tds);
    }
  | '(' expr ')'
    {
      printf("expr -> ( expr )\n");
    }
  | IDENTIFIER
    {
      printf("expr -> IDENTIFIER (%s)\n", $1);
      $$.result = symbol_add(&tds, $1);
    }
  | NUMBER
    {
      printf("expr -> NUMBER (%d)\n", $1);
      symbol* newSymbol = symbol_newtemp(&tds);
      newSymbol->isConstant = true;
      newSymbol->value = $1;
      $$.result = newSymbol;
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
  symbol_print(tds);
  printf("-----------------\nQuad list:\n");
  quad_print(code);

  symbol_destroy(tds);
  quad_destroy(code);

  return EXIT_SUCCESS;
}
