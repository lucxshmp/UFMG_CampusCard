#pragma once

#include <iostream>

    class Interface{
        public:
        
        /**
        * @brief função que imprime um quadro para cada sessão
        * @param sessao nome da sessao
        */
        void tituloSessao(const std::string& sessao) const;

        /**
        * @brief função que imprime uma mensagem de sáida/fim do programa
        */
        void mensagemSaida();
        
    };