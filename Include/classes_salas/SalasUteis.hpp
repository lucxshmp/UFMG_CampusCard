#pragma once

#include <string>
#include <vector>

class Sala {
public:
    std::string nome;
    std::string predio;
    std::string numero;
};

class CadastroSala {
private:
    std::vector<Sala> salas;

public:
    // Métodos para manipulação do cadastro
    void cadastrarSala(const std::string& nome, const std::string& predio, const std::string& numero);
    void exibirSalas() const;
    void salvarCadastro() const;
    void carregarCadastro();
    void alterarSala(const std::string& nome);
};
