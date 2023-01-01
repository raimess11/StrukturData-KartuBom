#ifndef ELEMENTKARTU_H_INCLUDED
#define ELEMENTKARTU_H_INCLUDED

#include<iostream>
using namespace std;

//player
struct player
{
    string namaPlayer;
    kartuPegangan deck;
    int jumlahKartu;
};

//players
typedef player infotypePlayer;
typedef struct elementPlayer* addressPlayer;

struct elementPlayer
{
    infotypePlayer info;
    addressPlayer next;
};

struct listPlayer
{
    addressPlayer first;
};

void takeCard(player &CurrentPlayer, player &nextPlayer, bool &finish);
void removeCard(addressHand &removedCard, player targetPlayer);

//kartu
const int N = 20;
string kartu;
typedef kartu infotypeKartu;



//set
int addressSet;
struct tumpukanKartu
{
    infotypeKartu[N] Set;
    addressSet top;
};

//void createStack(tumpukanKartu &S);
//bool isEmpty(tumpukanKartu S);
//bool isFull(tumpukanKartu S);
//void push(tumpukanKartu &S,infotype x);
//string pop(tumpukanKartu &S);
//void printInfo(tumpukanKartu S);

//hand
typedef struct elementHand *addressHand;

struct elementHand
{
    infotypeKartu info;
    addressHand next;
};

struct kartuPegangan
{
    addressHand head;
    addressHand tail;
};

void show(addressPlayer player)

//game
addressPlayer turn;
player lose;
bool finish;

void play(bool &finish, listPlayer &players, tumpukanKartu &set);
void prepareGame(listPlayer &players, tumpukanKartu &set);
void startGame(bool &finish, addressPlayer &turn, listPlayer &players);
addressPlayer checkLose(listPlayer players);

#endif // ELEMENTKARTU_H_INCLUDED
