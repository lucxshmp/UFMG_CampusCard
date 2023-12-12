#include "menuTransacoesRU.hpp"
#include "Transacoes.hpp"
#include "interface.hpp"

#ifdef _WIN32
    // Comando para limpar o console no Windows
    #define CLEAR_SCREEN "cls"
#else
    // Comando para limpar o console em sistemas Unix/Linux
    #define CLEAR_SCREEN "clear"
#endif

Transacoes transacao;
Usuario usuarios;
int nivel_fump =0;
double valor=0;
const char* guia_pdf;
namespace media::ui {
    /// @brief construtor com todas as opcoes do menu principal 
    MenuTransacoesRU::MenuTransacoesRU(){
        _title = "Transacoes RU";
        _options.push_back("1 - Realizar Pagamento");
        _options.push_back("2 - Realizar Deposito");
        _options.push_back("3 - Consultar Saldo");
    }

    Menu *MenuTransacoesRU::next(unsigned option){
        media::ui::MenuTransacoesRU transacoesRU;
        do {
            switch (option){
                case 0:
                    Interface interface;
                    interface.mensagemSaida();
                    return nullptr;

                case 1:
                    std::cout << "Informe o nivel fump (2 a 6): " << std::endl;
                    int nivel_fump;
                    std::cin >> nivel_fump;
                    usuarios.setNivelFump(nivel_fump);
                    transacao.set_pagamento(true);
                    transacao.pagamento();
                    return nullptr;

                case 2:
                    std::cout << "Informe valor a ser depositado: " << std::endl;
                    double valor;
                    std::cin >> valor;
                    transacao.set_deposito(true);
                    transacao.deposito(valor);
                    return nullptr;

                case 3:
                    transacao.consultar_saldo();
                    return nullptr;

                default:
                    // Opção inválida, retorne nullptr ou um menu padrão
                    std::cout << "Opcao invalida!" << std::endl;
                    return nullptr;
            }
        } while (option < 0 || option > 3);
    }
};