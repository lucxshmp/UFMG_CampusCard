#include "SimulaBancodedados.hpp"

/* @brief Essa classe deve funcionar como um pequeno banco de dados para possibilitar operações envolvendo saldo */
Usuario usuario;
BancoDeDados::BancoDeDados() {
    // Simulação de dados do banco de dados com as matriculas 2023000000, 2023000001, 2023000002, 2023000003, 2023000004.
    long int matricula = usuario.getMatricula();
    saldos_iniciais = {
        {matricula, 100.0},
        {matricula + 1, 100.0},
        {matricula + 2, 100.0},
        {matricula +3, 100.0},
        {matricula +4, 100.0},

        
        
    };
}

double BancoDeDados::recupera_saldo_inicial(long int _matricula) const {

    auto it = saldos_iniciais.find(_matricula);
    if (it != saldos_iniciais.end()) {
        return it->second; // Retorna o saldo inicial se o usuário for encontrado

    } else {
        std::cout<<"usuario nao encontrado"<<std::endl;
    }