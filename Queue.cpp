#include "Queue.h"

void createPlayList(playlistLagu &Q) {
    head(Q) = nil;
    tail(Q) = nil;
}

void createElement(infotype laguBaru, adr &pLagu) {
    pLagu = new element;
    info(pLagu) = laguBaru;
    next(pLagu) = nil;
}

void enqueue(playlistLagu &Q, adr pLagu) {
    if (head(Q) == nil && tail(Q) == nil) {
        head(Q) = pLagu;
        tail(Q) = pLagu;
    } else {
        next(tail(Q)) = pLagu;
        tail(Q) = pLagu;
    }
}

void dequeue(playlistLagu &Q, adr &pLagu) {
    if (head(Q) == nil && tail(Q) == nil) {
        cout<<"Queue Kosong \n";
    } else if (head(Q) == tail(Q)) {
        head(Q) = nil;
        tail(Q) = nil;
    } else {
        pLagu = head(Q);
        head(Q) = next(pLagu);
        next(pLagu) = nil;
    }
}

void showSemuaLagu(playlistLagu Q) {
    adr x;
    x = head(Q);
    cout<<"====================Playlist===================="<<endl;
    if (head(Q) == nil && tail(Q) == nil) {
        cout<<"{Playlist Kosong}\n";
    } else {
        while (x != nil) {
            cout<<info(x).Artis<<" - "<<info(x).Judul<<endl;
            x = next(x);
        }
        cout<<endl;
    }
}
