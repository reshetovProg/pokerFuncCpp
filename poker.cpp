#include <iostream>
#define random(a,b) a+rand()%(b+1-a)
using namespace std;

const string NAMES[] = { "Вася", "Катя", "Ира", "Коля", "Жора", "Игорь", "Гога" };
const int COUNT_NAMES = 7;

int** generateCardsSet() {
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
  if (count > 5 || count < 1) {
    cout << "не верное количество игроков" << endl;
    return nullptr;
  }
  else {
    string* array = new string[count];
    for (int i = 0, flag; i < count; i++) {
      array[i] = NAMES[random(0, COUNT_NAMES - 1)];
      flag = false;
      for (int j = 0; j < i; j++) {
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

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "");
    //  ♥4 : ♦5 : ♣6 : ♠7
    int** mainSet = generateCardsSet();
    shuffle(mainSet);
    showCards(mainSet);
    cout << endl;
    int playersCount = 5;
    string* playersName = createPlayers(playersCount);
    int* cash = createCash(playersCount, 1000);
    showPlayers(playersName, cash, playersCount);
    
    
}
