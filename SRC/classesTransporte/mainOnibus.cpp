#include "onibus.hpp"

  int main() {
    Onibus meuOnibus;

    meuOnibus.carregarOnibus(); // Carregar dados do arquivo onibus.txt

    int opcao;

  do {

    std::cout << "\n\n********** MENU ONIBUS **********\n\n " << std::endl;
    std::cout << "Escolha uma opção:" << std::endl;
    std::cout << "1. Cadastrar ônibus" << std::endl;
    std::cout << "2. Exibir horários do ônibus " << std::endl;
    std::cout << "3. Adicionar novo horário" << std::endl;
    std::cout << "4. Exibir ônibus cadastrados" << std::endl;
    std::cout << "5. Editar ônibus" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cout << "> ";
    std::cin >> opcao;
    std::cin.ignore(); // Limpar o buffer do teclado

switch (opcao) {
        case 1: {
            meuOnibus.cadastrarOnibus();
            meuOnibus.exibirInformacao();
            break;
        }
        case 2:
            meuOnibus.exibirHorarios();
            break;
        case 3: {
            HorarioOnibus novoHorario;
            meuOnibus.cadastrarHorarios(novoHorario);
            break;
        }
        case 4:
            meuOnibus.exibirOnibusCadastrados();
            break;
        case 5:
            meuOnibus.editarOnibus();
            break;
        case 0:
            std::cout << "Saindo..." << std::endl;
            break;
        default:
            std::cout << "Opção inválida. Tente novamente." << std::endl;
        }

    } while (opcao != 0);

    return 0;
}
