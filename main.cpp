#include <iostream>
#include "..\classes_identificacao\usuario.hpp"
#include "..\classes_identificacao\login.hpp"
#include "..\classes_menu\menu.hpp"
#include "..\classes_menu\main_menu.hpp"
#include "..\classes_apoio\validacao.hpp"

int main() {
    
    namespace ui = media::ui;
    media::ui::Login login;
    media::ui::MenuPrincipal menu;
    Validacao validacao;
    Usuario user;
    
    login.renderLogin();
    login.exibirMenuLogin(user);
    std::cout << "\n";
    menu.render();

    int opcao = validacao.obterNumeroInteiro(); 

     ui::Menu *menu2 = menu.next(opcao);
    while(menu2 != nullptr){
        menu2 -> render();
        std::cin >> opcao;

        ui::Menu *old_menu = menu2;
        menu2 = menu2 -> next(opcao);
        delete old_menu;
    }
    return 0;
}