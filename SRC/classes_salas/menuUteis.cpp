#include "menuSalas.hpp"
#include "SalasUteis.hpp"
#include <iostream>


namespace media::ui{
    CadastroSala cadastro;

/// @brief carrega dados existentes, se houver
    cadastro.carregarCadastro();

/// @brief construtor com todas as opcoes do menu 
    MenuUteis::MenuUteis(){
        _title = "Salas Uteis UFMG";
        _options.push_back("1 - Cadastrar Sala");
        _options.push_back("2 - Consultar Salas Cadastradas");
        _options.push_back("3 - Salvar e Sair");
    }

    Menu *MenuUteis::next(unsigned option) {
        do {
        switch (option) {
            case 1:
                std::string nome, predio, numero;
                std::cout << "\nNome da Sala: ";
                std::cin >> nome;
                std::cout << "Predio da Sala: ";
                std::cin >> predio;
                std::cout << "Numero da Sala: ";
                std::cin >> numero;

                cadastro.cadastrarSala(nome, predio, numero);
                return nullptr; 

            case 2:
                cadastro.exibirSalas();
                return nullptr;
                 
            case 3:
                cadastro.salvarCadastro();
                std::cout << "Cadastro salvo. Saindo...\n";
                return nullptr;

            default:
                // Opcao invalida, retorne nullptr ou um menu padrao
                std::cout << "Opcao invalida!" << std::endl;
                uteis.render();
                return new MenuUteis;
        }
    } while(option != 3);
    }
};