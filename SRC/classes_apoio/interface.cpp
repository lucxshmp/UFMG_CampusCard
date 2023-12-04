#include "interface.hpp"
#include "rotina.hpp"

void Interface::mensagemSaida(){
    std::cout << std::endl;
    std::cout << "-⎽_⎽-⎻⎺⎺⎻-⎽_⎽--⎻⎺⎺⎻--⎽_⎽-⎻⎺⎺⎻-⎽_⎽--⎻⎺⎺⎻-" << std::endl;
    std::cout << " Obrigado por usar O UFMG:CampusCard!" << std::endl;
    std::cout << "-⎽_⎽-⎻⎺⎺⎻-⎽_⎽--⎻⎺⎺⎻--⎽_⎽-⎻⎺⎺⎻-⎽_⎽--⎻⎺⎺⎻-" << std::endl;
    std::cout << std::endl;
    std::cout << "•´¨`•.¸¸.•´¨`•.¸¸.•´¨`•.¸¸.•´¨`•.¸¸.•" << std::endl;
    std::cout << "            Volte Sempre!            " << std::endl;
    std::cout << "•´¨`•.¸¸.•´¨`•.¸¸.•´¨`•.¸¸.•´¨`•.¸¸.•" << std::endl; 
}

//imprimir título sessão
void Interface::tituloSessao(const std::string& sessao) const{

    const int larguraTotal = 40;  
    const int larguraTitulo = sessao.length();  

    std::cout << std::endl;

    std::cout << std::setw(larguraTotal) << std::setfill('*') << "" << std::endl;

    std::cout << std::setw(larguraTotal) << std::setfill(' ') << "" << std::endl;

    //centralizar título 
    int espacosAntes = (larguraTotal - larguraTitulo) / 2;
    int espacosDepois = larguraTotal - larguraTitulo - espacosAntes;
    std::cout << std::setw(espacosAntes) << std::setfill(' ') << "" << sessao
              << std::setw(espacosDepois) << std::setfill(' ') << "" << std::endl;

    std::cout << std::setw(larguraTotal) << std::setfill(' ') << "" << std::endl;

    std::cout << std::setw(larguraTotal) << std::setfill('*') << "" << std::endl;

    std::cout << std::endl;
}