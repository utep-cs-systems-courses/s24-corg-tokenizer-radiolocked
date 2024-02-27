#include "tokenizer.h"
#include <stdio.h>
#include <ctype.h>

int space_char(char c){ //return true if c is whitespace
  if(c == ' ' || c == '\t'){
    return 1;
  }
  return 0;
}

int non_space_char(char c){ //return false if c is whitespace
  if(c == ' ' || c == '\t'){
    return 0;
  }
  return 1;
}

char *token_start(char *str){//return pointer to first char of next word
  //iterate through word until it ends
  while(*str == '\0' && *str != ' ' && *str != '\t'){
    str++;
  }

  //skips spaces and tabs
  while (*str == ' ' || *str == '\t'){
    str++; //point to the next thing?? idk how pointers work exactly
  }

  if (*str == '\0'){
    return NULL; //reached end of the string, so no more words
  }else{
    return str; //return pointer to the first character of the next word
  }
}

//return a pointer terminator char following *token
char *token_terminator(char *token){
  //move ot the next char
  while (*token != ' '&& *token != '\0'){
    token++;
  }
  while(*token == ' '){
    token++;
  }

  //now return the terminator
  if(*token == '\0'){
    return TERMINATOR;
  }else{
    return token; //return the pointer to the next token
  }
}

//count the number of tokens in the string
int count_tokens(char *token){
  int count = 0;
  bool word = false;

  //iterate through string
  while(*str != '\0'){
    //if current character is a space or newline
    if(*str == ' ' || *str == '\t' || *str == '\n'){
      word = false;//not inside a word
    }else if(word == false){
      word = true;
      count++;
    }
    str++;
  }
  return count;
}

//returns a freshly allocated new zero-terminated string
//containing <len> chars from <inStr>
//so from what i understood, creat an array
//with each element being a word from the input
char *copy_str(char *inStr, short len){
  char *copy = (char *)malloc((len + 1) * sizeof(char));//allocate memory for new string
  if(copy == NULL){
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  strncpy(copy, inStr, len);//copy 'len'characters from 'inStr' to 'copy'
  copy[len] = '\0';//null-terminate the string
  return copy;
}

char **tokenize(char *str){
  int num_tokens = 0;
  char *token;
  char **tokens = (char **)malloc(sizeof(char *));//allocate memory for array of pointers to tokens
  if(tokens == NULL){
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  token = strok(str, " ");
  while(token != NULL){
    tokens[num_tokens] = copy_str(token, strlent(token));//copy the token in a new string
    num_tokens++;
    tokens = (char **)realloc(tokens, (num_tokens + 1) * sizeof(char *));//resize array
    if(tokens == NULL){
      fprintf(stderr, "Memory allocation failed\n");
      exit(1);
    }
    token = strok(NULL, " ");//get the next token
  }
  tokens[num_tokens] = NULL;//null-terminate the array of tokens
  return tokens;
}

//prints all tokens
void print_tokens(char **tokens){
  if(tokens == NULL){
    fprintf(stderr, "Token array is NULL\n");
    return;
  }

  //iterate through tokens array untill NULL
  for(int i = 0; tokens[i] != NULL; i++){
    printf("tokens[%d] = \"%s\"\n", i, tokens[i]);
  }
}

//free all the tokens
void free_tokens(char **tokens){
  if(tokens == NULL){
    fprintf(stderr, "Token array is NULL\n");
    return;
  }

  //iterate throught tokens array until NULL
  for(int i = 0; tokens[i] != NULL; i++){
    free(tokens[i]);//frees the memory allocated for each token
  }
  free(tokens);//free memory allocated for the array
}
