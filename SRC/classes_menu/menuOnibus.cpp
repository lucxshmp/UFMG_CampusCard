#include "menuTransporte.hpp"
#include "onibus.hpp"
#include "menuOnibus.hpp"

namespace media::ui{
/// @brief construtor com todas as opcoes do menu principal 
    MenuOnibus::MenuOnibus(){
        _title = "\n\n********** MENU ONIBUS **********\n\n ";
        _title = "Escolha uma opção: \n";
        _options.push_back("1. Cadastrar ônibus");
        _options.push_back("2. Exibir ônibus cadastrados");
        _options.push_back("3. Editar ônibus");
        _options.push_back("0. Sair");
        std::cout << "> ";
    }

    Menu *MenuOnibus::next(unsigned option) {
        switch (option) {
            case 1:
                //implementar para onibus
                return nullptr; 
            case 2:

                //implementar para onibus
                return nullptr; 

            case 3: 
              //implementar para onibus
                return nullptr; 

            case 0:
            std::cout << "Saindo..." << std::endl;
            break;

            default:
                // Opção inválida, retorne nullptr ou um menu padrão
                std::cout << "Opcao invalida!" << std::endl;
                return nullptr;
        }
    }
};

