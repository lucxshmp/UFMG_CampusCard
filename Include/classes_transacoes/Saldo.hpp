#ifndef SALDO_HPP
#define SALDO_HPP
#include <iostream>
#include "SimulaBancodedados.hpp"
#include "usuario.hpp"

class Saldo{
    private: 
        double saldo_atual;
        

    public:
        Saldo();
        Saldo(long int _matricula, BancoDeDados &banco); 
        void diminuir_saldo(int _fump);
        void adicionar_saldo(double valor);
        double retornar_saldo_atual() const; 

};

#endif 