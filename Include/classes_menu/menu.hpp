#pragma once

#include <string> 
#include <vector> 
#include "..\classes_identificacao\usuario.hpp"

namespace media::ui{
    class Menu{
    public: 
        /// @brief Destrutor virtual, para correta destruição de subclasses.
        virtual ~Menu() = default;

        /// @brief Renderiza as opções do menu.
        virtual void render() const;
        
        /// @return O próximo menu, a partir da seleção do usuário.
        virtual Menu *next(unsigned option) = 0;

    protected:
        std::string _title = "Menu Principal";
        std::vector<std::string> _options = {"0 - Sair"};
    };
};