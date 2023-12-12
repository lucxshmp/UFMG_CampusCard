#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include <sstream>

class Onibus{
private:
    struct HorarioOnibus{
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
    std::string placaAtual;

    std::vector<HorarioOnibus> horarios;  // Modificado para armazenar HorarioOnibus

   
public:
    
    void salvarOnibus() const;
    void cadastrarOnibusNovo();
    std::string formatarOnibus(const HorarioOnibus& horario) const;
    void salvarOnibus(const std::vector<HorarioOnibus>& onibusCadastrados) const;
    void cadastrarOnibusNovo(std::vector<HorarioOnibus> &onibusCadastrados, std::vector<HorarioOnibus>::iterator it);
    void cadastrarOnibus(); 
    void exibirInformacao() const;
    void editarOnibus();
    void exibirOnibusCadastrados() const;
    void carregarOnibus();

};
