#include <iostream>
#include "usuario.hpp"
#include "login.hpp"
#include "menu.hpp"
#include "main_menu.hpp"

int main(){
    
    Usuario user;
    media::ui::Login login;
    login.renderLogin();
    login.exibirMenuLogin(user);
    std::cout << "\n";
    media::ui::MenuPrincipal menu;
    menu.render();
    unsigned opcao = 15; // atribui um valor aleatório 
    std::cin >> opcao;
    menu.next(opcao);
    return 0;
}