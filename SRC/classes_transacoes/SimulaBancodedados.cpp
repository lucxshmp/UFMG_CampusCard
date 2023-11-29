#include "SimulaBancodedados.hpp"

/* @brief Essa classe deve funcionar como um pequeno banco de dados para possibilitar operações envolvendo saldo */

BancoDeDados::BancoDeDados() {
    // Simulação de dados do banco de dados
    saldosIniciais = {
        {1, 100.0},
        {2, 100.0},
        {3, 100.0},
        {4, 100.0},
        {5, 100.0},
        
    };
}

double BancoDeDados::recupera_saldo_inicial(int idUsuario) const {
    auto it = saldosIniciais.find(idUsuario);
    if (it != saldosIniciais.end()) {
        return it->second; // Retorna o saldo inicial se o usuário for encontrado
    } else {
        return -1; // Retorna -1 se o usuário não for encontrado
    }
}