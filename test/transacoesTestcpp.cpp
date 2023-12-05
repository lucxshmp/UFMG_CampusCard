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

    transacoes.set_pagamento(true);
    transacoes.pagamento();
    CHECK(transacoes.get_pagamento() == true);

    transacoes.set_deposito(true);
    transacoes.deposito(100.0);
    CHECK(transacoes.get_deposito() == true);
    
}

TEST_CASE("Teste de consultar_saldo") {
    Transacoes transacoes;

    
}

TEST_CASE("Teste de preenche_pdf e gerar_GRU") {
    Transacoes transacoes;

    // Teste básico de preenche_pdf
    HPDF_Doc pdf = HPDF_New(NULL, NULL);
    HPDF_Page page = HPDF_AddPage(pdf);

    transacoes.preenche_pdf(page);
    

    // Teste básico de gerar_GRU
    transacoes.gerar_GRU("guia.pdf");
    

    // Liberar recursos
    HPDF_Free(pdf);
}

