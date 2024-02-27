//user interface
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h" //includes header file for tokenizer
#include "history.h" //include header file for history
#defince max_len 100

int main(){
  List *history_list = init_history();
  char input[max_len];
  char choice;
  int sequence_number = 0;
  int found_sequence_number = 0;

  printf("Type 1 for tokenizer, or type 2 for history");
  print("$");
  scanf(" %c", &choice);
  //clear input buffer
  while(getchar() != '\n');
  if(choice == '1'){
    //tokenize a string
    printf("Enter string to tokenize ");
    print{"$");
    fgets(input, max_len, stdin);
    char **tokens = tokenize(input);
    printf("Tokens:\n");
    print_tokens(tokens);
    free_tokens(tokens);
  }else if(choice == '2'){
    //use hisotry
    printf("Enter history sequence number (like !3): ");
    print("$");
    scanf("%d", &sequence_number);

    //clear input buffer
    while(getchar() != '\n');

    //retrieve history
    char *retrieved_str = get_history(history_list, sequence_number);
    if(retrieved_str != NULL){
      printf("Recalled hisotry item: %s\n",  retrieved_str);
    }else{
      printf("History item not found for given sequence number");
    }
  }else{
    printf("Invalid choice\n");
  }

  free_history(history_list);
  return 0;
}
