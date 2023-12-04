#include "menuTransporte.hpp"
#include "van.hpp"  // Altere o nome do arquivo para van.hpp
#include "menuVans.hpp"  // Altere o nome do arquivo para menuVan.hpp

namespace media::ui {
    /// @brief construtor com todas as opcoes do menu principal 
        MenuVans::MenuVans(){ {
        _title = "\n\n********** MENU VANS **********\n\n ";
        _title = "Escolha uma opção: \n";
        _options.push_back("1. Cadastrar van");
        _options.push_back("2. Exibir vans cadastradas");
        _options.push_back("3. Editar van");
        _options.push_back("0. Sair");
        std::cout << "> ";
    }

        Menu *MenuVans::next(unsigned option) {
        switch (option) {
            case 1:
                minhaVan.cadastrarVan();
                minhaVan.exibirInformacao();
                return nullptr;

            case 2:
                minhaVan.exibirVansCadastradas();
                return MenuOnibusVans();

            case 3:
                minhaVan.editarVan();
                return nullptr;

            case 0:
                std::cout << "Saindo..." << std::endl;
                break;

            default:
                // Opção inválida, retorne nullptr ou um menu padrão
                std::cout << "Opcao invalida!" << std::endl;
                return nullptr;
        }
    }
};
