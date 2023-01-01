#ifndef ELEMENTKARTU_H_INCLUDED
#define ELEMENTKARTU_H_INCLUDED

#include"Stack.h"

//player
struct player
{
    string namaPlayer;
    hand deck;
    int jumlahKartu;
};

//players
typedef player infotypePlayer;
typedef elementPlayer* addressPlayer;

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
