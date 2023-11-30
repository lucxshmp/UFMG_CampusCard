#include "menuOnibusVans.hpp"
#include "onibus.hpp"
#include "menuOnibus.hpp"

namespace media::ui{
/// @brief construtor com todas as opcoes do menu principal 
    MenuOnibusVans::MenuOnibusVans(){
        _title = "Transporte e locomocao";
        _options.push_back("1 - Cadastrar novo onibus");
        _options.push_back("2 - Exibir Lista dos Onibus");
        _options.push_back("3 -  ");
    }

    Menu *MenuOnibusVans::next(unsigned option) {
        switch (option) {
            case 1:
                
                onibus.cadastrarOnibus();
                onibus.exibirInformacao()
                return nullptr;
            case 2:

                onibus.exibirOnibusCadastrados();
                return MenuOnibusVans();

            case 3:
                
                // fazer aqui o que vc quer que o programa faça quando a pessoa apertar a opçao 2
                //exemplo se for a opção consultar data de prova chamar uma função que faça isso 
                //qualquer coisa usa o meu main menu de exemplo    
                std::cout << "Ate aqui deu certo\n";
                return nullptr; 
           
            default:
                // Opção inválida, retorne nullptr ou um menu padrão
                std::cout << "Opcao invalida!" << std::endl;
                return nullptr;
        }
    }
};
