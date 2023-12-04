#include "menuSalas.hpp"
#include "SalasUteis.hpp"
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
    MenuSalas::MenuSalas(){
        _title = "Menu de Salas da UFMG";
        _options.push_back("1 - Salas Uteis");
        _options.push_back("2 - Salas por Departamento");
    }

    Menu *MenuSalas::next(unsigned option) {
        media::ui::MenuUteis uteis;
        media::ui::MenuDepartamento depto;

        do {
        switch (option) {
            
            case 1:
                // Logica para a opcao 2 - Menu de Salas Uteis
                system(CLEAR_SCREEN);
                uteis.render();
                return new MenuUteis(); 
                break;

            case 2:
                // Logica para a opcao 1 - Menu de Salas por Departamento
                system(CLEAR_SCREEN);
                depto.render();
                return new MenuDepartamento(); 
                break;
                
            default:
                // Opcao invalida, retorne nullptr ou um menu padrao
                std::cout << "Opcao invalida!" << std::endl;
                salas.render();
                return new MenuSalas;
        }
    } while (option != 2)
    } 
};
