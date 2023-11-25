#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip> 
#include <cstdlib>  // Para a função system
#include <limits>


    //classe em que se cadastra uma disciplina no quadro semanal
    class Rotina{

        private:
            ///@brief: constructor de dados da rotina           

            // Definição da estrutura Horario
            struct Horario {
                int _dia;
                int _hora;
                Horario() : _dia(0), _hora(0) {}

                };

            // Definição da estrutura Disciplina
            struct Disciplina {
                std::string _codigo;
                std::string _nome;
                std::string _predio;
                std::string _sala;
                std::vector<Horario> horarios;
            };

            std::vector<Disciplina> disciplinas;

        public:

            ///@brief cadastra e associa as disciplina a informações
            ///@param associa a disciplina a um vetor de mesmo nome
            void cadastrarDisciplina();
            void editar_disciplina();
            void informacoes_disciplina();
            std::string transformarEmDia(int dia);
            std::string transformarEmHora(int hora);
            bool existeDisciplinaNoHorario(int dia, int hora) const;
            void cadastrarHorarios(Horario &novoHorario);
            void cadastrarDetalhes(Disciplina &novadisciplina);

    };

