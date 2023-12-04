#include "menuTransporte.hpp"
#include "onibus.hpp"
#include "menuOnibus.hpp"
#include "menuVans.hpp"

namespace media::ui{
/// @brief construtor com todas as opcoes do menu principal 
    MenuVans::MenuVans(){
        _title = "\n\n********** MENU VANS **********\n\n ";
        _title = "Escolha uma opção: \n";
        _options.push_back("1. Cadastrar vans");
        _options.push_back("2. Exibir vans");
        _options.push_back("3. Editar van");
        _options.push_back("0. Sair");
        std::cout << "> ";
    }

    Menu *MenuVans::next(unsigned option) {
        switch (option) {
            case 1:
                 //implementar para vans
          
            case 2:

               //implementar para vans

            case 3: 
              //implementar para vans

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

