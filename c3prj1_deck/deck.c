#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_card(card_t c);

void print_hand(deck_t * hand){
  if (hand == NULL || (*hand).n_cards == 0) {return;}
  else {
    card_t ** aofcptr = (*hand).cards;
    for (size_t i = 0; i < (*hand).n_cards; i++) {
      print_card(**aofcptr);
      aofcptr++;
    }
  }
}

int deck_contains(deck_t * d, card_t c) {
  if (d == NULL || (*d).n_cards == 0) {return 0;}
  else {
    card_t ** aofcptr = (*d).cards;
    for (size_t i = 0; i < (*d).n_cards; i++){
      card_t tmp_card = **aofcptr;
      if (tmp_card.value == c.value && tmp_card.suit == c.suit) {
	return 1;
      }
      aofcptr++;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  if (d == NULL) {return;}
  else {
    card_t ** aofcptr = (*d).cards;
    size_t num_cards = (*d).n_cards;
    for (size_t i = 0; i < num_cards; i++) {
      size_t r = random() % (num_cards - i);
      card_t * tmpCptr = aofcptr[num_cards - i - 1];
      aofcptr[num_cards - i -1] = aofcptr[r];
      aofcptr[r] = tmpCptr;
    }
  }
}

void assert_full_deck(deck_t * d) {
  if (d == NULL) {return;}
  if ((*d).n_cards == 0) {return;}
  else{
    deck_t tempDeck;
    for (size_t i = 0; i < (*d).n_cards - 1; i--) {
      tempDeck.n_cards = (*d).n_cards - i - 1;
      tempDeck.cards = (*d).cards + i + 1;
      assert(deck_contains(&tempDeck, *((*d).cards[i]))==0);
    }
  }
}
