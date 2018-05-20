
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lib.h"

struct symtable * symtable_new()
{
    struct symtable * t = malloc(sizeof(struct symtable));
    t->capacity = 1024;
    t->symbols = malloc(t->capacity*sizeof(struct symbol));
    t->temporary = 0;
    t->size = 0;
    return t;
}

static void symtable_grow(struct symtable * t) 
{
    t->capacity += 1024;
    t->symbols = realloc(t->symbols,t->capacity*sizeof(struct symbol));
    if(t->symbols == NULL) 
    {
      fprintf(stderr,"Error attempting to grow symbol table (actual size is %d)\n",t->size);
        exit(1);
    }
}

struct symbol * symtable_const(struct symtable * t, long int v) 
{
    unsigned int i;
    for ( i=0 ; i<t->size && t->symbols[i].u.value != v; i++ );
    if(i==t->size)
    {
        if(t->size==t->capacity)
          symtable_grow(t);
        struct symbol *s = &(t->symbols[t->size]);
        s->kind = CONSTANT;
        s->u.value = v;
        ++ (t->size);
        return s;
    }
    else 
    {
        return &(t->symbols[i]);
    }
}

struct symbol * symtable_get(struct symtable * t, const char * id) 
{
    unsigned int i;
    for ( i=0 ; i<t->size && strcmp(t->symbols[i].u.name,id) != 0; i++ );
    if(i<t->size)
      return &(t->symbols[i]);
    return NULL;
}

struct symbol * symtable_put(struct symtable * t, const char * id) 
{
    if(t->size==t->capacity)
      symtable_grow(t);
    struct symbol *s = &(t->symbols[t->size]);
    s->kind = NAME;
    strcpy(s->u.name,id);
    ++ (t->size);
    return s;
}

void symtable_dump(struct symtable * t)
{
    unsigned int i;
    for ( i=0 ; i<t->size; i++ )
    {
      if(t->symbols[i].kind==CONSTANT)
        printf("       %p = %ld\n",&(t->symbols[i]),t->symbols[i].u.value);
      if(t->symbols[i].kind==NAME)
        printf("       %p = %s\n",&(t->symbols[i]),t->symbols[i].u.name);
    }
    printf("       --------\n");
}

void symtable_free(struct symtable * t)
{
    free(t->symbols);
    free(t);
}

struct code * code_new()
{
    struct code * r = malloc(sizeof(struct code));
    r->capacity = 1024;
    r->quads = malloc(r->capacity*sizeof(struct quad));
    r->nextquad = 0;
    return r;
}

static void code_grow(struct code * c)
{
    c->capacity += 1024;
    c->quads = realloc(c->quads,c->capacity*sizeof(struct quad));
    if(c->quads == NULL) 
    {
      fprintf(stderr,"Error attempting to grow quad list (actual size is %d)\n",c->nextquad);
        exit(1);
    }
}

void gencode(struct code * c,
              enum quad_kind k,
              struct symbol * s1,
              struct symbol * s2,
              struct symbol * s3)
{
    if ( c->nextquad == c->capacity )
        code_grow(c);
    struct quad * q = &(c->quads[c->nextquad]);
    q->kind = k;
    q->sym1 = s1;
    q->sym2 = s2;
    q->sym3 = s3;
    ++ (c->nextquad);
}

struct symbol *newtemp(struct symtable * t)
{
  struct symbol * s;
  name_t name;
  sprintf(name,"temp%d",t->temporary);
  s = symtable_put(t,name);
  ++ (t->temporary);
  return s;
}

static void symbol_dump_file(struct symbol * s, FILE *fp)
{
    switch ( s->kind )
    {
        case NAME:
            fprintf(fp, "%s",s->u.name);

            break;
        case CONSTANT:
            fprintf(fp, "%ld",s->u.value);

            break;
        default:
            break;
    }
}

static void symbol_dump(struct symbol * s)
{
    switch ( s->kind )
    {
        case NAME:
            printf("%s",s->u.name);

            break;
        case CONSTANT:
            printf("%ld",s->u.value);

            break;
        default:
            break;
    }
}

static void quad_dump(struct quad * q)
{
    switch ( q->kind )
    {
        case BOP_PLUS:
            symbol_dump(q->sym1);
            printf(" := ");
            symbol_dump(q->sym2);
            printf(" + ");
            symbol_dump(q->sym3);
            break;
        case BOP_MINUS:
            symbol_dump(q->sym1);
            printf(" := ");
            symbol_dump(q->sym2);
            printf(" - ");
            symbol_dump(q->sym3);
            break;
        case BOP_MULT:
            symbol_dump(q->sym1);
            printf(" := ");
            symbol_dump(q->sym2);
            printf(" * ");
            symbol_dump(q->sym3);
            break;
        case UOP_MINUS:
            symbol_dump(q->sym1);
            printf(" := ");
            printf("- ");
            symbol_dump(q->sym2);
            break;
        case CALL_PRINT:
            printf("print ");
            symbol_dump(q->sym1);
            break;
        case COPY:
            symbol_dump(q->sym1);
            printf(" := ");
            symbol_dump(q->sym2);
            break;
        default:
            printf("BUG\n");
            break;
    }
}

void intermediaryToMIPS(struct symtable* t, struct code* c)
{
    //ouverture fichier
    FILE *fp = fopen("MIPS.s", "w");

    //declaration des variables
    fputs("\t.data\n",fp);

    for (unsigned int i=0 ; i<t->size; i++ )
    {

      if(t->symbols[i].kind==NAME)
        {
            fputs(t->symbols[i].u.name, fp);
            fprintf(fp,":");
            fprintf(fp, "\t.word 0\n");
        }
    }

    //traduction des quads
    fputs("\n\t.text\nmain:\n",fp);

    unsigned int i;
    for ( i=0 ; i<c->nextquad ; i++ )
    {
        struct quad * q = &(c->quads[i]);

         switch ( q->kind )
        {
            case BOP_PLUS:
                fprintf(fp, "\t# BOP_PLUS\n");

                if (q->sym2->kind==NAME){
                    fprintf(fp, "\tlw $t0, ");
                } else {
                    fprintf(fp, "\tli $t0, ");
                }
                symbol_dump_file(q->sym2, fp);      
                fprintf(fp, "\n");   //lw $t0, x 
                
                if (q->sym3->kind==NAME){
                    fprintf(fp, "\tlw $t1, ");
                } else {
                    fprintf(fp, "\tli $t1, ");
                }  
                symbol_dump_file(q->sym3, fp); 
                fprintf(fp, "\n");   //lw $t1, x 

                fprintf(fp, "\tadd $t0, $t0, $t1\n");  // add $t0, $t0, $t1

                fprintf(fp, "\tsw $t0, ");
                symbol_dump_file(q->sym1, fp); 
                fprintf(fp, "\n\n");   // sw $t0, res

                break;
            case BOP_MINUS:
                fprintf(fp, "\t# BOP_MINUS\n");

                if (q->sym2->kind==NAME){
                    fprintf(fp, "\tlw $t0, ");
                } else {
                    fprintf(fp, "\tli $t0, ");
                }
                symbol_dump_file(q->sym2, fp); 
                fprintf(fp, "\n");   //lw $t0, x 

                if (q->sym3->kind==NAME){
                    fprintf(fp, "\tlw $t1, ");
                } else {
                    fprintf(fp, "\tli $t1, ");
                }
                symbol_dump_file(q->sym3, fp); 
                fprintf(fp, "\n");   //lw $t1, x 

                fprintf(fp, "\tsub $t0, $t0, $t1\n");  // sub $t0, $t0, $t1

                fprintf(fp, "\tsw $t0, ");
                symbol_dump_file(q->sym1, fp); 
                fprintf(fp, "\n\n");   // sw $t0, res
                break;
            case BOP_MULT:
                fprintf(fp, "\t# BOP_MULT\n");

                if (q->sym2->kind==NAME){
                    fprintf(fp, "\tlw $t0, ");
                } else {
                    fprintf(fp, "\tli $t0, ");
                }
                symbol_dump_file(q->sym2, fp); 
                fprintf(fp, "\n");   //lw $t0, x 

                if (q->sym3->kind==NAME){
                    fprintf(fp, "\tlw $t1, ");
                } else {
                    fprintf(fp, "\tli $t1, ");
                }
                symbol_dump_file(q->sym3, fp); 
                fprintf(fp, "\n");   //lw $t1, x 

                fprintf(fp, "\tmul $t0, $t0, $t1\n");  // mult $t0, $t0, $t1

                fprintf(fp, "\tsw $t0, ");
                symbol_dump_file(q->sym1, fp); 
                fprintf(fp, "\n\n");   // sw $t0, res
                break;
            case UOP_MINUS:
                fprintf(fp, "\t# UOP_MINUS\n");

                if (q->sym2->kind==NAME){
                    fprintf(fp, "\tlw $t0, ");
                } else {
                    fprintf(fp, "\tli $t0, ");
                }
                symbol_dump_file(q->sym2, fp); 
                fprintf(fp, "\n");   // lw $t0, x 

                fprintf(fp, "\tneg $t0, $t0\n");

                fprintf(fp, "\tsw $t0, ");
                symbol_dump_file(q->sym1, fp);
                fprintf(fp, "\n\n"); // sw $t0, res
                break;
            case CALL_PRINT:
                fprintf(fp, "\t# CALL_PRINT\n");

                fprintf(fp, "\tli $v0, 1\n"); //print int

                fprintf(fp, "\tlw $a0, ");
                symbol_dump_file(q->sym1, fp); 
                fprintf(fp, "\n");   // lw $t0, x

                fprintf(fp, "\tsyscall\n\n");
                break;
            case COPY:
                fprintf(fp, "\t# COPY\n");

                if (q->sym2->kind==NAME){
                    fprintf(fp, "\tlw $t0, ");
                } else {
                    fprintf(fp, "\tli $t0, ");
                }
                symbol_dump_file(q->sym2, fp); 
                fprintf(fp, "\n");   // lw $t0, x 

                fprintf(fp, "\tsw $t0, ");
                symbol_dump_file(q->sym1, fp);
                fprintf(fp, "\n\n"); // sw $t0, res
                break;
            default:
                printf("BUG\n");
                break;
        }
    }

    fprintf(fp, "\t# EXIT\n");
    fprintf(fp, "\tli $v0, 10\n");
    fprintf(fp, "\tsyscall\n\n");

    if(fp != NULL)
    {
        fclose(fp);
    }
}

void code_dump(struct code * c)
{
    unsigned int i;
    for ( i=0 ; i<c->nextquad ; i++ )
    {
        printf("%4u | ",i);
        quad_dump(&(c->quads[i]));
        printf("\n");
    }
}

void code_free(struct code * c)
{
    free(c->quads);
    free(c);
}