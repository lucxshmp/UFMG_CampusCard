#include "validação.hpp"
#include "rotina.hpp"

    //confere se o usuário digitou s/n ou S/N
    char Validacao::validarSN(char escolha){

        //loop para valor digitado incorreto
        while (!(escolha == 'S' || escolha == 's' || escolha == 'N' || escolha == 'n')) {
            std::cout << "Escolha um valor válido (S/N): ";
            std::cin >> escolha;
        }

        return escolha;

    }


    int Validacao::validarNumero(int escolha){

        //loop
        while (true){
            std::cout << "Escolha uma opção válida: ";
            std::cin >> escolha;

            if(std::cin.fail() || escolha < 1 || escolha > 5){

                // Limpar o estado de erro
                std::cin.clear();

                // Descartar entrada inválida
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Entrada inválida. Digite um número entre 1 e 5." << std::endl;

            }else{
                break;
            }
        }

    return escolha;

    }

    //confere se o número digitado corresponde aos dias da semana
    int Validacao::validarDia(int escolha){

    //loop
    while (std::cin.fail() || escolha < 1 || escolha > 6){
        std::cout << "Entrada inválida. Digite um número entre 1 e 6: ";
        std::cin >> escolha;

        if (std::cin.fail()) {

            // Limpar o estado de erro
            std::cin.clear();

            // Descartar entrada inválida
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return escolha;
}

    //confere se o número digitado corresponde aos horários do noturno
    int Validacao::validarHorario(int escolha){ 
        while (std::cin.fail() || escolha < 1 || escolha > 2) {
            std::cout << "Entrada inválida. Digite um número entre 1 e 2: ";
            std::cin >> escolha;

            if (std::cin.fail()) {
                // Limpar o estado de erro
                std::cin.clear();
                // Descartar entrada inválida
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        return escolha;
    }

    //transforma os números em dias da semana por extenso
    std::string Validacao::transformarEmDia(int dia){

        /*switch que retorna um valor correspondente ao 
        número pré selecionado a um dia da semana */
        switch (dia) {
            case 1:
                return "Segunda";
            case 2:
                return "Terça";
            case 3:
                return "Quarta";
            case 4:
                return "Quinta";
            case 5:
                return "Sexta";
            case 6:
                return "Sábado";
            default:
                return "Dia inválido";
        }
    }

    //transforma os números em horário por extenso
    std::string Validacao::transformarEmHora(int hora){

        /*switch que retorna um valor correspondente ao 
        número pré selecionado a um horário do turno
        noturno da universidade UFMG */
        switch (hora) {
            case 1:
                return "19:00 a 20:40";
            case 2:
                return "20:55 a 22:25";
            default:
                return "Hórario inválido";
        }
    }
