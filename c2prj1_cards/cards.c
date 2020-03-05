#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >= 2 && c.value <=VALUE_ACE);
  assert(c.suit >= SPADES && c.suit <= CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r) {
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND";
  case FULL_HOUSE: return "FULL_HOUSE";
  case FLUSH: return "FLUSH";
  case STRAIGHT: return "STRAIGHT";
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND";
  case TWO_PAIR: return "TWO_PAIR";
  case PAIR: return "PAIR";
  case NOTHING: return "NOTHING";
  default: return"Invalid";
  }
}

char value_letter(card_t c) {
  switch(c.value) {
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9: return '0' + c.value;
  case 10: return '0';
  case VALUE_ACE: return 'A';
  case VALUE_KING: return 'K';
  case VALUE_QUEEN: return 'Q';
  case VALUE_JACK: return 'J';
  default: return EXIT_FAILURE;
  }
}


char suit_letter(card_t c) {
  switch(c.suit) {
  case SPADES: return 's';
  case HEARTS: return 'h';
  case DIAMONDS: return 'd';
  case CLUBS: return 'c';
  default: return EXIT_FAILURE;
  }
}

void print_card(card_t c) {
  printf("%c%c",value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let) {
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9': temp.value = value_let - '0'; break;
  case '0': temp.value = 10; break;
  case 'a':
  case 'A': temp.value = VALUE_ACE; break;
  case 'k':
  case 'K': temp.value = VALUE_KING; break;
  case 'q':
  case 'Q': temp.value = VALUE_QUEEN; break;
  case 'j':
  case 'J': temp.value = VALUE_JACK; break;
  default: assert(0);
  }
  switch(suit_let) {
  case 'S' :
  case 's' : temp.suit = SPADES; break;
  case 'H' :
  case 'h' : temp.suit = HEARTS; break;
  case 'D' :
  case 'd' : temp.suit = DIAMONDS; break;
  case 'C':
  case 'c' : temp.suit = CLUBS; break;
  default: assert(0);
  }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = 2 + c % 13;
  temp.suit = SPADES + c / 13;
  return temp;
}
