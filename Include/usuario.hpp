#pragma once 

#include <iostream> 
#include <string> 
#include <vector> 


class usuario {
private: 
    ///@brief: constructor de dados de cada aluno 
    long int matricula;
    
    std::string nome;

    std::string curso; 

    std::string email; 

    int fump; 

    char cpf[11];

    std::string endereço;


public:
    ///@brief: função de login do aplicativo 
    void login(long int matricula, char cpf[]){
    } 

};
