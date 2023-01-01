#include "ElementKartu.h"

#include<cstdlib>

#include<iostream>
using namespace std;

//game
void play(bool &finish, listPlayer &players, tumpukanKartu &set)
/*{I.S. finish true, yang artinya permainan belum berlangsung}
{F.S. Permainan berjalan selama finish masih false, berakhir ketika finish true}*/
{
    prepareGame(players, set);
    startGame(finish,turn,players);
    while (finish == false)
    {
        show(turn);
        takeCard(turn->info,turn->next->info,finish);
        removeCard(set, turn->info);
        turn = turn->next;
    }
    checkLose(players);
}

void prepareGame(listPlayer &players, tumpukanKartu &set)
/*{I.S. Terdapat stack kartu yang akan dibagikan kepada pemain, seluruh pemain belum mendapatkan kartu,
belum ditentukan pemain untuk turn, status finish masih true}
{F.S. Setiap pemain mendapatkan kartu secara merata}*/
{
    //players yang sudah punya kartu
    infotypeKartu newCard;
    addressHand newHandCard;
    listPlayer readyPlayers;
    readyPlayers.first = NULL;

    //bagikan kartu
    addressPlayer prev;
    while(prev->next != players.first)
    {
        prev = prev->next;
    }
    while(players.first != NULL)
    {
        //kalau beruntung dapet kartu
        if(rand() % 4 > 2)
        {
            pop(set,newCard);
            createHandElement(newCard, newHandCard);
            enqueueCard(players.first->info.deck, newHandCard);
            players.first->info.jumlahKartu++;
        }
        //geser
        if(handIsFull(players.first))
        {
            if(players.first->next != players.first)
            {
                prev->next = players.first->next;
                players.first = players.first->next;
                players.first->next = readyPlayers.first;
                readyPlayers.first = players.first;
            }
            else
            {
                players.first->next = readyPlayers.first;
                readyPlayers.first = players.first;
                players.first = NULL;
            }
        }
        else
        {
            players.first = players.first->next;
        }
    }
    players = readyPlayers;
}

void startGame(bool &finish, addressPlayer &turn, listPlayer &players)
/*{I.S. Setiap pemain telah mendapatkan kartu, belum ditentukan pemain untuk turn, status playing masih false
F.S. Turn/giliran diberikan kepada pemain pertama dalam antrian}*/
{
    finish = false;
    turn = players.first;
}

addressPlayer checkLose(listPlayer players)
/*{I.S. Permainan telah berakhir/finish
F.S. Pemain yang memiliki kartu bom (Joker) dinyatakan kalah}*/
{
    addressPlayer checksPlayer = players.first;
    while(checksPlayer->next != players.first)
    {
        if(checksPlayer->info.deck.head->info == joker)
        {
            return checksPlayer;
        }
        checksPlayer = checksPlayer->next;
    }
    return checksPlayer;
}

//players
void takeCard(player &CurrentPlayer, player &nextPlayer, bool &finish)
/*{I.S. kartu pemain selanjutnya lebih dari 1
F.S. kartu pemain selanjutnya diambil dan ditampung dalam variabel, jumlahKartu pemain selanjutnya berkurang 1.
Jika kartu pemain selanjutnya sisa 1, maka permainan berakhir}*/
{
    addressHand takedCard = NULL;
    int selectNumber = -1;
    if(nextPlayer.jumlahKartu > 1)
    {
        //ambil kartu
        while(selectNumber < 0 && selectNumber > nextPlayer.jumlahKartu)
        {
            cin >> selectNumber;
        }
        for(int qCard = 0; qCard < selectNumber; qCard++)
        {
            if(takedCard != NULL)
            {
                enqueueCard(nextPlayer.deck, takedCard);
            }
            dequeueCard(nextPlayer.deck, takedCard);
        }
        nextPlayer.jumlahKartu--;
        //simpan kartu
        enqueueCard(CurrentPlayer.deck, takedCard);
        CurrentPlayer.jumlahKartu++;
    }
    else
    {
        //endgame
    }
}

void removeCard(tumpukanKartu &set, player targetPlayer)
/*{I.S. jumlah kartu pemain lebih dari 1
F.S. kartu pilihan pemain dihapus dari kumpulanKartu}*/
{
    int selectNumber = 0;
    if(targetPlayer.jumlahKartu > 1)
    {
        addressHand removedCard = NULL;
        //pilih kartu yang mau di buang
        for(int qCard = 0; qCard < selectNumber; qCard++)
        {
            if(removedCard != NULL)
            {
                enqueueCard(targetPlayer.deck, removedCard);
            }
            dequeueCard(targetPlayer.deck, removedCard);
        }
        targetPlayer.jumlahKartu--;
        //convert queue to stack
        //put card to stack
        push(set, removedCard->info);
    }
}

//hand
void show(addressPlayer targetPlayer)
/*{I.S. Jumlah kartu pemain tidak kosong}
{F.S. Menampilkan seluruh kartu Hand pemain}*/
{
    showCardHand(targetPlayer->info.deck);
}

//stack for set
void createStack(tumpukanKartu &S) {
    S.top = 0;
}

bool isEmpty(tumpukanKartu S) {
    if (S.top == 0) {
        return true;
    } else {
        return false;
    }
}

bool isFull(tumpukanKartu S) {
    if (S.top == N) {
        return true;
    } else {
        return false;
    }
}

void push(tumpukanKartu &S,infotypeKartu x) {
    if (!isFull(S)) {
        S.top = S.top + 1;
        S.Set[S.top] = x;
    }
}

void pop(tumpukanKartu &S,infotypeKartu &x) {
    if (!isEmpty(S)) {
        x = S.Set[S.top];
        S.top = S.top - 1;
    }
}

void printInfo(tumpukanKartu S) {
    int i;
    for (i = S.top; i >= 1; i--) {
        cout<<S.Set[i]<<" ";
    }
}


//Queue for hand
void createHandQueue(kartuPegangan &newKartuPegangan)
{
    newKartuPegangan.head = NULL;
    newKartuPegangan.tail = NULL;
}

void createHandElement(infotypeKartu newInfotypeKartu, addressHand &newAddressHand)
{
    newAddressHand = new elementHand;
    newAddressHand->info = newInfotypeKartu;
    newAddressHand->next = NULL;
}

bool handIsFull(addressPlayer targetPlayer)
{
    int numberOfCard = 0;
    addressHand countCard = targetPlayer->info.deck.head;
    while(countCard->next != NULL)
    {
        numberOfCard++;
        countCard = countCard->next;
    }
    return numberOfCard >= 5;
}

bool handIsEmpty(addressPlayer targetPlayer)
{
    return targetPlayer->info.deck.head != NULL;
}

void enqueueCard(kartuPegangan &hand, addressHand newCard)
{
    if (hand.head == NULL && hand.tail == NULL) {
        hand.head = newCard;
        hand.tail = newCard;
    } else {
        hand.tail->next = newCard;
        hand.tail = newCard;
    }
}

void dequeueCard(kartuPegangan &hand, addressHand &removedCard)
{
    if (hand.head == NULL && hand.tail == NULL) {
        cout<<"Queue Kosong \n";
    } else if (hand.head == hand.tail) {
        hand.head = NULL;
        hand.tail = NULL;
    } else {
        removedCard = hand.head;
        hand.head = removedCard->next;
        removedCard->next = NULL;
    }
}

void showCardHand(kartuPegangan hand)
{
    addressHand showingCard = hand.head;
    for(int cardNumber = 1; showingCard->next != NULL; cardNumber++)
    {
        cout<<"/t"<<cardNumber;
    }
    cout<<endl;
    for(int cardNumber = 1; showingCard->next != NULL; cardNumber++)
    {
        cout<<"/t"<<showingCard->info;
    }
    cout<<endl;
}
