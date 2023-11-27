#include "menuRotinaCalendarios.hpp"


namespace media::ui{
/// @brief construtor com todas as opcoes do menu principal 
    MenuRotinaCalendarios::MenuRotinaCalendarios(){
        _title = "Rotina e Calendario";
        _options.push_back("1 - marcar hora");
        _options.push_back("2 - consultar data");
        _options.push_back("3 - sei la ");
    }

    Menu *MenuRotinaCalendarios::next(unsigned option) {
        switch (option) {
            case 1:
                
                // fazer aqui o que vc quer que o programa faça quando a pessoa apertar a opçao 2
                //exemplo se for a opção consultar data de prova chamar uma função que faça isso 
                //qualquer coisa usa o meu main menu de exemplo    
                std::cout << "Ate aqui deu certo\n";
                return nullptr; 

            case 2:

                // fazer aqui o que vc quer que o programa faça quando a pessoa apertar a opçao 2
                //exemplo se for a opção consultar data de prova chamar uma função que faça isso 
                //qualquer coisa usa o meu main menu de exemplo    
                std::cout << "Ate aqui deu certo\n";
                return nullptr; 

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
