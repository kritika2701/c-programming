#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

int main(int argc, char ** argv){
  if(argc<2){
    fprintf(stderr, "not enough arguments\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1],"r");
  if(f == NULL){
    fprintf(stderr, "could not open file\n");
    return EXIT_FAILURE;
  }

  future_cards_t * fc=malloc(sizeof(*fc));
  fc->decks=malloc(sizeof(*fc->decks));
  fc->n_decks=0;

  size_t n_hands=0;
  deck_t ** hands=read_input(f, &n_hands, fc);
  deck_t * deck_remain=build_remaining_deck(hands, n_hands);
  unsigned *win_count=malloc((n_hands+1)*sizeof(*win_count));

  for(size_t i=0; i<n_hands+1; i++)
    win_count[i]=0;

  unsigned num_trials =10000;
  if(argc==3)
    num_trials=atoi(argv[2]);

  size_t round=0;
  while(round<num_trials){
    shuffle(deck_remain);
    future_cards_from_deck(deck_remain, fc);
    deck_t * temp_win=hands[0];
    size_t win_hand=0;
    size_t n_tie=0;
    for(size_t i=1; i<n_hands; i++){
      int result=compare_hands(hands[i], temp_win);
      if(result==1){
	temp_win=hands[i];
	win_hand=i;
	n_tie=0;
      }
      else if(result==0){
	n_tie++;
      }
    }
    if(n_hands-1 == n_tie)
      win_count[n_hands]++;
    else
      win_count[win_hand]++;
    round++;
  }

  for(size_t i=0; i<n_hands; i++){
    printf("Hand %zu won %u / %u times (%.2f%%)\n",i,win_count[i], num_trials, 100.0*win_count[i]/(float)num_trials);
  }
  printf("And there were %u ties\n", win_count[n_hands]);

  free(win_count);
  free_deck(deck_remain);

  for(size_t i=0; i<n_hands; i++)
    free_deck(hands[i]);
  free(hands);

  for(size_t i=0; i<fc->n_decks; i++){
    if(fc->decks[i].n_cards>0){
      free(fc->decks[i].cards);
    }
  }
  free(fc->decks);
  free(fc);

  if(fclose(f)!=0){
    fprintf(stderr, "could not close file\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

  
