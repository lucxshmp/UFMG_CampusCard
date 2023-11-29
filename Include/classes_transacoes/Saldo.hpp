#ifndef SALDO_HPP
#define SALDO_HPP
#include <iostream>
#include "SimulaBancodedados.hpp"

class Saldo {
    private: 
        double saldo_atual;
        int nivel_fump;

    public:
        Saldo(int idUsuario, BancoDeDados &banco); 
        void diminuir_saldo(int nivel_fump, double valor);
        void adicionar_saldo(double valor);
        double exibe_saldo() const; 


};
#endif 