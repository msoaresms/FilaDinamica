#ifndef FILA_FILA_H
#define FILA_FILA_H

#include "No.h"

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
        this->frente->setProx(nullptr);
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
    this->tras->setProx(nullptr);
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

#endif //FILA_FILA_H
