#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class Van {
private:
    struct HorarioVan {
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

    void salvarVans(const std::vector<HorarioVan>& vansCadastradas) const;
    void cadastrarVanNova(const std::vector<HorarioVan>& vansCadastradas);

public:
    void cadastrarVan();
    void exibirInformacao() const;
    void editarVan();
    void exibirVansCadastradas() const;
    void carregarVans();
};