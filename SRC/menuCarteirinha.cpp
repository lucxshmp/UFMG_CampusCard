#include "menuCarteirinha.hpp"
#include "CarteiraEstudante.hpp"
#include "interface.hpp"

#ifdef _WIN32
    // Comando para limpar o console no Windows
    #define CLEAR_SCREEN "cls"
#else
    // Comando para limpar o console em sistemas Unix/Linux
    #define CLEAR_SCREEN "clear"
#endif 

namespace media::ui{
/// @brief construtor com todas as opcoes do menu principal 
    MenuCarteirinha::MenuCarteirinha(){
        _title = "Operacoes com a Carteirinha";
        _options.push_back("1 - Gerar Carteirinha Digital");
        _options.push_back("2 - Verificar Validade da Carteirinha Fisica");
        _options.push_back("3 - Invalidar Carteirinha Fisica");
    }

   Menu *MenuCarteirinha::next(unsigned option) {
        static CarteiraEstudante carteiraEstudante;  // Declaração da instância como estática

        do {
            switch (option) {
                case 0:
                    Interface interface;
                    interface.mensagemSaida();
                    return nullptr;

                case 1:
                    bool validadeAtual;
                    validadeAtual = carteiraEstudante.obterStatusValidade();
                    std::cout << "A validade da carteirinha fisica e: " << (validadeAtual ? "valida" : "invalida") << std::endl;
                    return new MenuCarteirinha();

                case 2:
                    std::cout << "Digite 0 para invalidar a carteirinha ou 1 para validá-la\n";
                    bool novo_status;
                    std::cin >> novo_status;

                    if (novo_status != 1 && novo_status != 0) {
                        while (novo_status != 1 && novo_status != 0) {
                            std::cout <<"Valor invalido, tente novamente:\n";
                            std::cout << "Digite 0 para invalidar a carteirinha ou 1 para validá-la\n";
                            std::cin >> novo_status;
                        }   
                    }

                    if (novo_status == 1 || novo_status == 0) {
                        carteiraEstudante.definirStatusValidade(novo_status);
                        std::cout << "Status alterado com sucesso\n";
                    }

                    return new MenuCarteirinha();

                default:
                    // Opção inválida, retorna nullptr para passar na compilação
                    std::cout << "Opcao invalida! Digite novamente:\n" << std::endl;
                    std::cin >> option;  // leia novamente a entrada
                    return nullptr;
            }
        } while (option < 0 || option > 2);
    }
};