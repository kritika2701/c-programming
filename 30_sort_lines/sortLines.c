#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
  for(int i=0;i<count;i++)
    printf("%s",data[i]);
}
//to read the data from file
char ** read(FILE *file, int *size){
  char *line=NULL;
  char **out=NULL;
  size_t sz=0;
  while((getline(&line, &sz, file))>=0){
    out=realloc(out, (*size+1)*sizeof(char*));
    out[*size]=line;
    (*size)++;
    line=NULL;
  }
  free(line);
  return out;
}
int main(int argc, char ** argv) {
  if(argc==1){
    int s=0;
    char ** output=read(stdin, &s);
    sortData(output, s);
    for(int i=0;i<s;i++)
      free(output[i]);
    free(output);
  }
  else{
    for(int i=1;i<argc;i++){
      FILE *f=fopen(argv[i],"r");
      if(f==NULL){
	fprintf(stderr, "failed to open a file\n");
	return EXIT_FAILURE;
      }
      int s=0;
      char ** output=read(f,&s);
      if(fclose(f)!=0){
	for(int j=0;j<s;j++)
	  free(output[j]);
	free(output);
	fprintf(stderr, "failed to close a file\n");
	return EXIT_FAILURE;
      }
      sortData(output,s);
      for(int j=0;j<s;j++)
	free(output[j]);
      free(output);
    }
  }
  return EXIT_SUCCESS;
}
