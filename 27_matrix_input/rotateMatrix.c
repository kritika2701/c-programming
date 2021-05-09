#include<stdio.h>
#include<stdlib.h>
void readM(char m[10][10],FILE *f){
  int c=0,i=0,j=0;
  while((c=fgetc(f))!=EOF){
    if(c=='\n'){
      if(j!=10){
	fprintf(stderr, "invalid number of row elements");
	exit(EXIT_FAILURE);
      }
      i++;j=0;
      continue;
    }
    if(i>=10){
      fprintf(stderr, "extra row");
      exit(EXIT_FAILURE);
    }
    m[i][j]=c;
    j++;
  }
  if(i<10){
    fprintf(stderr, "less rows");
    exit(EXIT_FAILURE);
  }
}

void rotate(char m[10][10]){
  int l=0,r=0;
  char tmp;
  for(int i=0;i<10;i++){
    l=0;
    r=9;
    while(l<r){
      tmp=m[i][l];
      m[i][l]=m[i][r];
      m[i][r]=tmp;
      l++;r--;
    }
  }
  int x=0,y=0;
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      x=9-j;
      y=9-i;
      tmp=m[i][j];
      m[i][j]=m[x][y];
      m[x][y]=tmp;
    }
  }
}
void print(char m[10][10]){
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      printf("%c",m[i][j]);
    }
    printf("\n");
  }
}
int main(int argc, char ** argv){
  if(argc!=2){
    fprintf(stderr, "invalid number of inputs");
    return EXIT_FAILURE;
  }
  FILE * f=fopen(argv[1],"r");
  if(f==NULL){
    fprintf(stderr,"could not open file");
    return EXIT_FAILURE;
  }
  
  char m[10][10];
  readM(m,f);
  if((fclose(f))!=0){
    fprintf(stderr, "could not close file");
    return EXIT_FAILURE;
  }
  rotate(m);
  print(m);
  return EXIT_SUCCESS;
}
