#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvpair_t* splitPairs(char* str){
  char * value1=strchr(str,'=');
  *value1='\0';
  value1++;
  char * n=strchr(value1,'\n');
  if(n!=NULL)
    *n='\0';
  kvpair_t* pair=malloc((size_t) sizeof(*pair));
  pair->key=str;
  pair->value=value1;
  return pair;
}

kvarray_t * readKVs(const char * fname) {
  FILE * f=fopen(fname,"r");
  if(f==NULL){
    perror("could not open the file\n");
    return NULL;
  }
  char * line=NULL;
  size_t sz=0;
  kvpair_t* curr_pair=NULL;
  kvarray_t* kv_array=malloc((size_t)(sizeof(*kv_array)));
  kv_array->size=0;
  kv_array->arr=NULL;
  while(getline(&line, &sz, f)>=0){
    curr_pair=splitPairs(line);
    kv_array->arr=realloc(kv_array->arr, (kv_array->size+1)*sizeof(*kv_array->arr));
    kv_array->arr[kv_array->size]=curr_pair;
    kv_array->size++;
    line=NULL;
  }
  free(line);
  if((fclose(f))!=0)
    return NULL;
  return kv_array;
}

void freeKVs(kvarray_t * pairs) {
  for(int i=0;i<pairs->size;i++){
    free(pairs->arr[i]->key);
    free(pairs->arr[i]);
  }
  free(pairs->arr);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  kvpair_t* curr_pair;
  for(int i=0;i<pairs->size;i++){
    curr_pair=pairs->arr[i];
    printf("key = '%s' value = '%s'\n",curr_pair->key, curr_pair->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  kvpair_t * curr_pair;
  for(int i=0;i<pairs->size;i++){
    curr_pair=pairs->arr[i];
    if(!strcmp(curr_pair->key,key))
      return curr_pair->value;
  }
  return NULL;
}
