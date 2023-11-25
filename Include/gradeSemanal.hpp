#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip> 
#include "rotina.hpp"


    //classe em que se cria uma grade semanal, que receberá disciplinas
    class Grade_Semanal{

        private:
            ///@brief: constructor de dados da grade semanal 
            Rotina rotina;

        public:



            void criarGrade(Rotina &rotina);

            ///@brief exibir grade por dia da semana

            ///@brief exibir grade da semana
            void exibir_grade_semanal(std::vector<std::vector<std::string>>& parametro);

    };