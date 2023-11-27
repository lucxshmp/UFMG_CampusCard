#pragma once 

#include "menu.hpp"
#include <string>
#include "menuGradeSemanal.hpp"
#include "menuMapasDepartamentos.hpp"
#include "menuOnibusVans.hpp"
#include "menuRotinaCalendarios.hpp"
#include "menuSalas.hpp"
#include "menuTransacoesRU.hpp"
#include "menuCarteirinha.hpp"


namespace media::ui {
    class MenuPrincipal : public Menu {
    public:
        ///@brief: constrói um menu principal 
        MenuPrincipal();

        /// @brief Constrói próximo menu (criação de conta ou login)
        /// @return O próximo menu, a partir da seleção do usuário.
        Menu *next(unsigned option) override;

    };
}
