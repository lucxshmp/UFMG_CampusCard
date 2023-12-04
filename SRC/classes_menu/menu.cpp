#include "menu.hpp"
#include <iostream>

namespace media::ui {
    void Menu::render() const {
        std::string margem(_title.size() + 5, '=');
        std::cout << margem << '\n';
        std::cout << "|| " << _title << " ||" << '\n';
        std::cout << margem << "\n\n";

        for (std::string opt : _options){
            std::cout << opt << '\n';
        }
        
        std::cout << std::endl << ">> Digite sua opcao" << '\n';
    }
}; 