#include<stdlib.h>
#include<stdio.h>
unsigned power(unsigned x, unsigned y);

void run_check(unsigned x, unsigned y, unsigned expected_ans){
  if(power(x,y) != expected_ans){
    printf("\nBroken implementation");
    exit(EXIT_FAILURE);
  }
}

int main(){
  run_check(0,0,1);
  run_check(32,3,32768);
  run_check(543543565,1,543543565);
  return EXIT_SUCCESS;
}
