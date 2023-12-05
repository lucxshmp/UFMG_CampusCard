#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Transacoes.hpp"

TEST_CASE("Teste de construtor e getters") {
    Transacoes transacoes;
    CHECK(transacoes.get_pagamento() == false);
    CHECK(transacoes.get_deposito() == false);
}

TEST_CASE("Teste de set_pagamento e set_deposito") {
    Transacoes transacoes;

    transacoes.set_pagamento(true);
    CHECK(transacoes.get_pagamento() == true);

    transacoes.set_deposito(true);
    CHECK(transacoes.get_deposito() == true);
}

TEST_CASE("Teste de pagamento e deposito") {
    Transacoes transacoes;

    transacoes.pagamento();
    CHECK(transacoes.get_pagamento() == true);

    transacoes.deposito(100.0);
    CHECK(transacoes.get_deposito() == true);
    
}

TEST_CASE("Teste de consultar_saldo") {
    Transacoes transacoes;

    
}

TEST_CASE("Teste de preenche_pdf, gerar_GRU e ler_qrcode") {
    Transacoes transacoes;

    
}



