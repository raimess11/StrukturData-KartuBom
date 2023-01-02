#include "Stack.h"

void createStack(stack &S) {
    Top(S) = 0;
}

bool isEmpty(stack S) {
    if (Top(S) == 0) {
        return true;
    } else {
        return false;
    }
}

bool isFull(stack S) {
    if (Top(S) == 15) {
        return true;
    } else {
        return false;
    }
}

void push(stack &S,infotype x) {
    if (!isFull(S)) {
        Top(S) = Top(S) + 1;
        info(S)[Top(S)] = x;
    }
}

string pop(stack &S) {
    infotype x;
    Top(S) = Top(S) - 1;
    return x;
}

void printInfo(stack S) {
    int i;
    for (i = Top(S); i >= 1; i--) {
        cout<<info(S)[i]<<" ";
    }
}
