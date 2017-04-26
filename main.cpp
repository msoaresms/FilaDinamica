#include <iostream>
using namespace std;

class Item{
private:
    int chave;
    string descricao;
public:
    Item(){}
    Item(int pChave, string pDescricao){
        this->chave = pChave;
        this->descricao = pDescricao;
    }
    int getChave() const {
        return chave;
    }
    void setChave(int chave) {
        Item::chave = chave;
    }
    string getDescricao() const {
        return descricao;
    }
    void setDescricao(string descricao) {
        Item::descricao = descricao;
    }
    void mostrar();
};

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
    void desinfileira(T *);
};

void Item::mostrar() {
    cout << "Descricao: " << this->descricao << endl;
    cout << "Chave: " << this->chave << endl << endl;
}

template <typename T>
void Fila<T>::enfileira(T pItem) {
    this->tras->setProx(new No<T>());
    this->tras = this->tras->getProx();
    this->tras->setItem(pItem);
    this->tras->setProx(NULL);
}

template <typename T>
void Fila<T>::desinfileira(T *pItem) {
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

    f.desinfileira(&x);
    f.desinfileira(&x);
    f.desinfileira(&x);
    f.desinfileira(&x);
    f.desinfileira(&x);


    return 0;
}