#ifndef TRANSACOES
#define TRANSACOES
#include <iostream>
#include "usuario.hpp"
#include "Saldo.hpp"

/* @brief: Nesta classe busca-se efetuar funcionalidades da transacao em si, como confirmar pagamento, deposito
e gerar e ler documentos para pagamento.  */
extern Saldo saldo;
extern Usuario usuario;
extern BancoDeDados banco;

class Transacoes {
    private: 
        bool confirma_pagamento;
        bool confirma_deposito;
    public: 
        Transacoes();
        bool get_pagamento();
        bool get_deposito();
        void set_pagamento(bool pagamento);
        void set_deposito(bool deposito);
        void pagamento();
        void deposito(double valor);
        void consultar_saldo();
        void ler_qrcode();
};
















#endif