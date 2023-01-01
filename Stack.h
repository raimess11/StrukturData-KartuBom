#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

typedef string infotype;

struct stack {
    infotype info[15];
    int Top;
};

void createStack(stack &S);
bool isEmpty(stack S);
bool isFull(stack S);
void push(stack &S,infotype x);
string pop(stack &S);
void printInfo(stack S);

#endif // STACK_H_INCLUDED
