/* @brief Essa classe deverá efetuar as movimentações no saldo dos alunos. 
        Para cada usuário é associado um nível de fumpista o qual confere descontos proporcionais ao nível de fumpista.
        nível 1: refeição gratuita.
        nível 2 e 3: refeição no valor de 1 real.
        nível 4: refeição no valor de 2 reais.
        nível 5: refeição no valor de 2,90 reais.
        nível 6: refeição no valor normal, de 5,60 reais. */
#include "Saldo.hpp"


Saldo::Saldo(int idUsuario, BancoDeDados &banco) : saldo(banco.recupera_saldo_inicial(idUsuario)) {}

void Saldo::adicionar_saldo(double valor) {
    saldo += valor;
}

void Saldo::diminuir_saldo(int nivel_fump) {
    switch (nivel_fump){
        case 2:
            saldo-= 1.0;
            break;
        case 3:
            saldo-= 1.0;
            break;
        case 4:
            saldo -=2.0;
            break;
        case 5:
            saldo-=2.90;
            break;
        case 6:
            saldo-=5.60;
            break;
    }
    
}

double Saldo::exibe_saldo() const {
    return saldo;
}