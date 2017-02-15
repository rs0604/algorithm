#include <stdio.h>
#include <stdlib.h>//rand()のため
#include <time.h>
typedef struct card {
  int number;
  char character;
} card_t;

void swap(card_t *card1, card_t *card2) {
  card_t temp;
  temp.number = card1->number;
  temp.character = card1->character;
  card1->number = card2->number;
  card1->character = card2->character;
  card2->number = temp.number;
  card2->character = temp.character;
}

void trace(card_t deck[], int length) {
  for(int i = 0; i < length; i++) {
    printf("%c%d\t", deck[i].character, deck[i].number);
    if(!((i+1) % 10)) printf("\n");
  }
  printf("\n");
}

void stableSort(card_t deck[], int length) {
}

#define SHUFFLE_TIMES 1000
void shuffle(card_t deck[], int length) {
  srand((unsigned)time(NULL));
  for(int i = 0; i < SHUFFLE_TIMES; i++) {
    int val1 = rand() % length;
    int val2 = rand() % length;
    swap(&deck[val1], &deck[val2]);
  }
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

  shuffle(deck, DECK_SIZE);
  trace(deck, DECK_SIZE);

  return 0;
}
