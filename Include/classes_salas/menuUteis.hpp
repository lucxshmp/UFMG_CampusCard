#pragma once

#include "Include\classes_menu\menu.hpp"
#include "Include\classes_menu\menuSalas.hpp"
#include <string>
#include <iostream>

namespace media::ui {
    class MenuUteis : public Menu {
    public:    
        ///@brief: constroi um menu de opcoes
        MenuUteis();

        ///@brief abre as opcoes dos usuarios
        ///@return a opcaoo escolhido pelo usuario
        Menu *next(unsigned option) override;
    };


}