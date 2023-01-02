#ifndef ELEMENTKARTU_H_INCLUDED
#define ELEMENTKARTU_H_INCLUDED

#include<iostream>
using namespace std;

//kartu
const int N = 21;
typedef string kartu;
typedef kartu infotypeKartu;

//hand
typedef struct elementHand* addressHand;
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

//set
typedef int addressSet;
struct tumpukanKartu
{
    infotypeKartu Set[N]={"Joker","Clubs 9","Diamons 9","Spade 9","Hearts 10","Clubs 10",
    "Diamons 10","Spade 10","Hearts King","Clubs King","Diamons King","Spade King","Hearts Queen",
    "Clubs Queen","Diamons Queen","Spade Queen","Hearts Jack","Clubs Jack","Diamons Jack","Spade Jack"};

    addressSet top = 19;
};

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

//game

const string joker = "Joker";

void play(bool &finish, listPlayer &players, tumpukanKartu &set,addressPlayer& turn);
void prepareGame(listPlayer &players, tumpukanKartu &set);
void startGame(bool &finish, addressPlayer &turn, listPlayer &players);
addressPlayer checkLose(listPlayer players);

//players
void takeCard(player &CurrentPlayer, player &nextPlayer, bool &finish, tumpukanKartu &set);
void removeCard(tumpukanKartu &set, player &targetPlayer);

//hand
void show(addressPlayer player);

//stack for set
void createStack(tumpukanKartu &S);
bool isEmpty(tumpukanKartu S);
bool isFull(tumpukanKartu S);
void push(tumpukanKartu &S,infotypeKartu x);
void pop(tumpukanKartu &S,infotypeKartu &x);
void printInfo(tumpukanKartu S);

//List players
//LINKED LIST BIASA


//Queue for hand
void createHandQueue(kartuPegangan &newKartuPegangan);
void createHandElement(infotypeKartu newInfotypeKartu, addressHand &newAddressHand);
bool handIsFull(addressPlayer targetPlayer);
bool handIsEmpty(addressPlayer targetPlayer);
void enqueueCard(kartuPegangan &hand, addressHand newCard);
void dequeueCard(kartuPegangan &hand, addressHand &removedCard);
void showCardHand(kartuPegangan hand);

#endif // ELEMENTKARTU_H_INCLUDED
