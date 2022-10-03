#include <stdlib.h>
#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

/*typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;
*/

/* Initialize the linked list to keep the history. */
List* init_history()
{

  List *history = malloc(sizeof(List)); //makes a new linked list & allocates memory

  history->root = NULL; //root initialized to NULL
  return history;
}


/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
//Adds new strings to the end of the LL
void add_history(List *list, char *str)
{

  Item *item = malloc(sizeof(Item));

  //ID's the Item
  int count = 0;
  if(list -> root == NULL){ //If the root is NULL we set new item as root

    list -> root = item;
  }
  else{ // else find the next free space in the list, by using a while loop
    struct s_Item *temp = list -> root;
    count++;
    while(temp -> next != NULL){
      count++;
      temp = temp -> next;
    }
    temp -> next = item; // once the end is found, set the item to the end
  }
  item -> id = count;
  int len = 0;
  while(*str != '\0'){
    len++;
    str++;
  }

  str = str - len;

  item -> str = copy_str(str, len); //copy the str into the item str

  item -> next = NULL; //set the next space to NULL
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){

  struct s_Item *temp = list -> root; //this will help iterate through list
  while(temp != NULL && id !=0){ // move through list an id amount
    temp = temp -> next;
    id--;
  }
  if(temp ==NULL){ //if item is null and id is not 0 then the Item doesn't exist
    printf("This ID is not in history\n");
  }
  else{ //return the string of that item
    return temp -> str;
  }
}


/*Print the entire contents of the list. */
void print_history(List *list){

  struct s_Item *temp = list -> root;
  while(temp != NULL){
    printf("[%i] %s\n", temp -> id, temp -> str); //print the entire history
    temp = temp -> next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{

  struct s_Item *temp = list -> root;
  struct s_Item *temp_2;
  while(temp != NULL){
    temp_2 = temp -> next;
    free(temp -> str);
    free(temp);
    temp = temp_2;
  }
  free(list);
  list -> root = NULL;
}
