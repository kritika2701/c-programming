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

void add_card_to(deck_t * deck, card_t c){
  card_t* c1=malloc(sizeof(*c1));
  c1->value=c.value;
  c1->suit=c.suit;
  deck->cards=realloc(deck->cards,(deck->n_cards+1)*sizeof(*deck->cards));
  deck->cards[deck->n_cards]=c1;
  deck->n_cards++;
}

card_t* add_empty_card(deck_t * deck){
  card_t* c1=malloc(sizeof(*c1));
  c1->value=0;
  c1->suit=0;
  deck->cards=realloc(deck->cards,(deck->n_cards+1)*sizeof(*deck->cards));
  deck->cards[deck->n_cards]=c1;
  deck->n_cards++;
  return c1;
}

deck_t* make_deck_exclude(deck_t * excluded_cards){
  deck_t * ans=malloc(sizeof(*ans));
  ans->cards=NULL;
  ans->n_cards=0;
  for(unsigned i=0;i<52;i++){
    card_t c=card_from_num(i);
    if(!deck_contains(excluded_cards, c))
      add_card_to(ans,c);
  }
  return ans;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands){
  deck_t* deck=malloc(sizeof(*deck));
  deck->n_cards=0;
  deck->cards=NULL;
  for(size_t i=0;i<n_hands;i++){
    for(int x=0;c<hands[i]->n_cards;x++){
      deck->cards=realloc(deck->cards, (deck->n_cards+1)*sizeof(*deck->cards));
      deck->cards[deck->n_cards]=hands[i]->cards[x];
      deck->n_cards++;
    }
  }
  deck_t * deck2=make_deck_exclude(deck);
  free(deck->cards);
  free(deck);
  return deck2;
}

void free_deck(deck_t * deck){
  for(int i=0;i<deck->n_cards;i++){
    free(deck->cards[i]);
  }
  free(deck->cards);
  free(deck);
}
