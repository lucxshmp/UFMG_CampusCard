#include "UFMGCampusCard\Include\classes_transporte\onibus.hpp"

#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>


    //função que cadastra onibus
    void Onibus::cadastrarOnibus(int linha, int placa, int tipo) {

            //inserir dados do onibus
            std::cout << "> Digite a linha do onibus: ";
            std::getline(std::cin, linha);

            std::cout << "> Digite o numero do onibus: ";
            std::getline(std::cin, placa);

            std::cout << "> Digite o numero do onibus: ";
            std::getline(std::cin, marca);

            std::cout << "> Digite o numero do onibus: ";
            std::getline(std::cin, tipo);

        
    }

    void Onibus::exibirInformacao() const {
        std::cout << "Linha: " << linha << std::endl;
        std::cout << "Placa: " << placa << std::endl;
        std::cout << "Marca: " << marca << std::endl;
        std::cout << "Tipo: " << tipo << std::endl;
        
    }


    //função que ordena a exibição da lista por prazo
    void Onibus::exibirOnibusCadastrados(){ 

        //Criar lista forma de armazenar os onibus
      
    }

    //função que permite a possibilidade de editar tarefas
struct HorarioOnibus {
int placa;
std::chrono::system_clock::time_point horario;
};

// Função para exibir os horários dos ônibus
void exibirHorarios(const std::vector<HorarioOnibus>& horarios) {
    std::cout << "Horários dos ônibus cadastrados:" << std::endl;

    for (const auto& horario : horarios) {
        std::tm* localTime = std::localtime(&horario.horario);
        std::cout << horario.placa << ": " << std::put_time(localTime, "%H:%M:%S") << std::endl;
    }
}

// Função para permitir que o usuário informe novos horários de ônibus
void informarNovoHorario(std::vector<HorarioOnibus>& horarios) {
    std::cout << "Informe o nome do ônibus: ";
    std::string placa;
    std::cin >> placa;

    // Obtém o tempo atual
    auto tempoAtual = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    // Adiciona um novo horário à lista de horários
    horarios.push_back({placa, std::chrono::system_clock::from_time_t(tempoAtual)});

    std::cout << "Novo horário cadastrado com sucesso!" << std::endl;
}



