#include "menuCarteirinha.hpp"
#include "CarteiraEstudante.hpp"
#include "interface.hpp"

namespace media::ui{
/// @brief construtor com todas as opcoes do menu principal 
    MenuCarteirinha::MenuCarteirinha(){
        _title = "Operacoes com a Carteirinha";
        _options.push_back("1 - Gerar Carteirinha Digital");
        _options.push_back("2 - Verificar Validade da Carteirinha Fisica");
        _options.push_back("3 - Invalidar Carteirinha Fisica");
    }

    Menu *MenuCarteirinha::next(unsigned option){
        media::ui::MenuCarteirinha carteirinha;
        do {
        switch (option){

            ccase 0:
                Interface interface;
                interface.mensagemSaida();
                return nullptr;

            case 1:
                const char* novaCarteirinhaDigi;
                CarteiraEstudante::GerarCarteiraDigital(novaCarteirinhaDigi); 
                std::cout << "Carteirinha Digital criada com sucesso!\n";
                return new MenuCarteirinha(); 

            case 2:
                bool validadeAtual;
                validadeAtual = CarteiraEstudante::obterStatusValidade();  
                std::cout << "A validade da carteirinha fisica e: " << (validadeAtual ? "valida" : "invalida") << std::endl;
                return new MenuCarteirinha();

            case 3:
                std::cout << "Digite 0 para invalidar a carteirinha ou 1 para validá-la\n";
                bool novo_status;
                std::cin >> novo_status; 
                
                if (novo_status != 1 && novo_status != 0){
                    while (novo_status != 1 && novo_status != 0){
                        std::cout <<"Valor invalido, tente novamente:\n";
                        std::cout << "Digite 0 para invalidar a carteirinha ou 1 para validá-la\n";
                        std::cin >> novo_status;
                    }   
                }
                
                if (novo_status == 1 || novo_status == 0){
                    CarteiraEstudante::definirStatusValidade(novo_status);
                    std::cout << "Status alterado com sucesso\n";
                }
                
                return new MenuCarteirinha(); 

            default:
                // Opção inválida, retorna nullptr para passar na compilaçao
                std::cout << "Opcao invalida! Digite novamente:\n" << std::endl;
                std::cin >> option;  // leia novamente a entrada
                return nullptr;
        }
        }while (option < 0 || option > 3);
    }
};
