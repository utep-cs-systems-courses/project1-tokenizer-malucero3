#include <stdio.h>
#include <stdlib.h>
/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  //checks if a char is a space 
  if(c == ' '|| c=='\t'){
    return 1;
  }
  return 0;
}
    
/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  //checks to see if char is a non space
  if(c != ' '|| c != '\t'|| c !='\0'){
    return 1;
  }
  return 0;
}
  

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  // moves pointer to the 1st non space character after a space
  while (space_char(*str) && *str != '\0'){
    str++;
  }
  return str;
}
/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  word = word_start(word);
 // moves pointer to 1st space char after a non space char
  while(non_space_char(*word) && *word != '\0'){
    word++;
  }
  return word;
}
/* Counts the number of words in the string argument. */
 int count_words(char *str)
 {

   int counter = 0;

   str = word_start(str);

   while(*str != '\0')
     {
       str = word_start(str);
       if(*str != '\0')
	 counter++;
     //adds to counter until '\0' is reached
       str = word_terminator(str);
   }
   return counter;
 }
/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  
  char *copyStr = (char*)malloc(sizeof(char)*(len+1));

  int i = 0;
  while(i <len)
    { //loops less that the length (save room for '\0')
      copyStr[i] = inStr[i]; //inserts whats in the str to the current index (i) into the new copyStr
      i++;
  }
  copyStr[len] = '\0'; // marks end of string with 0 terminator
  return copyStr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens frxom zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  int length = count_words(str);
  char **char_arr;
  char_arr = (char**)malloc((length+1)* sizeof(char *)); //char arr allocates memory + '/0'
  int i = 0;
  while(i<length){ //loop copys each word from string into the array leaving space for '0'
    str = word_start(str); //stores 1st char of string
    int strLen = word_terminator(str) - str; //stores len of word in str
    char_arr[i] = copy_str(str,strLen);
    str = word_terminator(str); //sets str to nxt blank
    i++;
  }
  char_arr[i] = NULL;
  return char_arr;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  int i;
  for(i=0; tokens[i] != NULL; i++)
    {
      printf("%s\n",tokens[i]);
    }
}

/* Frees all tokens and the vector containing themx. */
  void free_tokens(char **tokens)
  {
    int i;
    for(i=0; tokens[i] != NULL; i++)
      {
	free(tokens[i]); //frees memory
      }
    free(tokens[i]);
    free(tokens);
  }
