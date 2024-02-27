//user interface
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h" //includes header file for tokenizer

int main(){
  char in[50];
  printf("Ready for user input\n");
  printf("$ ");
  fgets(in, sizeof(in), stdin);

  //Tokenize the input string
  char **tokens = tokenize(in);

  //print tokens
  printf("Tokens:\n");
  for(int i = 0; tokens[i] != NULL; i++){
    printf("%s\n", tokens[i]);
  }
  //free memory
  free_tokens(tokens);
  return 0;
}
