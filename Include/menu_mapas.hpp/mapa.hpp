#ifndef MAPA_HPP
#define MAPA_HPP

#include <string>
#include <iostream>

class Mapa {
private:
    std::string link;

public:
    Mapa(const std::string& link);

    void exibirMapa() const;
};

#endif // MAPA_HPP
