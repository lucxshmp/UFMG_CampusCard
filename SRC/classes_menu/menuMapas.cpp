#include <iostream>
#include <string> 
#include <cstdlib>
#include "menuMapas.hpp"
#include "menu.hpp"

#ifdef _WIN32
    // Comando para limpar o console no Windows
    #define CLEAR_SCREEN "cls"
#else
    // Comando para limpar o console em sistemas Unix/Linux
    #define CLEAR_SCREEN "clear"
#endif

namespace media::ui{
/// @brief construtor com todas as opcoes do menu principal 
    MenuMapas::MenuMapas(){
        _title = "Menu de Mapas da UFMG";
        _options.push_back("1 - Mapas dos Campi");
        _options.push_back("2 - Mapas das linhas do Interno");
       
    }

    Menu *MenuMapas::next(unsigned option) {
        media::ui::MapasCampus campus;
        media::ui::MapasInterno interno;

        do{
        switch (option) {
            case 1:
                // Lógica para a opção 1 - Mapas dos Campus
                system(CLEAR_SCREEN);
                campus.render();
                return new MapasCampus(); 
                break;

            case 2:
                // Lógica para a opção 2 - Mapas das linhas do Interno
                system(CLEAR_SCREEN);
                interno.render();
                return new MapasInterno();
                break; 
            
            default:
                // Opção inválida, retorna nullptr para passar na compilaçao
                std::cout << "Opcao invalida! Digite novamente:\n" << std::endl;
                std::cin >> option;  // leia novamente a entrada
                return nullptr;
        }
        }while (option < 1 || option > 2);
    }
};


