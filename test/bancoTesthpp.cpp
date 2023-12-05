#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SimulaBancodedados.hpp"

TEST_CASE("Teste de recuperação de saldo inicial") {
    // Criação de uma instância do BancoDeDados
    BancoDeDados banco;

    // Adiciona alguns saldos iniciais fictícios para fins de teste
    banco.recupera_saldo_inicial(123456);  // Matrícula fictícia
    banco.recupera_saldo_inicial(987654);  // Outra matrícula fictícia

    // Teste de recuperação de saldo inicial
    CHECK(banco.recupera_saldo_inicial(123456) == 0.0); // Assume que o saldo inicial padrão é 0.0
    CHECK(banco.recupera_saldo_inicial(987654) == 0.0); // Assuma o mesmo saldo inicial para essa matrícula
    // Adicione mais verificações conforme necessário para os saldos iniciais adicionados.

    // Teste para matrícula inexistente
    CHECK(banco.recupera_saldo_inicial(999999) == 0.0); // Deve retornar 0.0 para matrículas não existentes
}

// Adicione mais testes conforme necessário.
