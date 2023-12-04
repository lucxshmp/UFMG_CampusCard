#include <iostream>
#include <string> 
#include <cstdlib>
#include "main_menu.hpp"
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
    MenuPrincipal::MenuPrincipal(){
        _title = "Menu Principal :p";
        _options.push_back("1 - Transacoes RU e Saldo");
        _options.push_back("2 - Onibus, Vans e Transporte Geral");
        _options.push_back("3 - Grade Semanal");
        _options.push_back("4 - Rotina e Calendario");
        _options.push_back("5 - Salas");
        _options.push_back("6 - Mapas");
        _options.push_back("7 - Operacoes com a Carteira de Estudante");
    }

    Menu *MenuPrincipal::next(unsigned option) {
        media::ui::MenuTransacoesRU ru;
        media::ui::MenuTransporte transporte;
        media::ui::MenuGrade grade;
        media::ui::MenuEventos eventos;
        media::ui::MenuSalas salas;
        media::ui::MenuMapas mapas;
        media::ui::MenuCarteirinha carteirinha;
        
        do {  
            switch (option) {
            case 1:
                // Lógica para a opção 1 - Transacoes RU e Saldo
                // Crie e retorne uma instância do menu correspondente, se aplicável
                system(CLEAR_SCREEN);
                ru.render();
                return new MenuTransacoesRU(); 
                break;

            case 2:
                // Lógica para a opção 2 - Onibus, Vans e Transporte Geral
                // Crie e retorne uma instância do menu correspondente, se aplicável
                system(CLEAR_SCREEN);
                transporte.render();
                return new MenuTransporte();
                break; 

            case 3:
                // Lógica para a opção 3 - Grade Semanal
                // Crie e retorne uma instância do menu correspondente, se aplicável
                system(CLEAR_SCREEN);
                grade.render();
                return new MenuGrade(); 
                break;

            case 4:
                // Lógica para a opção 4 - Rotina e Calendario
                // Crie e retorne uma instância do menu correspondente, se aplicável
                system(CLEAR_SCREEN);
                eventos.render();
                return new MenuEventos(); 
                break;

            case 5:
                // Lógica para a opção 5 - Salas
                // Crie e retorne uma instância do menu correspondente, se aplicável
                system(CLEAR_SCREEN);
                salas.render();
                return new MenuSalas(); 
                break;
                
            case 6:
                // Lógica para a opção 6 - Mapas
                // Crie e retorne uma instância do menu correspondente, se aplicável
                system(CLEAR_SCREEN);
                mapas.render();
                return new MenuMapas(); 
                break;

            case 7:
                // Lógica para a opção 7 - Operacoes com a Carteira de Estudante
                // Crie e retorne uma instância do menu correspondente, se aplicável
                system(CLEAR_SCREEN);
                carteirinha.render();
                return new MenuCarteirinha();
                break;

            default:
                // Opção inválida, retorna nullptr para passar na compilaçao
                std::cout << "Opcao invalida! Digite novamente:\n" << std::endl;
                std::cin >> option;  // leia novamente a entrada
                return nullptr;
        }
        } while (option < 0 || option > 7);
    }
};
