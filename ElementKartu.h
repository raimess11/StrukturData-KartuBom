#ifndef ELEMENTKARTU_H_INCLUDED
#define ELEMENTKARTU_H_INCLUDED

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


#endif // ELEMENTKARTU_H_INCLUDED
