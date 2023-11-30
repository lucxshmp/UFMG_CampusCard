#include "SimulaBancodedados.hpp"

/* @brief Essa classe deve funcionar como um pequeno banco de dados para possibilitar operações envolvendo saldo */

BancoDeDados::BancoDeDados() {
    // Simulação de dados do banco de dados
    saldos_iniciais = {
        {2023111111, 100.0},
        {2023222222, 100.0},
        {2023333333, 100.0},
        {2023444444, 100.0},
        {2023555555, 100.0},
        
    };
}

double BancoDeDados::recupera_saldo_inicial(long int _matricula) const {
    auto it = saldos_iniciais.find(_matricula);
    if (it != saldos_iniciais.end()) {
        return it->second; // Retorna o saldo inicial se o usuário for encontrado
    } else {
        return -1; // Retorna -1 se o usuário não for encontrado
    }
}