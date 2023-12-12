#include "SalasUteis.hpp"
#include <iostream>
#include <fstream>

void CadastroSala::cadastrarSala(const std::string& nome, const std::string& predio, const std::string& numero) {
    Sala novaSala;
    novaSala.nome = nome;
    novaSala.predio = predio;
    novaSala.numero = numero;

    salas.push_back(novaSala);

    std::cout << "Sala cadastrada com sucesso! Lembre de salvar o cadastro antes de encerrar o programa ;)\n";
}

void CadastroSala::exibirSalas() const {
    std::cout << "Salas Cadastradas:\n";
    for (const Sala& sala : salas) {
        std::cout << "Nome: " << sala.nome << ", Predio: " << sala.predio << ", Numero: " << sala.numero << "\n";
    }
}

void CadastroSala::salvarCadastro() const {
    std::ofstream arquivo("cadastro_salas.txt");

    if (arquivo.is_open()) {
        for (const Sala& sala : salas) {
            arquivo << sala.nome << "," << sala.predio << "," << sala.numero << "\n";
        }

        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo para escrita.\n";
    }
}

void CadastroSala::carregarCadastro() {
    std::ifstream arquivo("cadastro_salas.txt");

    if (arquivo.is_open()) {
        Sala sala;
        while (std::getline(arquivo, sala.nome, ',') &&
               std::getline(arquivo, sala.predio, ',') &&
               std::getline(arquivo, sala.numero)) {
            salas.push_back(sala);
        }

        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo para leitura.\n";
    }
}
