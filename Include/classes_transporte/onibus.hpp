#pragma once

#include <string>
#include <chrono>
#include <iostream>
#include <vector>
#include <ctime>

struct HorarioOnibus {
    std::chrono::system_clock::time_point horario;
    std::string placa;
    std::tm tmObj;
    std::string tipo;

    // Construtor padrão
    HorarioOnibus() : horario(), placa(), tmObj(), tipo() {}

    // Construtor para inicializar membros diretamente
    HorarioOnibus(std::chrono::system_clock::time_point horario, const std::string& placa, const std::tm& tmObj, const std::string& tipo)
        : horario(horario), placa(placa), tmObj(tmObj), tipo(tipo) {}
};

class Onibus {
private:
    std::string linha;
    std::string placa;
    std::string marca;
    std::string tipo;
    std::string placaAtual;

    void salvarOnibus() const;
    void cadastrarOnibusNovo();

    std::string formatarOnibus(const HorarioOnibus& horario) const;

public:
    std::vector<HorarioOnibus> horarios;

    void cadastrarOnibus();
    void exibirInformacao() const;
    void exibirHorarios() const;
    void adicionarHorario();
    void editarOnibus();
    void exibirOnibusCadastrados() const;
    void carregarOnibus();

    const std::vector<HorarioOnibus>& getOnibusCadastrados() const;
};
