#include "menuGradeSemanal.hpp"
#include "gradeSemanal.hpp"
#include "rotina.hpp"
#include "interface.hpp"
#include "main_menu.hpp"

#ifdef _WIN32
    // Comando para limpar o console no Windows
    #define CLEAR_SCREEN "cls"
#else
    // Comando para limpar o console em sistemas Unix/Linux
    #define CLEAR_SCREEN "clear"
#endif 

namespace media::ui{
/// @brief construtor com todas as opcoes do menu principal 
    MenuGrade::MenuGrade(){
        _title = "Grade Semanal";
        _options.push_back("1 - Cadastrar Disciplina");
        _options.push_back("2 - Editar Disciplina");
        _options.push_back("3 - Visualizar disciplinas cadastradas");
        _options.push_back("4 - Visualizar quadro de horários semanais");
        _options.push_back("5 - Retornar ao menu principal");

    }

    Menu *MenuGrade::next(unsigned option){

        Rotina rotina;
        Grade_Semanal grade;
        int aux = 0;
        do {
            switch (option){

                case 0:
                    aux = system(CLEAR_SCREEN);
                        if (aux == -1) {}
                    Interface interface;
                    interface.mensagemSaida();
                    return nullptr;

                case 1:
                    aux = system(CLEAR_SCREEN);
                    if (aux == -1) {}
                    rotina.cadastrarDisciplina();
                    return new MenuGrade(); 

                case 2:
                    aux = system(CLEAR_SCREEN);
                    if (aux == -1) {}
                    rotina.editar_disciplina();
                    return new MenuGrade();
                    
                case 3:
                    aux = system(CLEAR_SCREEN);
                    if (aux == -1) {}
                    rotina.informacoes_disciplina();
                    return new MenuGrade();
                
                case 4:
                    aux = system(CLEAR_SCREEN);
                    if (aux == -1) {}
                    grade.criarGrade(rotina);
                    return new MenuGrade();

                case 5:
                    aux = system(CLEAR_SCREEN);
                    if (aux == -1) {}
                    return new MenuPrincipal();

                default:
                    // Opção inválida, retorne nullptr ou um menu padrão
                    std::cout << "Opcao invalida!" << std::endl;
                    return new MenuGrade();
            }
        }while(option < 0 || option > 5);
}
}
