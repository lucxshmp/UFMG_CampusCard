#include <iostream>
#include <string> 
#include "main_menu.hpp"
#include "menu.hpp"


namespace media::ui{
/// @brief construtor com todas as opcoes do menu principal 
    MenuPrincipal::MenuPrincipal(){
        _title = "Menu Principal :p";
        _options.push_back("1 - Transacoes RU e Saldo");
        _options.push_back("2 - Onibus, Vans e Transporte Geral");
        _options.push_back("3 - Grade Semanal");
        _options.push_back("4 - Rotina e Calendario");
        _options.push_back("5 - Salas");
        _options.push_back("6 - Mapas e Departamentos");
        _options.push_back("7 - Operacoes com a Carteira de Estudante");
    }

    Menu *MenuPrincipal::next(unsigned option) {
        media::ui::MenuTransacoesRU ru;
        media::ui::MenuOnibusVans transporte;
        media::ui::MenuGrade grade;
        media::ui::MenuRotinaCalendarios rotina;
        media::ui::MenuSalas salas;
        media::ui::MenuDepartamentos dep;
        media::ui::MenuCarteirinha carteirinha;
        
        switch (option) {
            case 1:
                // Lógica para a opção 1 - Transacoes RU e Saldo
                // Crie e retorne uma instância do menu correspondente, se aplicável
                ru.render();
                return new MenuTransacoesRU(); 
                break;

            case 2:
                // Lógica para a opção 2 - Onibus, Vans e Transporte Geral
                // Crie e retorne uma instância do menu correspondente, se aplicável
                transporte.render();
                return new MenuOnibusVans();
                break; 

            case 3:
                // Lógica para a opção 3 - Grade Semanal
                // Crie e retorne uma instância do menu correspondente, se aplicável
                grade.render();
                return new MenuGrade(); 
                break;

            case 4:
                // Lógica para a opção 4 - Rotina e Calendario
                // Crie e retorne uma instância do menu correspondente, se aplicável
                rotina.render();
                return new MenuRotinaCalendarios(); 
                break;

            case 5:
                // Lógica para a opção 5 - Salas
                // Crie e retorne uma instância do menu correspondente, se aplicável
                salas.render();
                return new MenuSalas(); 
                break;
                
            case 6:
                // Lógica para a opção 6 - Mapas e Departamentos
                // Crie e retorne uma instância do menu correspondente, se aplicável
                dep.render();
                return new MenuDepartamentos(); 
                break;

            case 7:
                // Lógica para a opção 7 - Operacoes com a Carteira de Estudante
                // Crie e retorne uma instância do menu correspondente, se aplicável
                carteirinha.render();
                return new MenuCarteirinha();
                break;

            default:
                // Opção inválida, retorne nullptr ou um menu padrão
                std::cout << "Opcao invalida!" << std::endl;
                return nullptr;
        }
    }
};