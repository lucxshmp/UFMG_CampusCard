#include "redirecionamento.hpp"
#include <iostream>
#include <cstdlib>

void Redirecionamento::redirecionarLink(const std::string& link) {
    std::cout << "Redirecionando para: " << link << "\n";
#ifdef _WIN32
    // para windows
    std::system(("start " + link).c_str());
#elif __linux__ || __APPLE__
    // para linux ou macos
    std::system(("xdg-open " + link).c_str());
#else
    std::cerr << "Sistema operacional nao suportado." << std::endl;
#endif
}
