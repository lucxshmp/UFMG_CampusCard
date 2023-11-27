#pragma once 

#include "menu.hpp"
#include <string>

namespace media::ui {
    class MenuRotinaCalendarios : public Menu {
    public:
        ///@brief: constrói um menu principal 
        MenuRotinaCalendarios();

        /// @brief Constrói próximo menu (criação de conta ou login)
        /// @return O próximo menu, a partir da seleção do usuário.
        Menu *next(unsigned option) override;

    };
}
