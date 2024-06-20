#pragma once
// генерация колоды карт
int** generateCardsSet();
// отображение колоды
void showCards(int** array);
// перемешивание колоды
void shuffle(int** array);
// создание игроков (max 6)
string* createPlayers(int count);
// стартовая раздача денег
int* createCash(int countPlayers, int countMoney);
// отображение инфы об игроках
void showPlayers(string*& players, int*& cash, int count);
//сортировка колоды по номиналу
void sortSet(int**& set);
