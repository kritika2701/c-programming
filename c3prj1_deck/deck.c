#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  card_t ** arr=hand->cards;
  size_t n=hand->n_cards;
  for(int i=0;i<n;i++){
    print_card(*arr[i]);
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  card_t ** hand=d->cards;int flag=0;
  for(size_t i=0;i<(d->n_cards);i++){
    card_t card=*hand[i];
    if(card.value==c.value && card.suit==c.suit){
      flag=1;break;
    }
  }
  return flag;
}

void shuffle(deck_t * d){
  card_t ** hand=d->cards;
  size_t n=d->n_cards;
  card_t * tmp;
  for(int i=n-1;i>0;i--){
    int j=rand()%(i+1);
    tmp=hand[i];
    hand[i]=hand[j];
    hand[j]=tmp;
  }
}

void assert_full_deck(deck_t * d) {
  card_t ** hand=d->cards;
  size_t n=d->n_cards;
  for(int i=0;i<n-1;i++){
    int count=1;
    card_t current=*hand[i];
    for(int j=i+1;j<n;j++){
      card_t check=*hand[j];
      if(current.value==check.value && current.suit==check.suit)
        count++;
    }
    assert(count==1);
  }
}
