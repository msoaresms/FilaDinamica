#include <iostream>
#include "Item.h"
#include "Fila.h"
using namespace std;

int main() {
    Fila<Item> f;

    Item x;

    Item a(1, "A");
    Item b(2, "B");
    Item c(3, "C");
    Item d(42, "M");

    f.enfileira(a);
    f.enfileira(b);
    f.enfileira(c);
    f.enfileira(d);

    f.desenfileira(&x);
    f.desenfileira(&x);
    f.desenfileira(&x);
    f.desenfileira(&x);
    f.desenfileira(&x);


    return 0;
}
