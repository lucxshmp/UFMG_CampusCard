#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <hpdf.h>
#include "usuario.hpp"


class CarteiraEstudante {
public:
    CarteiraEstudante();

    void GerarCarteiraDigital(const char*);

    bool obterStatusValidade() const;

    void definirStatusValidade(bool novo_status);

private:
    bool ValidadeCarteira;
};