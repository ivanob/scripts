/**
Given a character array containing only letters and spaces, write a function to transpose the
"words" in the array. For example, ['H', 'i', ' ', 'W', 'o', 'r', 'l', 'd'] will
become ['W', 'o', 'r', 'l', 'd', ' ', 'H', 'i']. A "word" is defined as contiguous
letters bounded by the ends of the array, or 1 or more spaces. Your function should
return a character array or void, and the result should have the same length as the
input. Consider edge cases, such as all letters, leading and trailing spaces, etc. 

short-hand examples:
[Hi World]       ->  [World Hi]
[one two three ] ->  [ three two one]
[   ]            ->  [   ]
[ one  two three] -> [three two  one ]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
To compile: >> gcc inverse_sentence.c -o inverse_sentence.out
To run: >> ./inverse_sentence.out "a b cccccccc"
*/
int main(int argc, char *argv[]){
  if(argc != 2) printf("You should specify the sentence to inverse as a string");
  else {
    int i, j=0, k;
    char *s = argv[1];
    int len = strlen(s);
    char *inv = (char *)malloc(len * sizeof(char));
    //Algorithm
    for(i=len-1; i>=0; i--){
      if(s[i] == ' ' || i==0){ //Found new word
        k=i;
        if(s[i] == ' ') k++;
        while(k<len && s[k]!=' '){ //Copy the word
          inv[j] = s[k];
          j++;
          k++;
        }
        if(j<len){
          inv[j] = ' ';
          j++;
        }
      }
    }
    inv[len] = '\0';
    printf("Sentence: %s\n", s);
    printf("Inversed: %s\n", inv);
  }
}
