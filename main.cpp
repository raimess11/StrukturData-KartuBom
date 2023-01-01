#include <iostream>

using namespace std;

#include"ElementKartu.h"

int main()
{

    //bikin list player
    listPlayer players;
    players.first = NULL;
    for(int i = 0; i < 4; i++)
    {
        addressPlayer newPlayer = new elementPlayer;
        cin>>newPlayer->info.namaPlayer;
        createHandQueue(newPlayer->info.deck);
        newPlayer->info.jumlahKartu = 0;

        if(players.first = NULL)
        {
            players.first = newPlayer;
        }
        else
        {
            newPlayer->next = players.first;
            players.first = newPlayer;
        }
    }

    //bikin stack array set
    tumpukanKartu set;
    createStack(set);
    finish = true;
    play(finish,players,set);
    return 0;
}
//{"Joker","Clubs 8","Diamons 8","Spade 8","Hearts 9","Clubs 9","Diamons 9","Spade 9","Hearts 10","Clubs 10","Diamons 10","Spade 10","Hearts King","Clubs King","Diamons King","Spade King","Hearts Queen","Clubs Queen","Diamons Queen","Spade Queen"};
