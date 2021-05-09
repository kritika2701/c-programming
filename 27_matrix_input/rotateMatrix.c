#include<stdio.h>
#include<stdlib.h>

int verify(FILE *f){
  int c=0;int col=0;
  c=fgetc(f);
  while(!(c==EOF)){
    for(int i=0;i<10;i++){
      if(c=='\n'){
	fprintf(stderr, "char error\n");
	return 0;
      }
      c=fgetc(f);
    }
    if(c!='\n'){
      fprintf(stderr, "row err\n");
      return 0;
    }
    c=fgetc(f);
    col++;
  }
  if(col==10)
    return 1;
  else{
    fprintf(stderr, "column err\n");
    return 0;
  }
}

void rotate(char m[10][10]){
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      char temp=m[i][j];
      m[i][j]=m[j][i];
      m[j][i]=temp;
    }
  }
  for(int i=0;i<10;i++){
    for(int j=0;j<5;j++){
      char temp=m[i][j];
      m[i][j]=m[i][9-j];
      m[i][9-j]=temp;
    }
  }
  return ;
}

int main(int argc, char ** argv){
  if(argc!=2){
    fprintf(stderr,"invalid number of inputs\n");
    return EXIT_FAILURE;
  }
  FILE * f=fopen(argv[1],"r");
  if(f==NULL){
    fprintf(stderr,"could not open file\n");
    return EXIT_FAILURE;
  }
  if(!verify(f))
    return EXIT_FAILURE;
  char m[10][10];
  int c=0;
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      c=fgetc(f);
      if(c=='\n')
	c=fgetc(f);
      m[i][j]=c;
    }
  }
  rotate(m);
  for(int x=0;x<10;x++){
    for(int y=0;y<10;y++){
      printf("%c",m[x][y]);
    }
    printf("\n");
  }
  if(fclose(f)!=0){
    fprintf(stderr,"failed to close the input file\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
