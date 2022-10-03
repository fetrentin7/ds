#ifndef ATIVIDADE_FILA_H
#define ATIVIDADE_FILA_H

#include <iostream>
#include <sstream>
using namespace std;

template <typename F>
struct TELementoFila{
    F dado;
    TELementoFila *proximo;
};

template <typename F>
struct TFila{
    TELementoFila<F> *primeiro;
    TELementoFila<F> *ultimo;
};

template <typename F>

ostream& operator<<(ostream& os, TFila<F> fila) {
    if(fila.primeiro == NULL) {
        os << "fila vazia" << endl;
    } else {
        TELementoFila<F> * nav = fila.primeiro;
        for(int i =0 ; nav != NULL; i++){
            os << "fila[" << i << "]: " << nav->Dado << endl;
            nav = nav->proximo;
        }
    }
    return os;
}

template <typename F>
void queue( TFila<F> &fila, int novoDado){
    TELementoFila<F> *novo = new TELementoFila<F>;
    novo->dado = novoDado;
    novo->proximo = NULL;

    if(estaVazia(fila)){
        fila.primeiro = fila.ultimo = novo;
    }
    else{
        fila.ultimo->proximo = novo;
        fila.ultimo = novo;
    }
}

template <typename F>
void dequeue(TFila<F> &fila){
    if(estaVazia(fila)){
        throw "fila vazia";
    }
    else{
        TELementoFila<F> *nav = fila.primeiro;
        fila.primeiro = fila.primeiro->proximo;
        delete(nav);
    }
}

template <typename F>
bool estaVazia(TFila<F> fila){
    if(fila.primeiro == NULL){
        return true;
    }
    else{
        return false;
    }
}

template <typename F>
void mostrarFila(TFila<F> fila){
    TELementoFila<F> *nav = new TELementoFila<F>;

    while(nav!= NULL){
        cout<<nav->dado<<endl;
    }
}



#endif //ATIVIDADE_FILA_H
