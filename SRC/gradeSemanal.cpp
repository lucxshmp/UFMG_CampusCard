#include "gradeSemanal.hpp"
#include "rotina.hpp"

    //associa os horários das disciplinas com a grade
    void Grade_Semanal::criarGrade(Rotina &rotina){

        //auxiliares para manipulção de dados
        const int colunas = 7;
        const int linhas = 4;
        std::string diaSemana[] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sabado"};
        std::string horario[] = {"19:00 a 20:40", "20:55 a 22:25"};

        std::vector<std::vector<std::string>> grade(linhas, std::vector<std::string>(colunas, ""));

        //Inicializando a matriz com travessão para espaços vazios 
        for (int i = 0; i < colunas; i++){
            for (int j = 0; j < linhas; j++){
                grade[j][i] = "-";
            }
        }

        //Inicializando a linha de cabeçalho com dias da semana
        for(int c=1; c<colunas; c++){
            grade[0][c] = diaSemana[c-1];
        }

        //Inicializando a coluna de cabeçalho com os horários
        for(int l=1; l<linhas; l++){
            grade[l][0] = horario[l-1];
        }

        //TENTATIVA DE ASSOCIAR A POSIÇAO COM A DISCIPLINA
        for (const auto& disciplina : rotina.disciplinas){
            for (const auto& horario : disciplina.horarios){
                int dia = horario._dia;
                int hora = horario._hora;

                if (dia >= 1 && dia < colunas && hora >= 1 && hora < linhas){
                    grade[hora][dia] = disciplina._nome;
                }
            }
        }

        exibir_grade_semanal(grade);
    }

    //exibir grade completa da semana
    void Grade_Semanal::exibir_grade_semanal(std::vector<std::vector<std::string>>& parametro){

        Rotina rotina;
        Rotina::Disciplina disciplina;

        //impressao da grade
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 7; j++){
                std::cout << "|" << std::setw(18) << parametro[i][j];
            }
        
        std::cout << "|" << std::endl;

        }
    }



