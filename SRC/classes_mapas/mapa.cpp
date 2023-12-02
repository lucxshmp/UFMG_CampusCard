#include "mapa.hpp"
#include <iostream>
#include <cstdlib>  // Para usar a função std::system

#ifdef _WIN32
#include <Windows.h>  // Somente para sistemas Windows
#endif

Mapa::Mapa(const std::string& link) : link(link) {}

void Mapa::exibirMapa() const {
#ifdef _WIN32
    // Abre o link no navegador (Windows)
    ShellExecute(0, 0, link.c_str(), 0, 0, SW_SHOW);
#elif __linux__ || __APPLE__
    // Abre o link no navegador usando xdg-open (para Linux e macOS)
    std::system(("xdg-open " + link).c_str());
#else
    std::cerr << "Sistema operacional nao suportado." << std::endl;
#endif
}
