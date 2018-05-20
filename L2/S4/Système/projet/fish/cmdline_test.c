#include "cmdline.h"

#include <string.h>
#include <stdio.h>

static struct line li;
static int n = 0;

#define OK 0
#define KO 1

static void try(const char *line, int expected) {
  n++;
  printf("TEST #%i\n", n);

  int err = line_parse(&li, line, strlen(line));

  if ((!!err) != (!!expected)) {
    printf("UNEXPECTED RETURN WITH: %s\n", line);
  } else {
    printf("TEST OK!\n");
  }
  line_reset(&li);
}


int main() {
  line_init(&li);

  // things working
  try("bar\n", OK);
  try("bar baz\n", OK);
  try("bar 123\n", OK);
  try("bar > baz\n", OK);
  try("bar < baz\n", OK);
  try("bar > baz < qux\n", OK);
  try("bar &\n", OK);
  try("bar > baz &\n", OK);
  try("bar < baz &\n", OK);
  try("bar > baz < qux &\n", OK);
  try("bar | baz\n", OK);
  try("bar | baz &\n", OK);
  try("bar | baz > qux\n", OK);
  try("bar | baz < qux\n", OK);
  try("bar | baz | qux\n", OK);

  try("bar \"baz\"\n", OK);
  try("bar \"baz qux\"\n", OK);
  try("     \n", OK);
  try("\n", OK);

  // things not working
  try("bar \"bar\n", KO);	

  try("bar & | baz\n", KO);
  try("bar > qux | baz\n", KO);
  try("bar < qux | baz\n", KO);

  try("bar >\n", KO);		
  try("bar > qux > baz\n", KO);
  try("bar | > qux\n", KO);
  try("bar & > qux\n", KO);

  try("bar <\n", KO);		
  try("bar < qux < baz\n", KO);
  try("bar | < qux\n", KO);
  try("bar & < qux\n", KO);

  try("bar & &\n", KO);		

  try("bar & baz\n", KO);	
  try("bar > qux baz\n", KO);
  try("bar < qux baz\n", KO);
  try("bar |\n", KO);

  try("bar | | barz\n", KO);	
  try("bar > >\n", KO);
  try("< qux \n", KO);
  try("> qux \n", KO);
  try("bar | &\n", KO);
  try("& \n", KO);

 
  return 0;
}
