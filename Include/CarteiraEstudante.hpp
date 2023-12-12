#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "usuario.hpp"


class CarteiraEstudante{
public:
    CarteiraEstudante();
    
    bool obterStatusValidade() const;

    void definirStatusValidade(bool novo_status);

private:
    bool ValidadeCarteira;
};