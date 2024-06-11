#include <iostream>
#define random(a,b) a+rand()%(b+1-a)
using namespace std;

#include "prototypes.h"
#include "constants.h"


int** generateCardsSet() {
    //  suit - ♥3 : ♦4 : ♣5 : ♠6
    int** set = new int* [52];
    for (int index=0,value = 2; value < 15; value++) {
        for (int suit = 3; suit < 7; suit++) {
            set[index++] = new int[2]{value, suit};
        }    
    }
    return set;
}
void showCards(int** array) {
    int countCards = _msize(array) / sizeof(array[0]);
    for (int i = 0; i < countCards; i++) {
        switch (array[i][0]) {
        case 11:
            cout << "J";
            break;
        case 12:
            cout << "Q";
            break;
        case 13:
            cout << "K";
            break;
        case 14:
            cout << "A";
            break;
        default:
            cout << array[i][0];
        }
        cout << char(array[i][1]) << " ";
    }
}
void shuffle(int** array) {
    int size = _msize(array) / sizeof(array[0]);
    for (int i = 0; i < size; i++) {
        swap(array[i], array[random(0, size - 1)]);
    }
}
string* createPlayers(int count) {
  if (count > 6 || count < 1) {
    cout << "не верное количество игроков" << endl;
    return nullptr;
  }
  else {
    string* array = new string[count];
    array[0] = "Игрок";
    for (int i = 1, flag; i < count; i++) {
      array[i] = NAMES[random(0, COUNT_NAMES - 1)];
      flag = false;
      for (int j = 1; j < i; j++) {
        if (array[i] == array[j]) {
          flag = true;
          break;
        }
      }
      if (flag) i--;
    }
    return array;
  }

}
int* createCash(int countPlayers, int countMoney) {
  int* cash = new int[countPlayers];
  for (int i = 0; i < countPlayers; i++) {
    cash[i] = countMoney;
  }
  return cash;
}
void showPlayers(string*& players, int*& cash, int count) {
  for (int i = 0; i < count; i++) {
    cout << players[i] <<"\t" << cash[i]<<"$" << endl;
  }
}

void showPlayer(string players, int cash, int**& playersSet) {
  cout << players << "\t" << cash << "$" << " [ ";
  showCards(playersSet);
  cout << "]" <<endl;
}

void transferTopCard(int**& outSet, int**& inSet) {
  int countOutSet = _msize(outSet) / sizeof(outSet[0]);
  int countInSet = _msize(inSet) / sizeof(inSet[0]);
  int** outSetBuf = new int* [countOutSet - 1];
  int** inSetBuf = new int* [countInSet + 1];
  for (int i = 0; i < countOutSet - 1; i++) {
    outSetBuf[i] = outSet[i];
  }
  for (int i = 0; i < countInSet; i++) {
    inSetBuf[i] = inSet[i];
  }
  inSetBuf[countInSet] = outSet[countOutSet - 1];
  delete[] inSet;
  delete[] outSet;
  inSet = inSetBuf;
  outSet = outSetBuf;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "");
    int** mainSet = generateCardsSet();
    shuffle(mainSet);
    showCards(mainSet);
    cout << endl;
    int playersCount = 6;
    string* playersName = createPlayers(playersCount);
    int* cash = createCash(playersCount, 1000);
    
    int*** playersSets = new int** [playersCount];
    for (int i = 0; i < playersCount; i++) {
      playersSets[i] = new int* [0];
    }

    for (int i = 0; i < playersCount; i++) {
      for (int j = 0; j < 2; j++) {
        transferTopCard(mainSet, playersSets[i]);
      }     
    }

    for (int i = 0; i < playersCount; i++) {
      showPlayer(playersName[i], cash[i], playersSets[i]);
    }

    while (true) {

    }
    
    
}
