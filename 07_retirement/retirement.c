#include<stdio.h>
#include<stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

int month;

double calc(retire_info f, double balance){
  double change;
  for(int i=1;i<=f.months;i++){
    printf("Age %3d month %2d you have $%.2lf\n",month/12,month%12,balance);
    change=((balance*f.rate_of_return/1200)+f.contribution);
    balance+=change;
    month+=1;
  }
  return balance;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired){
  month=startAge;
  double bal;
  bal=calc(working,initial);
  bal=calc(retired,bal);
  
}

int main(){

  int age=327;
  double initial=21345;

  retire_info working;
  working.months=489;
  working.contribution=1000;
  working.rate_of_return=4.5;

  retire_info retired;
  retired.months=384;
  retired.contribution=-4000;
  retired.rate_of_return=1;

  retirement(age, initial, working, retired);

  return EXIT_SUCCESS;
}
