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

            std::cin >> escolha;

            if(std::cin.fail() || escolha < 1 || escolha > 5){

                // Limpar o estado de erro
                std::cin.clear();

                // Descartar entrada inválida
                std::cout << "(!) Entrada inválida\n (!) Digite um número entre 1 e 5." << std::endl;

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
            std::cout << "(!) Entrada inválida.\n (!) Digite um número entre 1 e 6: ";
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
            std::cout << "(!) Entrada inválida.\n (!) Digite 1 ou 2: ";
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

    //validar se o formato da data é DD-MM-AAAA
    bool Validacao::validarFormatoData(const std::string& data) const{
        std::tm tm = {};
        std::istringstream dateStream(data);
        dateStream >> std::get_time(&tm, "%d-%m-%Y");

        if (dateStream.fail()){
            std::cout << "(!) Entrada inválida. " << std::endl << "(!) ";
        }
        return !dateStream.fail();
    }

    //validar se o formato da hora é HH:MM
    bool Validacao::validarFormatoHora(const std::string& hora) const{
        std::tm tm = {};
        std::istringstream timeStream(hora);
        timeStream >> std::get_time(&tm, "%H:%M");

        if (timeStream.fail()){
            std::cout << "(!) Entrada inválida. " << std::endl << "(!) ";
        }
        return !timeStream.fail();
    }


//imprimir título sessão
void Validacao::tituloSessao(const std::string& sessao) const{

    const int larguraTotal = 60;  
    const int larguraTitulo = sessao.length();  

    std::cout << std::endl;

    std::cout << std::setw(larguraTotal) << std::setfill('*') << "" << std::endl;

    std::cout << std::setw(larguraTotal) << std::setfill(' ') << "" << std::endl;

    //centralizar título 
    int espacosAntes = (larguraTotal - larguraTitulo) / 2;
    int espacosDepois = larguraTotal - larguraTitulo - espacosAntes;
    std::cout << std::setw(espacosAntes) << std::setfill(' ') << "" << sessao
              << std::setw(espacosDepois) << std::setfill(' ') << "" << std::endl;

    std::cout << std::setw(larguraTotal) << std::setfill(' ') << "" << std::endl;

    std::cout << std::setw(larguraTotal) << std::setfill('*') << "" << std::endl;

    std::cout << std::endl;
}