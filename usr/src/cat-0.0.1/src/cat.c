/*
  "cat.c", source file of "cat"

  "cat" - concatenate and print files
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
#include <stdio.h>
#include <unistd.h>


int main(int argc, char* argv[]) {
  FILE* file;
  
  if (argc <= 1) {
    char c;
    while(read(0, &c, 1)) {
      putchar(c);
    }
  }
  else {

    int i;
    for(i = 1; i < argc; i++) {
      file = fopen(argv[i],"r");
      if(file) {
	char buffer;
	while((buffer = getc(file)) != EOF) {
	  putchar(buffer);
	}
	fclose(file);
      }
      else {
	fprintf(stderr,"File \"%s\" not found\n", argv[i]);
      }
    }
  }
  return 0;
}
