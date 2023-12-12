#pragma once

#include <iostream> 
#include <string> 
#include <vector> 

class Usuario{
private: 
    long int _matricula;
    std::string _nome;
    std::string _curso; 
    std::string _email; 
    int _fump; 
    long long int _cpf;
    std::string _endereco;

public:
    /// Constructor
    Usuario();

    /// Getters 
    long int getMatricula() const;
    std::string getNome() const;
    std::string getCurso() const;
    std::string getEmail() const; 
    int getNivelFump() const;
    long long int getCPF() const;
    std::string getEndereco() const;

    /// Setters
    void setMatricula(long int matricula);
    void setNome(const std::string& nome);
    void setCurso(const std::string& curso);
    void setEmail(const std::string& email);
    void setNivelFump(int fump);
    void setCPF(long long int cpf);
    void setEndereco(const std::string& endereco);
};