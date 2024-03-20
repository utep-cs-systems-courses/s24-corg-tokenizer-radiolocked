//user interface
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h" //includes header file for tokenizer
#include "history.h" //include header file for history
#define max_len 100

int main(){
  List *history_list = init_history();
  char input[max_len];
  char choice;
  int sequence_number = 0;

  do{
    printf("Type 1 for tokenizer, or type 2 for history. Type q to quit.\n");
    printf("$");
    scanf(" %c", &choice);
    getchar();//clear input buffer

    if(choice == '1'){
      //tokenize a string
      printf("Enter string to tokenize\n");
      printf("$ ");
      fgets(input, max_len, stdin);

      //check for empty input
      if(input[0] == '\n'){
	printf("Empty input Please enter a string.\n");
        continue;
      }

      //tokenization
      char **tokens = tokenize(input);
      if(tokens == NULL){
	printf("Tokenization failed. Exiting.\n");
	free_history(history_list);
	return 1;
      }

      //print tokens
      printf("Tokens:\n");
      print_tokens(tokens);
      //free memory for tokens
      free_tokens(tokens);

      //add input to history list
      add_history(history_list, input);
    }else if(choice == '2'){
      //use history
      print_history(history_list);
      printf("Enter history sequence number (like !3): \n");
      printf("$");
      scanf("%d", &sequence_number);

      //retrieve history
      char *retrieved_str = get_history(history_list, sequence_number);
      if(retrieved_str != NULL){
	printf("Recalled hisotry item: %s\n",  retrieved_str);
      }else{
	printf("History item not found for given sequence number\n");
      }
    }else if(choice != 'q'){
      printf("Invalid choice\n");
    }
  }while(choice != 'q');

  free_history(history_list);
  return 0;
}
