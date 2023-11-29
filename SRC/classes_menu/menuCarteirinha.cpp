#include "menuCarteirinha.hpp"
#include "CarteiraEstudante.hpp"

namespace media::ui{
/// @brief construtor com todas as opcoes do menu principal 
    MenuCarteirinha::MenuCarteirinha(){
        _title = "Operacoes com a Carteirinha";
        _options.push_back("1 - Gerar Carteirinha Digital");
        _options.push_back("2 - Verificar Validade da Carteirinha Fisica");
        _options.push_back("3 - Invalidar Carteirinha Fisica");
    }

    Menu *MenuCarteirinha::next(unsigned option) {
        media::ui::MenuCarteirinha carteirinha;
        switch (option) {
            case 1:
                const char* novaCarteirinhaDigi;
                CarteiraEstudante::GerarCarteiraDigital(novaCarteirinhaDigi); 
                std::cout << "Carteirinha Digital criada com sucesso!\n";
                return nullptr; 

            case 2:
                bool validadeAtual;
                validadeAtual = CarteiraEstudante::obterStatusValidade();  
                std::cout << "A validade da carteirinha fisica e: " << (validadeAtual ? "valida" : "invalida") << std::endl;
                return nullptr;

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
                
                return nullptr; 

            default:
                // Opção inválida, retorne nullptr ou um menu padrão
                std::cout << "Opcao invalida!" << std::endl;
                carteirinha.render();
                return new MenuCarteirinha();
        }
    }
};
