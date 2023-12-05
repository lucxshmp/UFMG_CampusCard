#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SimulaBancodedados.hpp"

TEST_CASE("Teste de recuperação de saldo inicial para matrículas existentes") {
    // Criação de uma instância do BancoDeDados
    BancoDeDados banco;

    // Teste de recuperação de saldo inicial para matrículas existentes
    CHECK(banco.recupera_saldo_inicial(2023000000) == 100.0);
    CHECK(banco.recupera_saldo_inicial(2023000001) == 100.0);
    CHECK(banco.recupera_saldo_inicial(2023000002) == 100.0);
    CHECK(banco.recupera_saldo_inicial(2023000003) == 100.0);
    CHECK(banco.recupera_saldo_inicial(2023000004) == 100.0);
}

TEST_CASE("Teste de recuperação de saldo inicial para matrícula não existente") {
    // Criação de uma instância do BancoDeDados
    BancoDeDados banco;

    // Teste de recuperação de saldo inicial para matrícula não existente
    CHECK(banco.recupera_saldo_inicial(999999) == 0.0);
}

// Adicione mais testes conforme necessário.
