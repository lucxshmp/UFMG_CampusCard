#include "menuSalas.hpp"
#include "SalasUteis.hpp"
#include "menuDepartamento.hpp"
#include "interface.hpp"
#include "redirecionamento.hpp"
#include <iostream>

namespace media::ui{
    
/// @brief construtor com todas as opcoes do menu  
    MenuDepartamento::MenuDepartamento(){
        _title = "Salas por Departamento - Escolha o Predio";
        _options.push_back("1 - ICEx- Instituto de Ciencias Exatas");
        _options.push_back("2 - Escola de Engenharia");
        _options.push_back("3 - FACE");
        _options.push_back("4 - IGC - Instituto de Geociencia");
        _options.push_back("5 - Escola de Musica");
        _options.push_back("6 - ICB - Instituto de Ciencias Biologicas");
    }

    Menu *MenuDepartamento::next(unsigned option) {
        do{
        switch (option) {
            case 1:
                Redirecionamento::redirecionarLink("https://www.icex.ufmg.br/icex_novo/minha-salas/");
                return nullptr; 

            case 2:
                Redirecionamento::redirecionarLink("https://alocacao.eng.ufmg.br/consulta.html");
                return nullptr;
                 
            case 3:
                Redirecionamento::redirecionarLink("https://sistemas.face.ufmg.br/sti/alocacao/");
                return nullptr;

            case 4:
                Redirecionamento::redirecionarLink("https://www.igc.ufmg.br/sgs/index.php");
                return nullptr;
                 
            case 5:
                Redirecionamento::redirecionarLink("https://musica.ufmg.br/mapa-de-salas/");
                return nullptr;

            case 6:
                Redirecionamento::redirecionarLink("https://docs.google.com/spreadsheets/d/184fhnTOwHgfoX_DhPxW91d3KEKBdkpXIokDVqVRuIxY/edit#gid=213018235");
                return nullptr;

            default:
                // Opcao invalida, retorne menu padrao
                return new MenuDepartamento();                 
        }
    } while (option != 6);
    }
};
