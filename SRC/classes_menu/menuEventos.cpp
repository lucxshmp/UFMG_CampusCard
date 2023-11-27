#include "menuEventos.hpp"
#include "eventos.hpp"
#include "menuPrincipal.hpp"


namespace media::ui{
/// @brief construtor com todas as opcoes do menu principal 
    MenuEventos::MenuEventos(){
        
        _title = "Eventos e tarefas";
        _options.push_back("1 - cadastrar evento ou tarefa");
        _options.push_back("2 - editar evento ou tarefa");
        _options.push_back("3 - exibir lista ordenada por prazo de eventos e tarefas ");
        _options.push_back("3 - voltar ao menu principal ");

    }

    Menu *MenuEventos::next(unsigned option) {
        
        std::vector<Eventos> tarefas;
        Eventos eventos;

        switch (option) {
            case 1:
                eventos.adicionarTarefas(tarefas);
                MenuEventos::MenuEventos();
                return nullptr; 

            case 2:
                eventos.editarTarefas(tarefas); 
                MenuEventos::MenuEventos();
                return nullptr; 

            case 3:
                eventos.exibirPorPrazo
                MenuEventos::MenuEventos();
                return nullptr;
            
            case 4;
                MenuPrincipal::MenuPrincipal();
                return nullptr;

            default:
                // Opção inválida, retorne nullptr ou um menu padrão
                std::cout << "Opcao invalida!" << std::endl;
                return nullptr;

        }
    }
};
