#pragma once

#include <string>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <vector>

class Onibus{

    private:

        //informações do onibus
        int linha;
        int placa;
        int marca;
        int tipo;

    public:

        /**
         * @brief função que permite editar as tarefas
         * @param tarefas vetor dos dados das tarefas
         */
        void cadastrarOnibus();

        /**
         * @brief função que exibe o onibus cadastrado
         */
        void exibirInformacao();

        /**
         * @brief função que exibe a lista de onibus cadastrados
         */
        void exibirOnibusCadastrados();

        /**
         * @brief função que que permite editar adicionar disciplinas em um vetor
         * @param tarefas vetor dos dados das tarefas
         */

        void editarOnibus();

        
};