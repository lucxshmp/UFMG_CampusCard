#include "menuEventos.hpp"
#include "eventos.hpp"
#include "menuPrincipal.hpp"
#include "interface.hpp"


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
        
        do {
            Rotina rotina;
            Grade_Semanal grade;

            switch (option){

                case 0:
                
                    Interface::mensagemSaida();
                    return nullptr;

                case 1:
                    rotina.cadastrarDisciplina();
                    return new MenuGrade(); 

                case 2:
                    rotina.editar_disciplina();
                    return new MenuGrade();
                    
                case 3:
                    rotina.informacoes_disciplina();
                    return new MenuGrade();
                
                case 4:
            
                    grade.criarGrade(rotina);
                    return new MenuGrade();

                case 5:
                    return new MenuPrincipal();

                default:
                    // Opção inválida, retorne nullptr ou um menu padrão
                    std::cout << "Opcao invalida!" << std::endl;
                    return new MenuGrade();
            }
        }while(option < 0 || option > 5);
    }
};
