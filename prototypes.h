#pragma once
// ��������� ������ ����
int** generateCardsSet();
// ����������� ������
void showCards(int** array);
// ������������� ������
void shuffle(int** array);
// �������� ������� (max 6)
string* createPlayers(int count);
// ��������� ������� �����
int* createCash(int countPlayers, int countMoney);
// ����������� ���� �� �������
void showPlayers(string*& players, int*& cash, int count);
