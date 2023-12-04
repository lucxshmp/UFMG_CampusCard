#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "CarteiraEstudante.hpp"

TEST_CASE("CarteiraEstudante - GerarCarteiraDigital") {
    CarteiraEstudante carteira;
    const char* arquivo = "carteira_teste.pdf";

    // Chame a função de geração
    carteira.GerarCarteiraDigital(arquivo);

    // Verifique se o arquivo foi criado
    std::ifstream file(arquivo);
    REQUIRE(file.good());
    file.close();

    // Remova o arquivo de teste
    std::remove(arquivo);
}

TEST_CASE("CarteiraEstudante - obterStatusValidade e definirStatusValidade") {
    CarteiraEstudante carteira;

    // Verifique o status de validade padrão
    CHECK(carteira.obterStatusValidade() == true);

    // Mude o status de validade e verifique novamente
    carteira.definirStatusValidade(false);
    CHECK(carteira.obterStatusValidade() == false);

    // Mude o status de validade novamente e verifique
    carteira.definirStatusValidade(true);
    CHECK(carteira.obterStatusValidade() == true);
}
