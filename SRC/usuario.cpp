
#include <iostream> 
#include <string> 
#include <vector> 
#include "usuario.hpp"
#include <cstring>

///Constructor padrao 
Usuario::Usuario() {
    _matricula = 2023000000;
    _nome = "aluno"; 
    _curso = "engenharia de sistemas";
    _email = "alunoteste@ufmg.br";
    _fump = 6; 
    _cpf = 1234567890;
    _endereco = "rua dos bobos n. 0";
}

/// Getters
long int Usuario::getMatricula() const {
    return _matricula;
}

std::string Usuario::getNome() const {
    return _nome;
}

std::string Usuario::getCurso() const {
    return _curso;
}

std::string Usuario::getEmail() const {
    return _email;
}

int Usuario::getNivelFump() const {
    return _fump;
}

long long int Usuario::getCPF() const {
    return _cpf;
}

std::string Usuario::getEndereco() const {
    return _endereco;
}


/// Setters
void Usuario::setMatricula(long int matricula) {
    _matricula = matricula;
}

void Usuario::setNome(const std::string& nome) {
    _nome = nome;
}

void Usuario::setCurso(const std::string& curso) {
    _curso = curso;
}

void Usuario::setEmail(const std::string& email) {
    _email = email;
}

void Usuario::setNivelFump(int fump) {
    _fump = fump;
}

void Usuario::setCPF(long long int cpf) {
    _cpf = cpf;
}

void Usuario::setEndereco(const std::string& endereco) {
    _endereco = endereco;
}