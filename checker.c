#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int  check_print(char *str, int line){
  printf ("%d: %s\n",line, str);
  return 0;
}

int main(int argc, char **argv){

  FILE *fp;
  char str[128];

  int len, i;
  int line=1;
  int check_flag=0;

  if (argc < 2){
    printf("Argument is lack.\n");
    return 0;
  }

  if ((fp = fopen(argv[1], "r")) == NULL){
    printf("File Open Error.\n");
    return 0;
  }

  setlocale(LC_CTYPE, "jpn");
  
  while (fgets(str, 128, fp) != NULL){
    i = 0;
    
    while (str[i] != '\0'){
      len = mblen (&str[i], MB_CUR_MAX);
      if (len != 1){
	check_flag = 1;
	check_print(str, line);
	break;
      }

      i++;
    }
    line++;
  }

  if (check_flag == 0) printf("No MultiByte Char.\n");

  fclose(fp);
  return 0;
}
