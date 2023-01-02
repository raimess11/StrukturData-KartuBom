#include "ElementKartu.h"

#include<iostream>
using namespace std;

//game
void play(bool &finish, listPlayer &players, tumpukanKartu &set,addressPlayer &turn)
/*{I.S. finish true, yang artinya permainan belum berlangsung}
{F.S. Permainan berjalan selama finish masih false, berakhir ketika finish true}*/
{
    addressPlayer lose = NULL;
    prepareGame(players, set);
    startGame(finish,turn,players);

    while (finish == false)
    {
        string x;
        show(turn);
        cout<<"ambil kartu pemain selanjutnya\n";
        for(int i = 1; i < turn->next->info.jumlahKartu+1; i++)
        {
            cout<<i<<". ???\n";
        }
        takeCard(turn->info,turn->next->info,finish,set);
        removeCard(set, turn->info);
        show(turn);
        cout<<"your Turn just Over.\npress any key for past to the next player.\n";
        cin>>x;
        turn = turn->next;
    }
    lose = checkLose(players);
    cout<<"yang kalah adalah: "<<lose->info.namaPlayer<<endl;
}

void prepareGame(listPlayer &players, tumpukanKartu &set)
/*{I.S. Terdapat stack kartu yang akan dibagikan kepada pemain, seluruh pemain belum mendapatkan kartu,
belum ditentukan pemain untuk turn, status finish masih true}
{F.S. Setiap pemain mendapatkan kartu secara merata}*/
{
    cout<<"we just prepare your games\n";
    addressPlayer selectedPlayer = players.first;
    for(int i = 0; i<20;i++)
    {
        infotypeKartu infoNewCard;
        addressHand newCard;
        pop(set,infoNewCard);
        createHandElement(infoNewCard, newCard);
        enqueueCard(selectedPlayer->info.deck, newCard);
        selectedPlayer->info.jumlahKartu++;
        selectedPlayer = selectedPlayer->next;

    }
}

void startGame(bool &finish, addressPlayer &turn, listPlayer &players)
/*{I.S. Setiap pemain telah mendapatkan kartu, belum ditentukan pemain untuk turn, status playing masih false
F.S. Turn/giliran diberikan kepada pemain pertama dalam antrian}*/
{
    cout<<"starting the game\n";
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
void takeCard(player &CurrentPlayer, player &nextPlayer, bool &finish, tumpukanKartu &set)
/*{I.S. kartu pemain selanjutnya lebih dari 1
F.S. kartu pemain selanjutnya diambil dan ditampung dalam variabel, jumlahKartu pemain selanjutnya berkurang 1.
Jika kartu pemain selanjutnya sisa 1, maka permainan berakhir}*/
{
    addressHand takedCard = NULL;
    int selectNumber = -1;
    if(nextPlayer.jumlahKartu > 1)
    {
        //ambil kartu
        while(selectNumber < 0 || selectNumber > nextPlayer.jumlahKartu)
        {
            cout<<"pilih kartu!\n";
            cin >> selectNumber;
            cout<<"------------\n";
        }
        for(int qCard = 0; qCard < selectNumber; qCard++)
        {
            if(takedCard != NULL)
            {
                enqueueCard(nextPlayer.deck, takedCard);
            }
            dequeueCard(nextPlayer.deck, takedCard);
        }
        cout<<"\n=*=*=*=*=*=*=*=*=*=*=*=\n";
        cout<<"kamu mendapatkan: "<<takedCard->info<<endl;
        cout<<"=*=*=*=*=*=*=*=*=*=*=*=\n";
        nextPlayer.jumlahKartu--;
        //simpan kartu
        enqueueCard(CurrentPlayer.deck, takedCard);
        CurrentPlayer.jumlahKartu++;
    }
    else
    {
        finish = true;
    }
}

void removeCard(tumpukanKartu &set, player &targetPlayer)
/*{I.S. jumlah kartu pemain lebih dari 1
F.S. kartu pilihan pemain dihapus dari kumpulanKartu}*/
{
    addressHand removedCard = targetPlayer.deck.head;
    if(targetPlayer.jumlahKartu > 1)
    {
        if(removedCard->info == "Joker")
        {
            dequeueCard(targetPlayer.deck, removedCard);
            enqueueCard(targetPlayer.deck, removedCard);
        }
        dequeueCard(targetPlayer.deck, removedCard);

        targetPlayer.jumlahKartu--;
        //convert queue to stack
        //put card to stack
        push(set, removedCard->info);
    }
}
/* if(removedCard != NULL)
            {
                enqueueCard(targetPlayer.deck, removedCard);
            }
            removedCard = NULL;
            cout<<"buang 1 kartu milik mu !";
            cin>>selectNumber;

            //pilih kartu yang mau di buang
            for(int qCard = 0; qCard < selectNumber; qCard++)
            {
                if(removedCard != NULL)
                {
                    enqueueCard(targetPlayer.deck, removedCard);
                }
                dequeueCard(targetPlayer.deck, removedCard);
            }*/

//hand
void show(addressPlayer targetPlayer)
/*{I.S. Jumlah kartu pemain tidak kosong}
{F.S. Menampilkan seluruh kartu Hand pemain}*/
{
    cout<<"current card of "<<targetPlayer->info.namaPlayer<<endl;
    addressHand showingCard = targetPlayer->info.deck.head;

    for(int cardNumber = 1; cardNumber <= targetPlayer->info.jumlahKartu ; cardNumber++)
    {
        cout<<cardNumber<<". "<<showingCard->info<<endl;
        showingCard = showingCard->next;
    }
    cout<<endl;
}

//stack for set
void createStack(tumpukanKartu &S) {
    S.top = 0;
}

bool isEmpty(tumpukanKartu S) {
    if (S.top == -1) {
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

