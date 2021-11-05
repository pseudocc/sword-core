#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  TEXT,
  EXEC,
  DIRC
};

typedef struct file_s file_t;
typedef struct shell_args_s shell_args_t;
typedef int (*shell_t)(shell_args_t args);

struct shell_args_s {
  char** strings;
  int length;
};

struct file_s {
  char name[64];
  int id;
  int parent;
  int created;
  int modified;
  int size;
  int type;
  union {
    char* text;
    shell_t cmd;
  } content;
};

static int bash_cmd(shell_args_t args);
static int echo_cmd(shell_args_t args);

static file_t root = {
  .name = "root",
  .id = 0,
  .parent = 0,
  .type = DIRC
};

static file_t usr = {
  .name = "usr",
  .id = 1,
  .parent = 0,
  .type = DIRC
};

static file_t bin = {
  .name = "bin",
  .id = 2,
  .parent = 1,
  .type = DIRC
};

static file_t bash = {
  .name = "bash",
  .id = 3,
  .parent = 2,
  .type = EXEC,
  .content = { .cmd = &bash_cmd }
};

static file_t echo = {
  .name = "echo",
  .id = 4,
  .parent = 2,
  .type = EXEC,
  .content = { .cmd = &echo_cmd }
};

shell_args_t argsep(char* line) {
  shell_args_t args = { .length = 0 };
  char* s = line;
  int i, t, k, n = 0, l = strlen(line);

  if (line[l - 1] == '\n')
    line[l - 1] = '\0';
  
  while (strsep(&s, " ") != NULL)
    n++;
  args.strings = malloc(sizeof(char*) * n);
  
  char c = '\0';
  for (i = 0, n = 0; i < l; i++) {
    switch (line[i]) {
    case '\0':
      break;
    case '"':
      t = i + 1;
      while (t < l && line[t] != '"')
        t++;
      if (t == l)
        break;
      line[i] = line[t] = '\0';
      k = -1;
      for (i = i + 1; i < t; i++)
        if (line[i] == '\0')
          line[i] = ' ';
        else if (k == -1)
          k = i;
      args.strings[n++] = &line[k];
      break;
    default:
      if (c == '\0')
        args.strings[n++] = &line[i];
      break;
    }
    c = line[i];
  }
  
  args.strings = realloc(args.strings, sizeof(char*) * n);
  args.length = n;

  return args;
}


int main(void) {
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  shell_args_t args;

  while ((read = getline(&line, &len, stdin)) != -1) {
    printf("number of characters read: %ld\n", read);
    args = argsep(line);
    for (int i = 0; i < args.length; i++)
      printf("[%d]: %s\n", i, args.strings[i]);
    free(args.strings);
  }

  free(line);
  return 0;
}

static int bash_cmd(shell_args_t args) {
  return 0;
}

static int echo_cmd(shell_args_t args) {
  printf("hello world!\n");
  return 0;
}
