#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define SIZE 100

void goto_tokens(char *input, List *list)
{
  
  printf("Please provide a sentence you would like to tokenize. \n",stdout);
  putchar('$');
  fgets(input,1000,stdin);
  add_history(list, input);
  char **tokens = tokenize(input);
  print_tokens(tokens);
  free_tokens(tokens);
}

void goto_history(char *input, List *list)
{

  print_history(list);
  printf("Please provide a number from thh history above\n");
  putchar('$');
  fgets(input,100,stdin);
  char *str = get_history(list, atoi(input)); //converts a str to an int value
  printf("string at %i: %s\n", atoi(input), str);
  char **tokens = tokenize(str);
  print_tokens(tokens);
  free_tokens(tokens);
}
int main() 
{
  char input[1000]; //set a limit on how big the input can be

  List *list = init_history();
  
  puts("Welcome!");

  while (1) { // Infinite while loop

    printf("Please enter 't' to Tokenize,'h' for history and 'q' to Quit.\n",stdout);
    putchar('$');
    fgets(input,1000,stdin);

    if(*input =='t'){
      goto_tokens(input, list);
    }
    else if (*input == 'h'){
      goto_history(input, list);
    }
    else if(*input =='q'){
      free_history(list);
      printf("Thank You, Goodbye!");
      exit(1);
    }
    else{
      printf("Invalid command please try again:)\n",input);
    }
  }
}
