#ifndef TRANSACOES
#define TRANSACOES
#include <iostream>
#include "./usuario.hpp"
#include "Saldo.hpp"

/* @brief: Nesta classe busca-se efetuar funcionalidades da transacao em si, como confirmar pagamento, deposito
e gerar e ler documentos para pagamento.  */

class Transacoes{
    private: 
        bool confirma_pagamento;
    public: 
        Transacoes();
        void pagamento();
        void deposito();
        void consultar_saldo();
        void gerar_GRU();
        void ler_qrcode();
};
















#endif
