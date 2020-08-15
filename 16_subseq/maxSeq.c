#include<stdlib.h>

size_t maxSeq(int * array, size_t n){
  if(n<=0)
    return 0;
  if(n==1)
    return 1;
  size_t length=1,maxLength=1;
  for(int i=1;i<n;i++){
    if(array[i]>array[i-1])
      length++;
    else{
      if(length>maxLength)
	maxLength=length;
      length=1;
    }
  }
  if (length>maxLength)
    return length;
  else
    return maxLength;
}
