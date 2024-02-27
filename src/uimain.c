//user interface
#include <stdio.h>

int main(){
  char in[50];
  printf("Ready for user input\n");
  printf("$ ");
  fgets(in, sizeof(in), stdin);
  printf("%s\n", in);
}
