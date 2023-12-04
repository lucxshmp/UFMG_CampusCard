#pragma once

#include <string>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <vector>

class Eventos{

    private:

        //informações das tarefas
        std::string _nome;
        std::string _descricao;
        std::string _data;
        std::string _hora;
        std::string _disciplina;
        std::chrono::system_clock::time_point deadline;

        /**
         * @brief Função que converte uma string de data e hora 
         * @param _data recebe a data da tarefa cadastrado na tarefa
         * @param _hora recebe a hora da tarefa cadastrado na tarefa
         * @return um time-point
         */
        std::chrono::system_clock::time_point parseDateTime(const std::string& _data, const std::string& _hora) const;

    public:

        /**
         * @brief função que permite editar as tarefas
         * @param tarefas vetor dos dados das tarefas
         */
        void editarTarefas(std::vector<Eventos>& tarefas);

        /**
         * @brief função que que permite editar adicionar disciplinas em um vetor
         * @param tarefas vetor dos dados das tarefas
         */
        void adicionarTarefas(std::vector<Eventos>& tarefas);

        /**
         * @brief função que permite exibir as informações e prazos das tarefas
         * @param tarefas vetor dos dados das tarefas
         */
        void exibirPorPrazo(const std::vector<Eventos>& tarefas);

        /**
         * @brief função responsável pela impressão da lista
         */
        void displayTarefa() const;

        /**
         * @brief função que calcula o tempo restante até o prazo da tarefa 
         * @return o resultado em dias e horas.
         */
        std::pair<int, int> tempo() const;

        /**
         * @brief operador que compara a tarefa com o prazo
         * @param tarefas vetor dos dados das tarefas
         */
        bool operator<(const Eventos& outros) const;

        
        /**
        * @brief função que salva a tarefas cadastrada em um arquivo
        * @param nomeArquivo nome do arquivo em que os dados serão salvos
        * @param tarefas vector com todas as tarefas
        */
        void salvarTarefasEmArquivo(const std::vector<Eventos>& tarefas, const std::string& nomeArquivo);
        
        /**
        * @brief função que salva a tarefas cadastrada em um arquivo
        * @param nomeArquivo nome do arquivo em que os dados serão salvos
        * @param tarefas vector com todas as tarefas
        */
        void carregarTarefasDeArquivo(std::vector<Eventos>& tarefas, const std::string& nomeArquivo);

        /**
        * @brief funções set para alterar o parâmetro privado
        * @param nome item privado refrente ao nome da tarefa
        * @param data item privado refrente a data da tarefa
        * @param descricao item privado refrente a descrição da tarefa
        * @param hora item privado refrente a hora da tarefa
        * @param disciplina item privado refrente a disciplina da tarefa
        */   
        void setNome(const std::string& nome);
        void setDescricao(const std::string& descricao);
        void setData(const std::string& data);
        void setHora(const std::string& hora);
        void setDisciplina(const std::string& disciplina);

        /**
        * @brief funções get obtem o parâmetro privado
        * @return o item privado desejado
        */
        std::string getNome() const;
        std::string getDescricao() const;
        std::string getData() const;
        std::string getHora() const;
        std::string getDisciplina() const;

};
