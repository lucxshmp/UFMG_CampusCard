// onibus.hpp

#pragma once

#include <string>
#include <chrono>
#include <iostream>
#include <vector>
#include <ctime>

struct HorarioOnibus {
    std::string placa;
    std::chrono::system_clock::time_point horario;
};

class Onibus {
private:
    std::string linha;
    std::string placa;
    std::string marca;
    std::string tipo;

public:
    std::vector<HorarioOnibus> horarios;

    void cadastrarOnibus();
    void exibirInformacao() const;
    void exibirHorarios();
    const std::vector<HorarioOnibus>& getHorarios() const;
};