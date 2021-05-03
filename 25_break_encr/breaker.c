#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int key(FILE *file){
  int arr[26]={0};
  int c;
  while(c=fgetc(file) !=EOF){
    if(isalpha(c)){
      c=tolower(c);
      arr[c-'a']++;
    }
  }
  int m=0,j=0;
  for(int i=0;i<26;i++){
    if(arr[i]>m){
      m=arr[i];j=i;
    }
  }
  int k=0;
  if(j>=('e'-'a'))
    k=j-('e'-'a');
  else
    k=(26-('e'-'a'))+j;
  return k;
}

int main(int argc, char ** argv){
  if(argc!=2){
    fprintf(stderr, "not enough arguments\n");
    return EXIT_FAILURE;
  }
  FILE * file= fopen(argv[1], "r");
  if(file==NULL){
    perror("Could not open file\n");
    return EXIT_FAILURE;
  }
  int k=key(file);
  printf("%d\n",k);
  if(fclose(file)!=0){
    perror("Failed to close the input file\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
