#include <stdio.h>

typedef struct card {
  int number;
  char character;
} card_t;

void swap(card_t *card1, card_t *card2) {
  card_t* temp = card2;
  card1 = card2;
  card2 = temp;
}

void trace(card_t deck[], int length) {
  for(int i = 0; i < length; i++) {
    printf("%c%d ", deck[i].character, deck[i].number);
    
  }
  printf("\n");
}

void stableSort(card_t deck[], int length) {
}

#define DECK_SIZE 54
int main(void) {
  
  card_t deck[DECK_SIZE];

  for(int i = 0; i < DECK_SIZE -2; i++) {
    deck[i].number = (i % 13) + 1;
    switch(i / 13) {
    case 0:
      deck[i].character = 'H';
      break;
    case 1:
      deck[i].character = 'D';
      break;
    case 2:
      deck[i].character = 'S';
      break;
    case 3:
      deck[i].character = 'C';
      break;
    }
  }

  deck[52].number = 0;
  deck[52].character = 'J';
  deck[53].number = 0;
  deck[53].character = 'J';
  
  trace(deck, DECK_SIZE);

  return 0;
}
      
