%{
  #include <stdio.h>
  #include <stdlib.h>

  #include "symbol.h"
  #include "quad.h"
  #include "quad_list.h"

  void yyerror(char*);
  int yylex();
  void lex_free();

  struct symbol* tds = NULL;
%}

%union{
  char* string;
	int value;
	struct{
		struct symbol* result;
    struct quad* code;
	} codegen;
}

%token ASSIGN WHILE DO DONE IF THEN ELSE ENDIF
%token EQUAL TRUE FALSE OR AND NOT
%token <string> ID
%token <value> NUM
%type <codegen> statement
%type <codegen> expression
%type <codegen> condition

%left OR
%left AND
%left NOT

%%

axiom:
  statement_list '\n'
    {
      printf("Match !!!\n");
      return 0;
    }
    ;

statement_list:
    statement_list statement
    {
    }
  | statement
    {
    }
  ;

statement:
    ID ASSIGN expression
    {
    }
  | WHILE condition DO statement_list DONE
    {
    }
  | IF condition THEN statement_list ENDIF
    {
    }
  | IF condition THEN statement_list ELSE statement_list ENDIF
    {
    }
  ;

condition:
    ID EQUAL NUM
    {
      struct symbol* arg1 = symbol_get_or_create(&tds, $1);
      struct symbol* arg2 = symbol_newtemp(&tds);
      arg2->isConstant = true;
      arg2->value = $3;
      struct symbol* res = symbol_newtemp(&tds);
      $$.code = quad_gen("==",arg1,arg2,res);
    }
  | TRUE
    {
    }
  | FALSE
    {
    }
  | condition OR tag condition
    {
    }
  | condition AND tag condition
    {
    }
  | NOT condition
    {
    }
  | '(' condition ')'
    { 
    }
  ;

expression:
    ID
    {
      $$.result = symbol_add(&tds, $1);
      $$.code = NULL;
    }
  | NUM
    {
      struct symbol* newSymbol = symbol_newtemp(&tds);
      newSymbol->isConstant = true;
      newSymbol->value = $1;
      $$.result = newSymbol;
      $$.code = NULL;
    }
  ;

tag:
    {
    }
  ;


%%

void yyerror (char *s) {
    fprintf(stderr, "[Yacc] error: %s\n", s);
}

int main() {
  printf("Enter your code:\n");
  yyparse();
  printf("-----------------\nSymbol table:\n");
  symbol_print(tds);
  printf("-----------------\nQuad list:\n");

  // Be clean.
  lex_free();
  symbol_destroy(tds);
  return 0;
}
