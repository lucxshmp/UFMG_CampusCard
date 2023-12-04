#include "menuTransacoesRU.hpp"
#include "Transacoes.hpp"

Transacoes transacao;
Usuario usuario;
int nivel_fump =0;
double valor=0;
namespace media::ui{
/// @brief construtor com todas as opcoes do menu principal 
    MenuTransacoesRU::MenuTransacoesRU(){
        _title = "Transacoes RU";
        _options.push_back("1 - Realizar Pagamento");
        _options.push_back("2 - Realizar Deposito");
        _options.push_back("3 - Consultar Saldo");
    }

    Menu *MenuTransacoesRU::next(unsigned option) {
        switch (option) {
            case 1:
                // fazer aqui o que vc quer que o programa faça quando a pessoa apertar a opçao 2
                //exemplo se for a opção consultar data de prova chamar uma função que faça isso 
                //qualquer coisa usa o meu main menu de exemplo 
                std::cout<<"Informe o nivel fump (2 a 6): "<<std::endl;
                std::cin>>nivel_fump;
                usuario.setNivelFump(nivel_fump);
                transacao.set_pagamento(true);
                transacao.pagamento();
                return nullptr; 

            case 2:

                // fazer aqui o que vc quer que o programa faça quando a pessoa apertar a opçao 2
                //exemplo se for a opção consultar data de prova chamar uma função que faça isso 
                //qualquer coisa usa o meu main menu de exemplo
                std::cout<<"Informe valor a ser depositado: "<<std::endl;
                std::cin>>valor;   
                transacao.set_deposito(true);
                transacao.deposito(valor);
                return nullptr; 

            case 3:
                
                // fazer aqui o que vc quer que o programa faça quando a pessoa apertar a opçao 2
                //exemplo se for a opção consultar data de prova chamar uma função que faça isso 
                //qualquer coisa usa o meu main menu de exemplo    
                transacao.consultar_saldo();
                return nullptr; 
           
            default:
                // Opção inválida, retorne nullptr ou um menu padrão
                std::cout << "Opcao invalida!" << std::endl;
                return nullptr;
        }
    }
};