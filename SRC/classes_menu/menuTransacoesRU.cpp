#include "menuTransacoesRU.hpp"
#include "Transacoes.hpp"
#include "interface.hpp"

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
        do{
        switch (option) {

            case 0:
                Interface::mensagemSaida();
                return nullptr;

            case 1:
                
                std::cout<<"Informe o nivel fump (2 a 6): "<<std::endl;
                std::cin>>nivel_fump;
                usuario.setNivelFump(nivel_fump);
                transacao.set_pagamento(true);
                transacao.pagamento();
                return nullptr; 

            case 2:

                std::cout<<"Informe valor a ser depositado: "<<std::endl;
                std::cin>>valor;   
                transacao.set_deposito(true);
                transacao.deposito(valor);
                return nullptr; 

            case 3:
                    
                transacao.consultar_saldo();
                return nullptr; 
           
            default:
            
                // Opção inválida, retorna nullptr para passar na compilaçao
                std::cout << "Opcao invalida! Digite novamente:\n" << std::endl;
                std::cin >> option;  // leia novamente a entrada
                return nullptr;
        }
        } while (option < 0 || option > 3);
    }
};