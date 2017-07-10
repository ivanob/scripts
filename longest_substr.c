#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Find the Longest SharedSubstring between two strings

To compile: >> gcc longest_substr.c -o longest_substr.out
To run: >> ./longest_substr.out "bgalway" "algalalwabsdf"
*/

int min(int a, int b){
  if(a>b) return b;
  else return a;
}

int main(int argc, char *argv[]){
  if(argc!=3) printf("Number of parameters incorrect, you should specify 2 strings");
  else{
    char *s1 = argv[1];
    char *s2 = argv[2];
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *sol = (char *)malloc(min(len1,len2) * sizeof(char));
    for(int i=0; i<len1; i++){
      for(int j=0; j<len2; j++){
        int k1 = i;
        int k2 = j;
        char *match = (char *)malloc(min(len1,len2) * sizeof(char));
        while(k1<len1 && k2<len2 && s1[k1]==s2[k2]){
          match[k1-i] = s1[k1];
          k1++;
          k2++;
        }
        match[k1-i] = '\0';
        if(strlen(match)>strlen(sol)){
          memcpy(sol, match, strlen(match));
        }
        free(match);
      }
    }
    printf("The longest shared substring is: '%s'\n", sol);
  }
  return -1;
}
