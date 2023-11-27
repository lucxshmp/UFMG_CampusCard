#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip> 

    //classe que cria uma lista com todas as tarefas por ordem de data
    class Calendario{

        private:
            ///@brief: constructor de dados do calendario 
            std::string nome_tarefa;
            std::string descrição_tarefa;
            int dia;
            int mes;
            int ano;
            int semestre;
            std::string entrega;
            
        public:

            ///@brief  cria uma lista organizada a partir de um calendário
            ///@param 
            void criar_calendario(/*tempo atual*/);

            ///@brief cria uma tarefa
            ///@param 
            void criar_tarefa(std::string nome_tarefa, std::string descrição_tarefa, int dia, int mes, int ano, int semestre)
            
            ///@brief notifica o usuário da aplicação que o prazo da entrega está próximo
            ///@param 
            void notificar_entrega();

            ///@brief 
            ///@param 
            void exibir_lista();

    };
    
