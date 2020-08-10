#include "cards.h"
#include<stdio.h>

int main(void) {
  card_t c;int  a;
  printf("\nEnter card value and suit");
  scanf("%u",&c.value);
  scanf("%d",&a);
  c.suit=a;
  assert_card_valid(c);
  print_card(c);
  char v=value_letter(c);
  printf("\n%c",v);
  char s=suit_letter(c);
  printf("%c",s);
  int r;
  printf("\nEnter ranking");
  scanf("%d",&r);
  hand_ranking_t t;
  t=r;
  printf("\n%s",ranking_to_string(t));
  card_t c2;
  printf("\nEnter char for value and suit");
  char a1,b;
  scanf(" %c %c",&a1,&b);
  
  c2=card_from_letters(a1,b);
  print_card(c2);

  for (int i=0;i<52;i++){
    c2=card_from_num(i);
    print_card(c2);
    printf(" ");
  }

  return 0;
}

