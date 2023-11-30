// onibus.cpp

#include "onibus.hpp"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <chrono>

void Onibus::cadastrarOnibus() {
    std::cout << "> Digite a linha do onibus: ";
    std::getline(std::cin, linha);

    std::cout << "> Digite o numero do onibus:";
    std::getline(std::cin, placa);

    std::cout << "> Digite o tipo do onibus:";
    std::getline(std::cin, tipo);

    std::cout << "> Digite a marca do onibus:";
    std::getline(std::cin, marca);

    HorarioOnibus novoHorario;
    novoHorario.placa = placa;
    novoHorario.horario = std::chrono::system_clock::now();
    horarios.push_back(novoHorario);

    std::cout << "Novo horário cadastrado com sucesso!" << std::endl;
}

void Onibus::exibirInformacao() const {
    std::cout << "Linha: " << linha << std::endl;
    std::cout << "Placa: " << placa << std::endl;
    std::cout << "Marca: " << marca << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
}

void Onibus::exibirHorarios() {
    std::cout << "Horários dos ônibus cadastrados:" << std::endl;

    for (const auto& horario : horarios) {
        std::time_t tempoEmTimeT = std::chrono::system_clock::to_time_t(horario.horario);
        std::tm* localTime = std::localtime(&tempoEmTimeT);

        if (localTime) {
            std::cout << horario.placa << ": " << std::put_time(localTime, "%H:%M:%S") << std::endl;
        } else {
            std::cout << "Erro ao converter tempo para struct tm." << std::endl;
        }
    }
}

const std::vector<HorarioOnibus>& Onibus::getHorarios() const {
    return horarios;
}

