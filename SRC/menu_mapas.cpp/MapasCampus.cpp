#include "menuMapas.hpp"
#include "mapa.hpp"
#include <iostream>


namespace media::ui{

    Mapa mapaPampulha("https://drive.google.com/file/d/1ML72QfOedus6YnM-UgALSKkp7HFLrb63/view?usp=sharing");
    Mapa mapaCentroBH("https://drive.google.com/file/d/1bF_fW7p3NQlxUp4DcKES9LxjcazGCEq6/view?usp=sharing");
    Mapa mapaMontesClaros("https://drive.google.com/file/d/1rO9XVIuv9Mv3pPTTjHwpiNAAejZNeUOH/view?usp=sharing");

/// @brief construtor com todas as opcoes do menu principal 
    MapasCampus::MapasCampus(){
        _title = "Mapas da UFMG - Campi";
        _options.push_back("1 - Campus Pampulha");
        _options.push_back("2 - Campus Centro BH");
        _options.push_back("3 - Campus Montes Claros");
    }

    Menu *MapasCampus::next(unsigned option) {
        switch (option) {
            case 1:
                mapaPampulha.exibirMapa();
                std::cout << "Abrindo no navegador...\n";
                return nullptr; 

            case 2:
                mapaCentroBH.exibirMapa();    
                std::cout << "Abrindo no navegador...\n";
                return nullptr;
                 
            case 3:
                mapaMontesClaros.exibirMapa();    
                std::cout << "Abrindo no navegador...\n";
                return nullptr;

            default:
                // Opção inválida, retorne nullptr ou um menu padrão
                std::cout << "Opcao invalida!" << std::endl;
                return nullptr;
        }
    }
};