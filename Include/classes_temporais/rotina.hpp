#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip> 
#include <limits>


    //classe em que se cadastra uma disciplina no quadro semanal
    class Rotina{

        private:
            ///@brief: constructor de dados da rotina           

            // Definição da estrutura Horario
            struct Horario {
                int _dia;
                int _hora;

                //construtor que inicaliza com 0
                Horario() : _dia(0), _hora(0) {}

                };

            // Definição da estrutura Disciplina
            struct Disciplina {
                std::string _nome;
                std::string _codigo;
                std::string _predio;
                std::string _sala;
                std::vector<Horario> horarios;

                //construtor que inicializa com 0
                Disciplina() : _nome("0"), _codigo("0"), _predio("0"), _sala("0") {}
            }; 

            //criação vetor do struct disciplina
            std::vector<Disciplina> disciplinas;

        public:


            /**
             * @brief função que permite que classes selecionadas acessem o vetor disciplina
             * @return retorna o vetor privado
             */
            const std::vector<Disciplina>& getDisciplinas() const;

            /**
             * @brief função que adiciona disciplinas ao vetor
             */
            void cadastrarDisciplina();

            /**
             * @brief função que permite alterar valores dos dados da disciplina
             */
            void editar_disciplina();

            /**
             * @brief função que exibe as informações de disciplina
             */
            void informacoes_disciplina();

            /**
             * @brief função que altera o valor digitado em inteiro para um char correspondente ao dia da semana
             * @param dia recebe o inteiro digitado associado ao dia
             * @return retorna o dia associado ao número
             */
            std::string transformarEmDia(int dia);

            /**
             * @brief função que altera o valor digitado em inteiro para um char correspondente ao horario
             * @param hora recebe o inteiro digitado associado ao horario
             * @return retorna o horario associado ao número
             */
            std::string transformarEmHora(int hora);

            /**
             * @brief função que permite a consulta se há uma disciplina cadastrada em um dia e hora
             * @param hora inteiro associado ao horario
             * @param dia inteiro associado ao dia da semana
             * @return retorna verdadeiro se há uma disciplina cadastrada no horário
             * @return retorna false se não há disciplina cadastrada no horário
             */
            bool existeDisciplinaNoHorario(int dia, int hora) const;

            /**
             * @brief função que cadastra os horarios das disciplinas
             * @param novoHorario vetor de struct
             */
            void cadastrarHorarios(Horario &novoHorario);

            /**
             * @brief função que cadastra as informações das disciplinas
             * @param novoDisciplina vetor de struct
             */
            void cadastrarDetalhes(Disciplina &novadisciplina);

    };

