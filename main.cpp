#include"ElementKartu.h"

int main()
{

    //membuat list player
    listPlayer players;
    players.first = NULL;
    addressPlayer turn;

    cout<<"loading player:\n";
    for(int i = 0; i < 4; i++)
    {
        cout<<"Insert player-"<<i+1<<" name : ";
        addressPlayer newPlayer = new elementPlayer;
        cin>>newPlayer->info.namaPlayer;
        createHandQueue(newPlayer->info.deck);
        newPlayer->info.jumlahKartu = 0;

        if(players.first == NULL)
        {
            players.first = newPlayer;
            newPlayer->next = players.first;
        }
        else
        {
            addressPlayer Q = players.first;
            while(Q->next != players.first)
            {
                Q = Q->next;
            }
            Q->next = newPlayer;
            newPlayer->next = players.first;

        }

    }

    //membuat stack array set

    tumpukanKartu set;
    createStack(set);
    set.top = 19;
    bool finish = true;

    play(finish,players,set,turn);
    return 0;
}
//{"Joker","Clubs 8","Diamons 8","Spade 8","Hearts 9","Clubs 9","Diamons 9","Spade 9","Hearts 10","Clubs 10","Diamons 10","Spade 10","Hearts King","Clubs King","Diamons King","Spade King","Hearts Queen","Clubs Queen","Diamons Queen","Spade Queen"};
