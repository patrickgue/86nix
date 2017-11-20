#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>

#define boolean int
#define true 1
#define false 0

#define T_FILE 8
#define T_DIRE 4
#define T_DEVI 2
#define T_LINK 10

void list_dir_simple(char dir[256], boolean all, boolean type) {
  DIR *dp;
  struct dirent *ep;
  struct stat fileStat;

  dp = opendir (dir);
  if (dp != NULL) {
    while (ep = readdir (dp)) {
      if( (strcmp(ep->d_name,".") != 0 && strcmp(ep->d_name,"..") != 0 && ep->d_name[0] != '.') || all == true) {
	if(type == true) {
	  stat(ep->d_name, &fileStat);
	  char t;
	  switch (ep->d_type) {
	  case T_FILE:
	    t = '-';
	    break;
	  case T_DIRE:
	    t = 'd';
	    break;
	  case T_DEVI:
	    t = 'c';
	    break;
	  case T_LINK:
	    t = 'l';
	    break;
	  default:
	    t = '?';
	  }
	  printf("%c", t);
	  printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
	  printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
	  printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
	  printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
	  printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
	  printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
	  printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
	  printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
	  printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
	  struct passwd *pw = getpwuid(fileStat.st_uid);
	  struct group  *gr = getgrgid(fileStat.st_gid);

	  printf(" %10s %10s ", pw->pw_name, gr->gr_name);

	}
	  
	puts (ep->d_name);
      }
    }
    (void) closedir (dp);
  }
  else {
    perror ("Couldn't open the directory");
  }
}


int main(int argc, char* argv[]) {
  int i, flag_count = 0;
  boolean list_flag = false, all_flag = false;
  for(i = 1; i < argc; i++) {
    if(strcmp(argv[i], "-a") == 0) {
      all_flag = true;
      flag_count++;
    }

    if(strcmp(argv[i], "-l") == 0) {
      list_flag = true;
      flag_count++;
    }
  }
  
  if(argc - flag_count > 1) {
    for(i = 1; i < argc; i++) {
      if(strcmp(argv[i], "-a") != 0 && strcmp(argv[i], "-l") != 0) {
	list_dir_simple(argv[i],all_flag,list_flag);
      }
    }
  }
  else {
    list_dir_simple("./", all_flag,list_flag);
  }
  return 0;
}
