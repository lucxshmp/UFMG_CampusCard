#include "gradeSemanal.hpp"
#include "rotina.hpp"
#include "validacao.hpp"
#include "interface.hpp"

    //associa os horários das disciplinas com a grade
    void Grade_Semanal::criarGrade(Rotina &rotina){
        
        rotina.carregarDisciplinasDeArquivo("disciplinas.txt");

        Validacao validacao;
        Interface interface;
        interface.tituloSessao("Grade de Horário");

        //auxiliares para manipulção de dados e leitura do código
        const int colunas = 7;
        const int linhas = 4;
        std::string diaSemana[] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sabado"};
        std::string horario[] = {"19:00 a 20:40", "20:55 a 22:25"};

        //criação do quadro, como um vetor de vetor
        std::vector<std::vector<std::string>> grade(linhas, std::vector<std::string>(colunas, ""));

        //Inicializando a matriz com espaço vázio
        for (int i = 0; i < colunas; i++){
            for (int j = 0; j < linhas; j++){
                grade[j][i] = " ";
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

        //associando disciplinas cadastradas aos horários correspondentes
        for (const auto& disciplina : rotina.getDisciplinas()){
            for (const auto& horario : disciplina.horarios){
                int dia = horario._dia;
                int hora = horario._hora;

                if (dia >= 1 && dia < colunas && hora >= 1 && hora < linhas){
                    grade[hora][dia] = disciplina._nome;
                }
            }
        }

        std::cout << std::endl;

        //exibição da grade
        exibir_grade_semanal(grade);

    }

    //exibir grade completa da semana
    void Grade_Semanal::exibir_grade_semanal(std::vector<std::vector<std::string>>& parametro){


        //impressao da grade
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 7; j++){
                std::cout << "|" << std::setw(21) << parametro[i][j];
            }

        std::cout << "|" << std::endl;

        }

    }
