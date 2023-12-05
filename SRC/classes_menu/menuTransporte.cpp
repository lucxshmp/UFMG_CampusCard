#include "menuTransporte.hpp"
#include "onibus.hpp"
#include "menuOnibus.hpp"
#include "menuVans.hpp"
#include "interface.hpp"

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
        
        int aux = 0;
        do{
        switch (option) {

            case 0:
                    ux = system(CLEAR_SCREEN);
                        if (aux == -1) {}
                    Interface interface;
                    interface.mensagemSaida();
                    return nullptr;
            
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

            default:
                 // Opção inválida, retorna nullptr para passar na compilaçao
                std::cout << "Opcao invalida! Digite novamente:\n" << std::endl;
                std::cin >> option;  // leia novamente a entrada
                return nullptr;
        }
        } while (option < 0 || option > 2);
    }
};

