#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Saldo.hpp"
#include "SimulaBancodedados.hpp"

TEST_CASE("Teste de inicialização do saldo") {
    // Criação de uma instância do BancoDeDados e do Saldo
    BancoDeDados banco;
    Saldo saldo(2023000000, banco);

    // Verifica se o saldo inicial é 100.0 (conforme o banco de dados simulado)
    CHECK(saldo.retornar_saldo_atual() == 100.0);
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

TEST_CASE("Teste de diminuição de saldo com FUMP") {
    // Criação de uma instância do BancoDeDados e do Saldo
    BancoDeDados banco;
    Saldo saldo(2023000000, banco);

    // Diminui o saldo com FUMP (considerando diferentes valores de FUMP)
    saldo.diminuir_saldo(2);
    CHECK(saldo.retornar_saldo_atual() == 99.0);

    saldo.diminuir_saldo(3);
    CHECK(saldo.retornar_saldo_atual() == 98.0);

    saldo.diminuir_saldo(4);
    CHECK(saldo.retornar_saldo_atual() == 96.0);

    saldo.diminuir_saldo(5);
    CHECK(saldo.retornar_saldo_atual() == 93.1);

    saldo.diminuir_saldo(6);
    CHECK(saldo.retornar_saldo_atual() == 87.4);
}

