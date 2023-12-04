#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <sstream>
#include <iomanip> 
#include "rotina.hpp"


    //classe em que se cria uma grade semanal, que receberá disciplinas
    class Grade_Semanal{

        private:
            ///@brief: constructor de dados da grade semanal 
            Rotina rotina;

        public:
            /**
             * @brief função que cria uma grade e os associa com as disciplinas
             * @param rotina classe rotina
             */
            void criarGrade(Rotina &rotina);

            /**
             * @brief função que responsavel por imprimir a grade
             * @param parametro vetor de vetor correspondente a grade
             */
            void exibir_grade_semanal(std::vector<std::vector<std::string>>& parametro);

    };
