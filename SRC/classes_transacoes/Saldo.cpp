/* @brief Essa classe deverá efetuar as movimentações no saldo dos alunos. 
        Para cada usuário é associado um nível de fumpista o qual confere descontos proporcionais ao nível de fumpista.
        nível 1: refeição gratuita.
        nível 2 e 3: refeição no valor de 1 real.
        nível 4: refeição no valor de 2 reais.
        nível 5: refeição no valor de 2,90 reais.
        nível 6: refeição no valor normal, de 5,60 reais. */
#include "Saldo.hpp"


Saldo::Saldo(long int _matricula, BancoDeDados &banco) : saldo_atual(banco.recupera_saldo_inicial(_matricula)) {}

void Saldo::adicionar_saldo(double valor) {
    saldo_atual += valor;
}

void Saldo::diminuir_saldo(int _fump) {
    switch (_fump){
        case 2:
            saldo_atual-= 1.0;
            break;
        case 3:
            saldo_atual-= 1.0;
            break;
        case 4:
            saldo_atual -=2.0;
            break;
        case 5:
            saldo_atual-=2.90;
            break;
        case 6:
            saldo_atual-=5.60;
            break;
    }
    
}

double Saldo::retornar_saldo_atual() const {
    return saldo_atual;
}

