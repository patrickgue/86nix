//#include "stdio.h"

typedef struct _iobuf
{
    char*   _ptr;
    int _cnt;
    char*   _base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char*   _tmpfname;
} FILE;


typedef long unsigned int size_t;

int printf(const char *format, ...) {
  return 0;
}

int fprintf(FILE *stream, const char *format, ...) {
  return 0;
}

int sprintf(char *str, const char *format, ...) {
  return 0;
}

int snprintf(char *str, size_t size, const char *format, ...) {
  return 0;
}

int scanf(const char *format, ...) {
  return 0;
}

int fscanf(FILE *stream, const char *format, ...) {
  return 0;
}

int sscanf(const char *str, const char *format, ...) {
  return 0;
}

int fputc(int c, FILE *stream) {
  return 0;
}

int fputs(const char *s, FILE *stream) {
  return 0;
}

int putc(int c, FILE *stream) {
  return 0;
}

int putchar(int c) {
  return 0;
}

int puts(const char *s) {
  return 0;
}



int main(int argc, char* argv[]) {
  return 0;
}


