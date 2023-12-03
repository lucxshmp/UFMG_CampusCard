#include "./Transacoes.hpp"


Saldo saldo;
Usuario usuario;

Transacoes::Transacoes(){
    confirma_pagamento=false;
}
void Transacoes::pagamento(){
    if (confirma_pagamento==true){
        saldo.diminuir_saldo(usuario.getNivelFump());
        std::cout<<"pagamento confirmado"<<std::endl;
    }
    else{
        std::cout<<"Houve um erro no pagamento"<<std::endl;
    }
}
