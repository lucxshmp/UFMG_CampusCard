#include "menuGradeSemanal.hpp"
#include "gradeSemanal.hpp"
#include "rotina.hpp"


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

        switch (option) {
            case 1:
                rotina.cadastrarDisciplina();
                return MenuGrade(); 

            case 2:
                rotina.editar_disciplina();
                return MenuGrade();
                
            case 3:
                rotina.informacoes_disciplina();
                return MenuGrade();
            
            case 4:
                grade.exibir_grade_semanal();
                return MenuGrade();

            case 5:
                return MenuPrincipal::MenuPrincipal();;

            default:
                // Opção inválida, retorne nullptr ou um menu padrão
                std::cout << "Opcao invalida!" << std::endl;
                return MenuGrade();
        }
    }
};
