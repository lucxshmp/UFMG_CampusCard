#ifndef TRANSACOES
#define TRANSACOES
#include <iostream>
#include "./usuario.hpp"
#include "Saldo.hpp"

class Transacoes {
    public: 
        void pagamento();
        void deposito();
        void consultar_saldo();
        void gerar_GRU();
        void ler_qrcode();
};
















#endif
