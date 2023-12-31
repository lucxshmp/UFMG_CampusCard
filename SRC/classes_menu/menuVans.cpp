#include "menuTransporte.hpp"
#include "van.hpp"  // Altere o nome do arquivo para van.hpp
#include "menuVans.hpp"  // Altere o nome do arquivo para menuVan.hpp

#ifdef _WIN32
    // Comando para limpar o console no Windows
    #define CLEAR_SCREEN "cls"
#else
    // Comando para limpar o console em sistemas Unix/Linux
    #define CLEAR_SCREEN "clear"
#endif

namespace media { 
  namespace ui {
    /// @brief construtor com todas as opcoes do menu principal 
        MenuVans::MenuVans(){ 
        _title = " MENU VANS";
          std::cout << "\nEscolha uma opção: \n";
        _options.push_back("1. Cadastrar van");
        _options.push_back("2. Exibir vans cadastradas");
        _options.push_back("3. Editar van");
        std::cout << "> ";
        }

        Menu *MenuVans::next(unsigned option){;
          Van minhaVan;
          int aux = 0;
          switch (option) {
            case 1:
                std::cin.ignore();
                minhaVan.cadastrarVan();
                minhaVan.exibirInformacao();
                return new MenuVans();

            case 2:
                minhaVan.exibirVansCadastradas();
                return new MenuVans();
            
            case 3:
                std::cin.ignore();
                minhaVan.editarVan();
                return nullptr;

            case 0:
                    ux = system(CLEAR_SCREEN);
                        if (aux == -1) {}
                    Interface interface;
                    interface.mensagemSaida();
                    return nullptr;

            default:
                // Opção inválida, retorne nullptr ou um menu padrão
                std::cout << "Opcao invalida!" << std::endl;
                return nullptr;
        }
        }
    }
  }
