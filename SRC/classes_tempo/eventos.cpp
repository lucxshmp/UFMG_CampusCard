#include "eventos.hpp"
#include "validação.hpp"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>

    //função que adiciona uma tarefa ao vetor tarefas
    void Eventos::adicionarTarefas(std::vector<Eventos>& tarefas){

        Validacao validacao;
        
        //auxiliar do loop
        char cadastrarMaisTarefas;

        //loop para se cadastrar mais de uma tarefa
        do {

            //inserir dados as tarefas
            std::cout << "Digite o nome da tarefa: ";
            std::getline(std::cin, _nome);

            std::cout << "Digite a descrição da tarefa: ";
            std::getline(std::cin, _descricao);

            std::cout << "Digite a data de vencimento da tarefa (formato: DD-MM-AAAA): ";
            std::getline(std::cin, _data);

            std::cout << "Digite a hora de vencimento da tarefa (formato: HH:MM): ";
            std::getline(std::cin, _hora);

            std::cout << "Digite a disciplina da tarefa: ";
            std::getline(std::cin, _disciplina);

            deadline = parseDateTime(_data, _hora);

            //adicionar tarefa ao vetor
            tarefas.push_back(*this);

            // opção de cadastro de mais tarefas
            std::cout << "Deseja cadastrar mais tarefas? (S para sim, qualquer outra tecla para não): ";
            std::cin >> cadastrarMaisTarefas;
            validacao.validarSN(cadastrarMaisTarefas);
            std::cin.ignore(); // Limpa o buffer de entrada

        //condição de parada do loop
        } while (cadastrarMaisTarefas == 'S' || cadastrarMaisTarefas == 's');
    }

    //função que ordena a exibição da lista por prazo
    void Eventos::exibirPorPrazo(const std::vector<Eventos>& tarefas){ 

        //copia o vetor
        std::vector<Eventos> tarefasCopia = tarefas;  

        //organiza a cópia por prazo
        std::sort(tarefasCopia.begin(), tarefasCopia.end()); 

        //chama a função que imprime
        std::cout << "\nLista de Tarefas Ordenadas por Prazo:\n";
        for (const auto& tarefas : tarefasCopia) {
            tarefas.displayTarefa();
        }
    }

    //função que imprime a lista
    void Eventos::displayTarefa() const {
        auto tempoRestante = tempo();

        std::cout << "Tarefa: " << _nome << "\n"
                  << "Descrição: " << _descricao << "\n"
                  << "Disciplina: " << _disciplina << "\n"
                  << "Prazo: ";

        //analisa se o prazo já venceu
        if (tempoRestante.first < 0) {
            std::cout << "Prazo Vencido\n";
        } else {
            std::cout << tempoRestante.first << " dias e " << tempoRestante.second << " horas\n";
        }
        std::cout << "-----------------------------------" << std::endl;
    }

    //função que permite a possibilidade de editar tarefas
    void Eventos::editarTarefas(std::vector<Eventos>& tarefas) {
        
        Validacao validacao;

        //tarefas com index
        int tarefaIndex = 0;

        //auxiliar no loop
        char realizarAlteracao ='\n';

        //loop que permite mais edições
        do{

            std::cout << "Escolha o número correspondente para alterar a tarefa" << std::endl;

            //lista todas as tarefas cadastradas
            for (int i = 0; i < tarefas.size(); i++) {
                std::cout << "Digite " << i + 1 << " para editar: " << tarefas[i]._nome << std::endl;
            }

            tarefaIndex = validacao.validarNumero(tarefaIndex);

            //levar o indíce a zero
            tarefaIndex--;

            //analise do indíce
            if (tarefaIndex >= 0 && tarefaIndex < tarefas.size()) {
                
                std::cout << "Escolha o atributo a ser editado:\n"
                          << "1. Nome\n"
                          << "2. Descrição\n"
                          << "3. Data\n"
                          << "4. Hora\n"
                          << "5. Disciplina\n"
                          << "Escolha: ";

                int escolha = 0;
                escolha = validacao.validarNumero(escolha);
                std::cin.ignore(); // Limpar o buffer de entrada

                //switch que altera o desejado pelo usuário
                switch (escolha) {
                    case 1:
                        std::cout << "Digite o novo nome: ";
                        std::getline(std::cin, tarefas[tarefaIndex]._nome);
                        break;
                    case 2:
                        std::cout << "Digite a nova descrição: ";
                        std::getline(std::cin, tarefas[tarefaIndex]._descricao);
                        break;
                case 3:
                    std::cout << "Digite a nova data (formato: DD-MM-AAAA): ";
                    std::getline(std::cin, tarefas[tarefaIndex]._data);
                    // Recalcular o prazo após alterar a data
                    tarefas[tarefaIndex].deadline = parseDateTime(tarefas[tarefaIndex]._data, tarefas[tarefaIndex]._hora);
                    break;
                case 4:
                    std::cout << "Digite a nova hora (formato: HH:MM): ";
                    std::getline(std::cin, tarefas[tarefaIndex]._hora);
                    // Recalcular o prazo após alterar a hora
                    tarefas[tarefaIndex].deadline = parseDateTime(tarefas[tarefaIndex]._data, tarefas[tarefaIndex]._hora);
                    break;
                    case 5:
                        std::cout << "Digite a nova disciplina: ";
                        std::getline(std::cin, tarefas[tarefaIndex]._disciplina);
                        break;
                    default:
                        std::cout << "Escolha inválida.\n";
                        break;
                }
            }else{
                std::cout << "Índice inválido.\n";
            }

            //possibilidade de realizar mais alterações
            std::cout << "Deseja realizar mais alterações? (S/N): " << std::endl;
            std::cin >> realizarAlteracao;
            validacao.validarSN(realizarAlteracao);


            //limpar buffer
            if(realizarAlteracao == 'S' || realizarAlteracao == 's') std::cin.ignore();

        //condição parada do loop
        }while(realizarAlteracao == 'S' || realizarAlteracao == 's');

    }

    //função que calcula o prazo
    std::pair<int, int> Eventos::tempo() const {

        //obtem o tempo atual
        auto now = std::chrono::system_clock::now();

        //subtrai o tempo cadastrado pelo atual
        auto duration = std::chrono::duration_cast<std::chrono::hours>(deadline - now);

        //converte em horas e dias
        int dias = duration.count() / 24;  
        int horas = duration.count() % 24;

        return {dias, horas};
    }

   //pperador de comparação 
    bool Eventos::operator<(const Eventos& outros) const {
        return deadline < outros.deadline;
    }

    //converter o dado cadastrado pelo usuário em tempo que pode ser realizado operações
    std::chrono::system_clock::time_point Eventos::parseDateTime(const std::string& date, const std::string& time) const {
        std::tm tm = {};
        std::istringstream dateStream(date + " " + time);
        dateStream >> std::get_time(&tm, "%d-%m-%Y %H:%M");

        auto timePoint = std::chrono::system_clock::from_time_t(std::mktime(&tm));
        return timePoint;
    }

    int main() {
        std::vector<Eventos> tarefas;
        Eventos eventos;

        // Adicionar tarefas
        eventos.adicionarTarefas(tarefas);


        // Exibir tarefas ordenadas pelo prazo
        eventos.exibirPorPrazo(tarefas);


        eventos.editarTarefas(tarefas);
        eventos.exibirPorPrazo(tarefas);


        return 0;
    }