#pragma once 

#include "menu.hpp"
#include <string>

namespace media::ui{
    class MenuMapas : public Menu{
    public:
        ///@brief: constrói um menu principal 
        MenuMapas();

        /// @brief Constrói próximo menu (mapas dos campi ou de interno)
        /// @return O próximo menu, a partir da seleção do usuário.
        Menu *next(unsigned option) override;

    };
}
