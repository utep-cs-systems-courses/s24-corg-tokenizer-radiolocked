#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

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
  if(str == NULL){
    return NULL;//hande NULL pointer
  }

  //iterate throught leading spaces
  while(*str != '\0' && (*str == ' ' || *str == '\t')){
    str++;
  }

  //return pointer to first character
  return str;
}

//return a pointer terminator char following *token
char *token_terminator(char *token){
  if(token == NULL){
    return NULL;//handle null pointer
  }
  
  //move ot the next char
  while (*token != ' '&& *token != '\0'){
    token++;
  }
  
  //now return the terminator
  if(*token == '\0'){
    return NULL;//return NULL to indicage end of string
  }else{
    return token;//pointer to next token
  }
}

//count the number of tokens in the string
int count_tokens(char *str){
  int count = 0;
  int  in_word = 0;

  //iterate through string
  while(*str != '\0'){
    //if current character is a space or newline
    if(*str == ' ' || *str == '\t' || *str == '\n'){
      in_word = 0;//not inside a word
    }else if(in_word == 0){
      in_word = 1;
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
  //copy characters
  for(int i = 0; i < len; i++){
    copy[i] = inStr[i];
  }
  copy[len] = '\0';//null-terminate the string
  return copy;
}

char **tokenize(char *str){
  int num_tokens = count_tokens(str);//count number of tokens
  //allocate memory for pointers array
  char **tokens = (char **)malloc((num_tokens + 1) * sizeof(char *));

  if(tokens == NULL){
    fprintf(stderr, "Memmory allocation failed\n");
    exit(1);
  }

  int token_index = 0;
  char *token_begin = token_start(str);

  while(token_begin != NULL){//correct loop condition
    char *token_end = token_terminator(token_begin);
    int token_length = token_end - token_begin;

    tokens[token_index] = copy_str(token_begin, token_length);
    token_index++;

    token_begin = token_start(token_end);//move to start of next string
  }
  tokens[num_tokens] = NULL;//mark the end of the token array
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
