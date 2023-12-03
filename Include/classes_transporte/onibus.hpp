// onibus.hpp

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class Onibus {
private:
    struct HorarioOnibus {
        std::string placa;
        std::string tipo;
        std::string marca;
        std::string linha;
        std::vector<std::string> horarios;
    };

    std::string linha;
    std::string placa;
    std::string marca;
    std::string tipo;

    void salvarOnibus(const std::vector<HorarioOnibus>& onibusCadastrados) const;
    void cadastrarOnibusNovo(const std::vector<HorarioOnibus>& onibusCadastrados);

public:
    void cadastrarOnibus(); 
    void exibirInformacao() const;
    void editarOnibus();
    void exibirOnibusCadastrados() const;
    void carregarOnibus();
};
