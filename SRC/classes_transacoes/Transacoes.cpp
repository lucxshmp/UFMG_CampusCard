#include "./Transacoes.hpp"


Saldo saldo;
Usuario usuario;

Transacoes::Transacoes(){
    confirma_pagamento=false;
    confirma_deposito=false;
}
void Transacoes::pagamento(){
    if (confirma_pagamento==true){
        saldo.diminuir_saldo(usuario.getNivelFump());
        std::cout<<"Pagamento confirmado"<<std::endl;
    }
    else{
        std::cout<<"Houve um erro no pagamento"<<std::endl;
    }
}
void Transacoes::deposito(){
    if (confirma_deposito==true){
        saldo.adicionar_saldo(0); //O zero é apenas um valor qualquer para completar a lógica da transação. Será modificado.
        std::cout<<"Deposito confirmado"<<std::endl;
    }
    else{
        std::cout<<"Houve um erro no deposito"<<std::endl;
    }
}
