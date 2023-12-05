#pragma once

#include "Include\classes_menu\menuMapas.hpp"
#include "Include\classes_menu\menu.hpp"
#include <string>
#include <iostream>

namespace media::ui {
    class MapasInterno : public Menu {
    public:    
        ///@brief: constroi um menu de opções
        MapasInterno();

        ///@brief abre as opções dos usuários
        ///@return o mapa escolhido pelo usuario
        Menu *next(unsigned option) override;
    };


}
