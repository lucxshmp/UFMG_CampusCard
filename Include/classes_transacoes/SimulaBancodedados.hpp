#ifndef SIMULABANCODEDADOS
#define SIMULABANCODEDADOS
#include <iostream>
#include <unordered_map>
#include "usuario.hpp"

class BancoDeDados {
private:
    std::unordered_map<int, double> saldos_iniciais; /* Simulação de um banco de dados com ID de usuário no formato de
    número de matrícula e saldo inicial */

public:
    BancoDeDados();
    double recupera_saldo_inicial(long int _matricula) const;
};


#endif 