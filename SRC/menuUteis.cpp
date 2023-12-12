#include "menuSalas.hpp"
#include "SalasUteis.hpp"
#include "menuUteis.hpp"
#include "interface.hpp"
#include <iostream>
#include <string>


namespace media::ui{

/// @brief construtor com todas as opcoes do menu 
    MenuUteis::MenuUteis(){
        _title = "Salas Uteis UFMG";
        _options.push_back("1 - Cadastrar Sala");
        _options.push_back("2 - Consultar Salas Cadastradas");
        _options.push_back("3 - Salvar e Sair");
    }

    Menu *MenuUteis::next(unsigned option) {

        CadastroSala cadastro;
        /// @brief carrega dados existentes, se houver
        cadastro.carregarCadastro(); 
        
        std::string nome = "0";
        std::string predio = "0";
        std::string numero = "0";
        
        do{
        switch (option){
            case 1:
        
                std::cout << "\nNome da Sala (nao utilize espaco): ";
                std::cin >> nome;
                std::cout << "Predio da Sala (nao utilize espaco): ";
                std::cin >> predio;
                std::cout << "Numero da Sala (nao utilize espaco): ";
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
                return new MenuUteis();
        }
    } while(option != 3);
    }
};
