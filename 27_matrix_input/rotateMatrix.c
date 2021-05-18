#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>

int checkInp(FILE *f){
  int c=0, col=0;
  c=fgetc(f);
  while(!(c==EOF)){
    for(int i=0;i<10;i++){
      if(c=='\n'){
	fprintf(stderr, "character error");
	return 0;
      }
      c=fgetc(f);
    }
    if(c!='\n'){
      fprintf(stderr, "wrong rows");
      return 0;
    }
    c=fgetc(f);
    col++;
  }
  if(col==10)
    return 1;
  else{
    fprintf(stderr, "wrong columns");
    return 0;
  }
}

void rotate(char matrix[10][10]){
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      char temp=matrix[i][j];
      matrix[i][j]=matrix[j][i];
      matrix[j][i]=temp;
    }
  }
  for(int i=0;i<10;i++){
    for(int j=0;j<5;j++){
      char temp=matrix[i][j];
      matrix[i][j]=matrix[i][9-j];
      matrix[i][9-j]=temp;
    }
  }
  return;
}

int main(int argc, char ** argv){
  if(argc!=2){
    fprintf(stderr, "wrong number of arguments");
    return EXIT_FAILURE;
  }
  FILE * f= fopen(argv[1],"r");
  if(f==NULL){
    perror("could not open file");
    return EXIT_FAILURE;
  }
  if(!(checkInp(f)))
    return EXIT_FAILURE;
  char matrix[10][10];
  int c=0;
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      c=fgetc(f);
      if(c=='\n')
	c=fgetc(f);
      matrix[i][j]=c;
    }
  }
  rotate(matrix);
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      printf("%c", matrix[i][j]);
    }
    printf("\n");
  }
  if(fclose(f)!=0){
    perror("could not close the file");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
