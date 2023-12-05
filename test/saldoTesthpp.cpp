#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Saldo.hpp"

TEST_CASE("Teste de saldo inicial") {
    // Criação de uma instância do BancoDeDados e do Saldo
    BancoDeDados banco;
    Saldo saldo(2023000000, banco);

    // Verifica se o saldo inicial é 100.0 (conforme o banco de dados simulado)
    CHECK(saldo.retornar_saldo_atual() == 100.0);
}

TEST_CASE("Teste de diminuição de saldo com FUMP") {
    // Criação de uma instância do BancoDeDados e do Saldo
    BancoDeDados banco;
    Saldo saldo(2023000000, banco);

    // Diminui o saldo com FUMP (considerando um valor de FUMP arbitrário)
    saldo.diminuir_saldo(50);

    // Verifica se o saldo foi reduzido corretamente
    CHECK(saldo.retornar_saldo_atual() == 50.0);
}

TEST_CASE("Teste de adição de saldo") {
    // Criação de uma instância do BancoDeDados e do Saldo
    BancoDeDados banco;
    Saldo saldo(2023000000, banco);

    // Adiciona saldo (considerando um valor arbitrário)
    saldo.adicionar_saldo(30.0);

    // Verifica se o saldo foi aumentado corretamente
    CHECK(saldo.retornar_saldo_atual() == 130.0);
}

