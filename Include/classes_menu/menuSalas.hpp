#pragma once 

#include "menu.hpp"
#include <string>

namespace media::ui {
    class MenuSalas : public Menu {
    public:
        ///@brief: constroi um menu principal das salas
        MenuSalas();

        /// @brief Constroi proximo menu (salas uteis ou salas por depto)
        /// @return O proximo menu, a partir da selecao do usuario.
        Menu *next(unsigned option) override;

    };
}
