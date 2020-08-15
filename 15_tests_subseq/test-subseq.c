#include<stdlib.h>
size_t maxSeq(int *array, size_t n);

int main(){
  int test1[0]={};
   if(maxSeq(test1,0)!=0)
      return EXIT_FAILURE;
  int test2[5]={-1,-2,0,3,6};  
  if(maxSeq(test2,5)!=4)
    return EXIT_FAILURE;
  int test3[7]={1,2,3,4,4,5,6};
  if(maxSeq(test3,7)!=4)
    return EXIT_FAILURE;
  int test4[6]={0,1,2,3,4,6};
  if(maxSeq(test4,6)!=6)
    return EXIT_FAILURE;
  int test5[9]={1,2,3,4,3,4,5,6,7};
  if(maxSeq(test5,9)!=5)
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}
