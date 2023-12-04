#include "menuTransporte.hpp"
#include "onibus.hpp"
#include "menuOnibus.hpp"
#include "menuVans.hpp"

#ifdef _WIN32
    // Comando para limpar o console no Windows
    #define CLEAR_SCREEN "cls"
#else
    // Comando para limpar o console em sistemas Unix/Linux
    #define CLEAR_SCREEN "clear"
#endif


namespace media::ui{
/// @brief construtor com todas as opcoes do menu principal 
    MenuTransporte::MenuTransporte(){
        _title = "\n\n********** TRANSPORTE **********\n\n ";
        _title = "Escolha uma opção: \n";
        _options.push_back("1. Onibus");
        _options.push_back("2. Vans");
        _options.push_back("0. Sair");
        std::cout << "> ";
    }

    Menu *MenuTransporte::next(unsigned option) {
        media::ui::MenuOnibus onibus;
        media::ui::MenuVans vans;
        switch (option) {
            case 1:
                system(CLEAR_SCREEN);
                onibus.render();
                return new MenuOnibus();
                break;
          
            case 2:
                system(CLEAR_SCREEN);
                vans.render();
                return new MenuVans();
                break;

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
