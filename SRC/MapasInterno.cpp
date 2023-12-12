#include "redirecionamento.hpp"
#include "menuMapas.hpp"
#include "MapasInterno.hpp"
#include "interface.hpp"
#include <iostream>

namespace media::ui{
    
/// @brief construtor com todas as opcoes do menu  
    MapasInterno::MapasInterno(){
        _title = "Mapas da UFMG - Pontos Interno";
        _options.push_back("1 - Linha 1");
        _options.push_back("2 - Linha 2");
        _options.push_back("3 - Linha 3");
        _options.push_back("4 - Linha 3 - Atendimento BH-Tec");
        _options.push_back("5 - Linha 4");
        _options.push_back("6 - Linha 4 - Atendimento McDonalds");
        _options.push_back("7 - Linha 4 - Atendimento McDonalds e BH-Tec");
        _options.push_back("8 - Linha Sabado");
    }

    Menu *MapasInterno::next(unsigned option) {
        
        do{
        switch (option) {
            case 1:
                Redirecionamento::redirecionarLink("https://drive.google.com/file/d/1M3d3_lgyRktZz90pcj8ekznKGNTqKmRT/view?usp=sharing");
                return nullptr; 

            case 2:
                Redirecionamento::redirecionarLink("https://drive.google.com/file/d/1WgDHK03ea96Hhbru_if_Rc0zR9koYIAL/view?usp=sharing");
                return nullptr;
                 
            case 3:
                Redirecionamento::redirecionarLink("https://drive.google.com/file/d/1KJwbXhSZNrWH7TMluClw_5wCeQ2cCzsX/view?usp=sharing");
                return nullptr;

            case 4:
                Redirecionamento::redirecionarLink("https://drive.google.com/file/d/1n4kn8K9PBJAj9gtt4HshPjHtI7C9ihV4/view?usp=sharing");
                return nullptr;
                 
            case 5:
                Redirecionamento::redirecionarLink("https://drive.google.com/file/d/1HDOn3zstYrDuR2HyvI-wU6eBSjbUG5Gp/view?usp=sharing");
                return nullptr;

            case 6:
                Redirecionamento::redirecionarLink("https://drive.google.com/file/d/1SQAc54Zsahf5R-i045M4EohlWcE_uoy1/view?usp=sharing");
                return nullptr;
                 
            case 7:
                Redirecionamento::redirecionarLink("https://drive.google.com/file/d/1W-lXtkE-hjOnjnnaJ_pDzggJUZdZX1wG/view?usp=sharing");
                return nullptr;

            case 8:
                Redirecionamento::redirecionarLink("https://drive.google.com/file/d/1wp3S5OFTT_vGeqlX-SzXHW4RwCoTqkeN/view?usp=sharing");
                return nullptr;

            default:
                // Opcao invalida, retorne menu padrao
                return new MapasInterno();
        }
    } while (option != 8);
    }
};
