#include "menuTransporte.hpp"
#include "onibus.hpp"
#include "menuOnibus.hpp"
#include "menuVans.hpp"

namespace media::ui{
/// @brief construtor com todas as opcoes do menu principal 
    MenuOnibus::MenuOnibusVans(){
        _title = "\n\n********** MENU ONIBUS **********\n\n ";
        _title = "Escolha uma opção: \n";
        _options.push_back("1. Cadastrar ônibus");
        _options.push_back("2. Exibir ônibus cadastrados");
        _options.push_back("3. Editar ônibus");
        _options.push_back("0. Sair");
        std::cout << "> ";
    }

    Menu *MenuOnibus::next(unsigned option) {
        do{
        switch (option) {
            case 1:
                
                meuOnibus.cadastrarOnibus();
                meuOnibus.exibirInformacao();
                return nullptr;

            case 2:

                meuOnibus.exibirOnibusCadastrados();
                return MenuOnibusVans();

            case 3: 
                
                meuOnibus.editarOnibus();
                return nullptr; 

            case 0:
                std::cout << "Saindo..." << std::endl;
                return nullptr;

            default:
                // Opção inválida, retorna nullptr para passar na compilaçao
                std::cout << "Opcao invalida! Digite novamente:\n" << std::endl;
                std::cin >> option;  // leia novamente a entrada
                return nullptr;
        }
        } while (option < 0 || option > 3);
    }
};

