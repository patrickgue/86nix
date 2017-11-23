/*
  "stdio.h", header file of "stdio"

  "stdio" - c standard I/O library for 86nix
  Copyright (C) 2017  Patrick Günthard

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef STDIO_H
#define STDIO_H

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




//typedef long unsigned int size_t;

int printf(const char *format, ...);

int fprintf(FILE *stream, const char *format, ...);

int sprintf(char *str, const char *format, ...);

int snprintf(char *str, size_t size, const char *format, ...);

int scanf(const char *format, ...);

int fscanf(FILE *stream, const char *format, ...);

int sscanf(const char *str, const char *format, ...);

int fputc(int c, FILE *stream);

int fputs(const char *s, FILE *stream);

int putc(int c, FILE *stream);

int putchar(int c);

int puts(const char *s);


#endif
