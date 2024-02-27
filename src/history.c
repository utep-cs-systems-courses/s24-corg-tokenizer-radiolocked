#include "history.h"
#include <stdio.h>
#include <stdlib.h>

List *init_history(){//initialize list
  List *list = (List*)malloc(sizeof(List));
  if(list == NULL){
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  list->root = NULL;
  return list;
}

//add history to the end of the list
void add_history(List *list, char *str){
  Item *new_item = (Item*)malloc(sizeof(Item));
  if(new_item == NULL){
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  //calculate the length of the input string
  int len = 0;
  while (str[len] != '\0'){
    len++;
  }

  //allocate memory for the string in the new item
  new_item->str = (char*)malloc((len+1) * sizeof(char));
  if(new_item->str == NULL){
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  //copy the string char by char
  for(int i = 0; i <= len; i++){
    new_item->str[i] = str[i];
  }

  new_item->next = NULL;

  if(list->root == NULL){
    new_item->id = 1;
    list->root = new_item;
  }else{
    Item *current = list->root;
    while(current->next != NULL){
      current = current->next;
    }
    new_item->id = current->id + 1;
    current->next = new_item;
  }
}

char *get_history(List *list, int id){
  Item *current = list->root;
  while (current != NULL){
    if(current -> id == id){
      return current -> str;
    }
    current = current -> next;
  }
  return NULL;//return NULL if id isnt found
}

//print entire list
void print_history(List *list){
  Item *current = list->root;
  while (current != NULL){
    printf("ID: %d, String: %s\n", current->id, current->str);
    current = current -> next;
  }
}

//free the history list and the strings
void free_history(List *list){
  Item *current = list -> root;
  while (current != NULL){
    Item *temp = current;
    current = current -> next;
    free(temp->str);
    free(temp);
  }
  free(list);
}
