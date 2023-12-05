#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "menuOnibus.hpp"
#include "menuTransporte.hpp"
#include "menuVans.hpp"
#include "onibus.hpp"
#include "van.hpp"

TEST_CASE("Teste de funcionalidades do sistema de transporte", "[SistemaTransporte]") {
    // Teste para a classe MenuTransporte
    SECTION("MenuTransporte") {
        media::ui::MenuTransporte menuTransporte;

        // Simula a escolha da opção 1 (Ônibus)
        Menu* nextMenu = menuTransporte.next(1);
        REQUIRE(dynamic_cast<media::ui::MenuOnibus*>(nextMenu) != nullptr);

        // Simula a escolha da opção 2 (Vans)
        nextMenu = menuTransporte.next(2);
        REQUIRE(dynamic_cast<media::ui::MenuVans*>(nextMenu) != nullptr);

        // Teste adicional: Simula uma escolha inválida
        nextMenu = menuTransporte.next(99);
        REQUIRE(nextMenu == nullptr);
    }

    // Teste para a classe MenuOnibus
    SECTION("MenuOnibus") {
        media::ui::MenuOnibus menuOnibus;

        // Simula a escolha da opção 1 (Cadastrar ônibus)
        Menu* nextMenu = menuOnibus.next(1);
        REQUIRE(dynamic_cast<media::ui::MenuOnibus*>(nextMenu) != nullptr);

        // Simula a escolha da opção 2 (Exibir ônibus cadastrados)
        nextMenu = menuOnibus.next(2);
        REQUIRE(dynamic_cast<media::ui::MenuOnibus*>(nextMenu) != nullptr);

        // Teste adicional: Simula uma escolha inválida
        nextMenu = menuOnibus.next(99);
        REQUIRE(nextMenu == nullptr);
    }

    // Teste para a classe MenuVans
    SECTION("MenuVans") {
        media::ui::MenuVans menuVans;

        // Simula a escolha da opção 1 (Cadastrar van)
        Menu* nextMenu = menuVans.next(1);
        REQUIRE(dynamic_cast<media::ui::MenuVans*>(nextMenu) != nullptr);

        // Simula a escolha da opção 2 (Exibir vans cadastradas)
        nextMenu = menuVans.next(2);
        REQUIRE(dynamic_cast<media::ui::MenuVans*>(nextMenu) != nullptr);

        // Teste adicional: Simula uma escolha inválida
        nextMenu = menuVans.next(99);
        REQUIRE(nextMenu == nullptr);
    }

    // Adicione mais testes conforme necessário para as outras classes (Onibus, Van, etc.)
}
