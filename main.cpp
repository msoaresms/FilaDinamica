#include <iostream>
#include "Item.h"
using namespace std;

template <class T>
class No{
private:
    T item;
    No<T> *prox;
public:
    const T &getItem() const {
        return item;
    }
    void setItem(const T &item) {
        this->item = item;
    }
    No<T> *getProx() const {
        return prox;
    }
    void setProx(No<T> *prox) {
        this->prox = prox;
    }
};

template <class T>
class Fila{
private:
    No<T> *frente, *tras;
    bool vazia(){
        return (this->frente == this->tras);
    }
public:
    Fila(){
        this->frente = new No<T>();
        this->frente->setProx(NULL);
        this->tras = this->frente;
    }

    No<T> *getFrente() const {
        return frente;
    }
    void setFrente(No<T> *frente) {
        Fila::frente = frente;
    }
    No<T> *getTras() const {
        return tras;
    }
    void setTras(No<T> *tras) {
        Fila::tras = tras;
    }

    void enfileira(T);
    void desenfileira(T *);
};

template <typename T>
void Fila<T>::enfileira(T pItem) {
    this->tras->setProx(new No<T>());
    this->tras = this->tras->getProx();
    this->tras->setItem(pItem);
    this->tras->setProx(NULL);
}

template <typename T>
void Fila<T>::desenfileira(T *pItem) {
    if (!this->vazia()) {
        No<T> *aux = this->frente;
        this->frente = this->frente->getProx();
        *pItem = this->frente->getItem();
        delete aux;
    }
}

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
