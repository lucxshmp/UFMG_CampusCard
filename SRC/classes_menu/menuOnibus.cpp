#include "menuTransporte.hpp"
#include "onibus.hpp"
#include "menuOnibus.hpp"
#include "menuVans.hpp"

namespace media{
  namespace ui {
/// @brief construtor com todas as opcoes do menu principal 
    MenuOnibus::MenuOnibus() {
        _title = "MENU ONIBUS";
        std::cout<<  "Escolha uma opção: \n";  
        _options.push_back("1. Cadastrar ônibus");
        _options.push_back("2. Exibir ônibus cadastrados");
        _options.push_back("3. Editar ônibus");
        std::cout << "> ";
    }

    Menu *MenuOnibus::next(unsigned option) {
      Onibus meuOnibus;
        switch (option) {
            case 1:
                  meuOnibus.cadastrarOnibus();
                  meuOnibus.exibirInformacao();
              return new MenuOnibus();

            case 2:

              meuOnibus.exibirOnibusCadastrados();
              return new MenuOnibus();

          case 3:
          std::cin.ignore();  // Limpa o buffer de entrada
          meuOnibus.editarOnibus();
          return new MenuOnibus(); 

            case 0:
            std::cout << "Saindo..." << std::endl;
              return nullptr;
            break;

            default:
                std::cout << "Opcao invalida!" << std::endl;
              return nullptr;
        }
    }
  }
};

