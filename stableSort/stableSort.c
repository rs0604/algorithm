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
  system("clear");
  for(int i = 0; i < length; i++) {
    printf("%c%d\t", deck[i].character, deck[i].number);
    if(!((i+1)%13)) printf("\n");
  }
  fflush(stdout);
}


void bubbleSort(card_t deck[], int length) {
  for(int i = 0; i < length; i++) {
    for(int j = length-1; j > i; j--) {
      if(deck[j].number < deck[j-1].number) {
        swap(&deck[j], &deck[j-1]);
        usleep(60000);
        trace(deck, length);
      }
    }
  }
}

void selectionSort(card_t deck[], int length) {
  for(int i = 0; i < length; i++) {
    int minj = i;
    for(int j = i; j < length; j++) {
      if(deck[j].number < deck[minj].number)
        minj = j;
    }
    swap(&deck[i], &deck[minj]);
    usleep(60000);
    trace(deck, length);
  }
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

int isStable(card_t stable_deck[], card_t test_deck[], int length) {
  for(int i = 0; i < length; i++) {
    if(!(stable_deck[i].character == test_deck[i].character)) {
      return -1;
    }
  }
  return 0;
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

  // シャッフルした後、比較元とするためのコピーを作る。
  shuffle(deck, DECK_SIZE);
  card_t old_deck[DECK_SIZE] = {};
  memcpy(old_deck, deck, sizeof(deck));
  
  trace(deck, DECK_SIZE);

  printf("bubble sort.\n");
  bubbleSort(deck, DECK_SIZE);

  printf("\ndone!\n");
  sleep(2);

  card_t selectionSortDeck[DECK_SIZE] = {};
  memcpy(selectionSortDeck, old_deck, sizeof(old_deck));

  printf("selectionSort.\n");
  sleep(2);
  selectionSort(selectionSortDeck, DECK_SIZE);
  printf("\ndone!\n");
  sleep(2);

  if(isStable(deck, selectionSortDeck, DECK_SIZE) == -1) {
    printf("Not Stable.\n");
  } else {
    printf("Stable.\n");
  }
  
  return 0;
}
