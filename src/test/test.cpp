#include <iostream>

int i = 10;

void f();

int main()
{
    f();
}

void f()
{
    int i = 20;
    printf("%d - %d\n", i, ::i);
}