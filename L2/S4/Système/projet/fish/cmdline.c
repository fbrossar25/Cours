#include "cmdline.h"

#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void line_init(struct line *li) {
  assert(li);
  memset(li, 0, sizeof(struct line));
}


static int valid_cmdarg_filename(const char *word){ 
   size_t i, lenf;
   char forbidden[] = "<>&|";// forbidden characters in commands arguments and filenames
   char *ptr;

   lenf = strlen(forbidden);
   for (i = 0; i < lenf ; i++){
      ptr = strchr(word, forbidden[i]);
      if (ptr) {
         return 0;
      }
   }
   return 1;
}

static int line_next_word(const char *str, const size_t len, size_t *index, char **word) {
  assert(str);
  assert(index);
  assert(word);
  assert(len >= 1); 
  assert(str[len -1] == '\n'); 


  size_t i = *index;

  *word = NULL;

  /* eat space */
  while (i < len && isspace(str[i])) {
    i++;
  }

  /* check if it is the end of the line */
  if (i == len) {
    *index = i;
    return 0;
  }

  size_t start = i;
  size_t end = i;
  if (str[i] == '"') {
    start++;
    do {
      i++;
    } while (i < len && str[i] != '"');

    if (i == len) {
      return -1;
    }

#ifdef DEBUG
    printf("last char: %i\n", str[i]);
#endif

    assert(str[i] == '"');

    end = i;
    i++;
  } else {
    while (i < len && !isspace(str[i])) {
      i++;
    }

    end = i;
  }

  *index = i;

  /* copy this word */
  assert(end >= start); 
  *word = calloc(end - start + 1, sizeof(char));
  memcpy(*word, str + start, end - start);
  return 0;
}


static int parse_error(const char *fmt, ...) {
  va_list ap;

  fprintf(stderr, "Error while parsing: ");
  va_start(ap, fmt);
  int ret = vfprintf(stderr, fmt, ap);
  va_end(ap);
  return ret;
}

enum status {
  COMMANDS,
  REDIRECTIONS,
  BACKGROUND
};

int line_parse(struct line *li, const char *str, const size_t len) {
  assert(li);
  assert(str);

  size_t index = 0;
  size_t curr_cmd = 0;
  size_t curr_arg = 0;
  int valret = 0; 

  enum status status = COMMANDS;

  for (;;) {
    /* get the next word */
    char *word;
    int err = line_next_word(str, len, &index, &word);
    if (err) {
      parse_error("Malformed line\n");
      valret = -1; 
      break;
    }

    if (!word) {
      break;
    }

    assert(word);
#ifdef DEBUG
    printf("\tnew word: '%s'\n", word);
#endif

    if (strcmp(word, "|") == 0) {
      free(word);

      if (status != COMMANDS) {
        parse_error("No pipe allowed after a redirection or a '&'\n");
        valret = -1;
        break;
      }

      if (curr_arg == 0){ 
        parse_error("One command is empty\n");
        valret = -1;
        break;
      }

      li->cmds[curr_cmd].nargs = curr_arg;

      curr_arg = 0;
      curr_cmd++;

    } else if (strcmp(word, ">") == 0) {
      free(word);

      if (li->redirect_output) {
        parse_error("Ouput redirection already defined\n");
        valret = -1;
        break;
      }

      if (status == COMMANDS) {
        if (curr_arg == 0) {
          parse_error("No redirection allowed after an empty command\n");
          valret = -1;
          break;
        }
        status = REDIRECTIONS;
      }

      if (status != REDIRECTIONS) {
        parse_error("No redirection allowed after a '&'\n");
        valret = -1;
        break;
      }

      li->redirect_output = 1;

      err = line_next_word(str, len, &index, &word);
      if (err) {
        parse_error("Malformed line\n");
        valret = -1;
        break;
      }

      if (!word) {
        parse_error("Waiting for a filename after a redirection\n");
        valret = -1;
        break;
      }

      if (!valid_cmdarg_filename(word)){
        parse_error("Filename \"%s\" is not valid\n", word);
        free(word);
        valret = -1;
        break;        
      }

      li->file_output = word;

    } else if (strcmp(word, "<") == 0) {
      free(word);

      if (li->redirect_input) {
        parse_error("Input redirection already defined\n");
        valret = -1;
        break;
      }

      if (status == COMMANDS) {
        if (curr_arg == 0) {
          parse_error("No redirection allowed after an empty command\n");
          valret = -1;
          break;
        }
        status = REDIRECTIONS;
      }

      if (status != REDIRECTIONS) {
        parse_error("No redirection allowed after a '&'\n");
        valret = -1;
        break;
      }

      li->redirect_input = 1;

      err = line_next_word(str, len, &index, &word);
      if (err) {
        parse_error("Malformed line\n");
        valret = -1;
        break;
      }

      if (!word) {
        parse_error("Waiting for a filename after a redirection\n");
        valret = -1;
        break;
      }

      if (!valid_cmdarg_filename(word)){
        parse_error("Filename \"%s\" is not valid\n", word);
        free(word);
        valret = -1;
        break;      
      }

      li->file_input = word;

    } else if (strcmp(word, "&") == 0) {
      free(word);

      if (status == BACKGROUND) {
        parse_error("More than one '&' detected\n");
        valret = -1;
        break;
      }

      if (curr_arg == 0){
        parse_error("An empty command before '&' detected\n");
        valret = -1;
        break;
      }

      status = BACKGROUND;

      li->background = 1;
    } else {
      if (status != COMMANDS) {
        free(word);
        parse_error("No more commands allowed after a redirection or a '&'\n");
        valret = -1;
        break;
      }
      if (curr_cmd == MAX_CMDS) {   
        free(word);
        parse_error("Too much commands. Max: %i\n", MAX_CMDS);
        valret = -1;
        break;
      }
      if (curr_arg == MAX_ARGS) {
        free(word);
        parse_error("Too much arguments. Max: %i\n", MAX_ARGS);
        valret = -1;
        break;
      }

      if (!valid_cmdarg_filename(word)){ 
        parse_error("Argument \"%s\" is not valid\n", word);
        free(word);
        valret = -1;
        break;        
      }

      li->cmds[curr_cmd].args[curr_arg] = word;
      curr_arg++;
    }
  }

  if (!valret && curr_cmd > 0 && curr_arg == 0) {
    parse_error("An empty command detected\n");
    valret = -1;
  }

  if (curr_arg != 0) {
    li->cmds[curr_cmd].nargs = curr_arg; 
    curr_cmd++;
  }
  li->ncmds = curr_cmd;
  return valret;
}

void line_reset(struct line *li) {
  assert(li);
  size_t i,j;

  for (i = 0; i < li->ncmds; i++) {
    for (j = 0; j < li->cmds[i].nargs; j++) {
      free(li->cmds[i].args[j]);
    }
  }

  if (li->redirect_input) {
    free(li->file_input);
  }

  if (li->redirect_output) {
    free(li->file_output);
  }

  memset(li, 0, sizeof(struct line));
}
