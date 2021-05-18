#include<stdio.h>
#include<stdlib.h>

int checkInp(FILE *f){
  int c=0;int col=0;
  c=fgetc(f);
  while(!(c==EOF)){
    for(int i=0;i<10;i++){
      if(c=='\n'){
	fprintf(stderr, "character error\n");
	return 0;
      }
      c=fgetc(f);
    }
    if(c!='\n'){
      fprintf(stderr, "wrong rows\n");
      return 0;
    }
    c=fgetc(f);
    col++;
  }
  if(col==10)
    return 1;
  else{
    fprintf(stderr, "wrong columns\n");
    return 0;
  }
}

void rotate(FILE *f){
  int c;char matrix[10][10];
  while((c=fgetc(f))!=EOF){
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
	matrix[i][j]=c;
      }
    }
  }
  char new[10][10];
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      new[i][j]=matrix[j][i];
    }
  }
  for(int i=0;i<10;i++){
    int k=0;
    for(int j=9;j>=0;j--){
      matrix[i][k]=new[i][j];
      k++;
    }
  }
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      printf("%c", matrix[i][j]);
    }
    printf("\n");
  }
}
  
int main(int argc, char ** argv){
  if(argc!=2){
    fprintf(stderr, "wrong number of arguments\n");
    return EXIT_FAILURE;
  }
  FILE * f= fopen(argv[1],"r");
  if(f==NULL){
    perror("could not open file\n");
    return EXIT_FAILURE;
  }
  if(!(checkInp(f)))
    return EXIT_FAILURE;
  rotate(f);
  if(fclose(f)!=0){
    perror("could not close the file\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
