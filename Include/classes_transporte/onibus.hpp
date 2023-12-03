#pragma once

#include <string>
#include <chrono>
#include <iostream>
#include <vector>
#include <ctime>

// Função para validar o formato da hora
bool validarFormatoHora(const std::string& horaStr);

struct HorarioOnibus {
    std::chrono::system_clock::time_point horario;

    std::tm tmObj;
    std::string placa;  // Adicionando o membro 'placa'
    std::string tipo;

    // Construtor padrão
    HorarioOnibus() : horario(std::chrono::system_clock::now()), tipo("") {}

};

class Onibus {
private:
    std::string linha;
    std::string placa;
    std::string marca;
    std::string tipo;
    std::string placaAtual;


    std::vector<HorarioOnibus> horarios;  // Modificado para armazenar HorarioOnibus

    void salvarOnibus() const;
    void cadastrarOnibusNovo();

    std::string formatarOnibus(const HorarioOnibus& horario) const;

public:
    void cadastrarOnibus();
    void exibirInformacao() const;
    void exibirHorarios() const;

    void cadastrarHorarios(HorarioOnibus& novoHorario);

    void editarOnibus();
    void exibirOnibusCadastrados() const;
    void carregarOnibus();

    const std::vector<HorarioOnibus>& getOnibusCadastrados() const;
};
