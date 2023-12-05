#include "menuEventos.hpp"
#include "eventos.hpp"
#include "main_menu.hpp"
#include "validacao.hpp"
#include "gradeSemanal.hpp"
#include "rotina.hpp"
#include "interface.hpp"
#include <iostream>
#include <iomanip>

#ifdef _WIN32
    // Comando para limpar o console no Windows
    #define CLEAR_SCREEN "cls"
#else
    // Comando para limpar o console em sistemas Unix/Linux
    #define CLEAR_SCREEN "clear"
#endif


namespace media::ui{
    /// @brief construtor com todas as opcoes do menu principal 
    MenuEventos::MenuEventos(){

        _title = "Grade Semanal";
        _options.push_back("1 - Cadastrar tarefa");
        _options.push_back("2 - Editar tarefa");
        _options.push_back("3 - Visualizar tarefas cadastradas");
        _options.push_back("4 - Retornar ao menu principal");

    } 

    Menu *MenuEventos::next(unsigned option){

        int aux = 0;
        do {
        Eventos eventos;
        std::vector<Eventos> tarefas;

            switch (option){

                case 0:
                    ux = system(CLEAR_SCREEN);
                        if (aux == -1) {}
                    Interface interface;
                    interface.mensagemSaida();
                    return nullptr;

                case 1:
                    aux = system(CLEAR_SCREEN);
                    if (aux == -1) {}
                    eventos.adicionarTarefas(tarefas);
                    return new MenuGrade(); 

                case 2:
                    aux = system(CLEAR_SCREEN);
                    if (aux == -1) {}
                    eventos.editarTarefas(tarefas);
                    return new MenuGrade();

                case 3:
                    aux = system(CLEAR_SCREEN);
                    if (aux == -1) {}
                    eventos.exibirPorPrazo(tarefas);
                    return new MenuGrade();

                case 4:
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
};
