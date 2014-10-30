#include<stdio.h>
#include<string.h>

int isAnagram(const char *s1, const char *s2){
  int len1 = strlen(s1);
  int len2 = strlen(s2); 
  if(len1 != len2)
    return 0;
  for(int i = 0; i <= len1; i++){
    if(strchr(s2, s1[i]) == NULL) 
       return 0;
    else if(strchr(s1, s2[i]) == NULL)
      return 0;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  char *string1 = "annn";
  char *string2 = "anan";
  if(isAnagram(string1, string2)){
    puts("it's an Anagram!");
    puts("Anna is awsome at coding");
  }
  else 
    puts("it's not an Anagram");
  return 0;
}
