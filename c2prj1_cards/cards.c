#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  int flag=0;
  if((c.value>=2 && c.value<=VALUE_ACE) && (c.suit>=SPADES && c.suit<=CLUBS))
    flag=1;
  assert(flag);

}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
    case 0:return "STRAIGHT_FLUSH";break;
    case 1:return "FOUR_OF_A_KIND";break;
    case 2:return "FULL_HOUSE";break;
    case 3:return "FLUSH";break;
    case 4:return "STRAIGHT";break;
    case 5:return "THREE_OF_A_KIND";break;
    case 6:return "TWO_PAIR";break;
    case 7:return "PAIR";break;
    case 8:return "NOTHING";break;
    default:printf("Invalid input");exit(0);
  }
}

char value_letter(card_t c) {
  char v=' ';
  if (c.value>=2 && c.value<=9){
    v=48+c.value;
  }
  switch(c.value){
    case 10:v= '0';break;
    case 11:v= 'J';break;
    case 12:v= 'Q';break;
    case 13:v= 'K';break;
    case 14:v= 'A';
  }
  if (c.value>14){
    printf("invalid input");
    exit(0);
  }
  return v;
}

char suit_letter(card_t c) {
  switch(c.suit){
    case SPADES:return 's';
    case HEARTS:return 'h';
    case DIAMONDS:return 'd';
    case CLUBS:return 'c';
    default:printf("Invalid input");exit(0); 
  }
}

void print_card(card_t c) {
  char v=value_letter(c);
  char s=suit_letter(c);
  printf("%c%c",v,s);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let){
    case '2':temp.value=2;break;
    case '3':temp.value=3;break;
    case '4':temp.value=4;break;
    case '5':temp.value=5;break;
    case '6':temp.value=6;break;
    case '7':temp.value=7;break;
    case '8':temp.value=8;break;
    case '9':temp.value=9;break;
    case '0':temp.value=10;break;
    case 'A':temp.value=14;break;
    case 'K':temp.value=13;break;
    case 'Q':temp.value=12;break;
    case 'J':temp.value=11;break;
    default:printf("Invalid input");exit(0);
  }
  switch(suit_let){
    case 's':temp.suit=SPADES;break;
    case 'h':temp.suit=HEARTS;break;
    case 'd':temp.suit=DIAMONDS;break;
    case 'c':temp.suit=CLUBS;break;
    default:printf("Invalid input");exit(0);
  }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;char a,b;
  if(c>51){
    printf("invalid input");
    exit(0);
  }
  
  if(c>=0 && c<=12)
    a='s';
  else if(c>=13 && c<=25)
    a='h';
  else if(c>=26 && c<=38)
    a='d';
  else if(c>=39 && c<=51)
    a='c';
  
  if (c%13==0)
    b='0';
  else if(c%13==1)
    b='A';
  else if(c%13>=2 && c%13 <=9)
    b=48+(c%13);
  else if (c%13==10)
    b='J';
  else if(c%13==11)
    b='Q';
  else if (c%13==12)
    b='K';
  temp=card_from_letters(b,a);
  return temp;
}
