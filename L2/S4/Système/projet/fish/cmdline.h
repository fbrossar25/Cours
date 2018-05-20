#ifndef CMDLINE_H
#define CMDLINE_H

#include <stddef.h>

#define MAX_ARGS 16
#define MAX_CMDS 16

struct cmd {
  char *args[MAX_ARGS + 1]; //+1 to have a NULL at the end
  size_t nargs;
};

struct line {
  struct cmd cmds[MAX_CMDS];
  size_t ncmds;
  int redirect_input;
  char *file_input;
  int redirect_output;
  char *file_output;
  int background;
};


void line_init(struct line *li);
int line_parse(struct line *li, const char *str, const size_t len);
void line_reset(struct line *li);

#endif
