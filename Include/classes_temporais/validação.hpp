#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <sstream>
#include <iomanip>


class Validacao{
    public:

            /**
             * @brief função que confere e altera o S/N se o valor não estiver correto
             * @param escolha refere-se ao que foi digitado pelo usuário
             * @return retorna um valor válido em formato S/N
             */
            char validarSN(char escolha);

            /**
             * @brief função que confere se o que foi digitado é um inteiro, e o altera se não for
             * @param escolha refere-se ao que foi digitado pelo usuário
             * @return retorna um valor válido em formato inteiro
             */
            int validarNumero(int escolha);

            /**
             * @brief função que confere se o que foi digitado é um valor correspondente a data, se não for o altera
             * @param escolha refere-se ao que foi digitado pelo usuário
             * @return retorna um valor válido em formato inteiro e da data
             */
            int validarDia(int escolha);

            /**
             * @brief função que confere se o que foi digitado é um valor válido aos dias, se não for o altera
             * @param escolha refere-se ao que foi digitado pelo usuário
             * @return retorna um valor válido em formato inteiro
             */
            int validarHorario(int escolha);

            /**
             * @brief função que altera o valor digitado em inteiro para um char correspondente ao dia da semana
             * @param dia recebe o inteiro digitado associado ao dia
             * @return retorna o dia associado ao número
             */
            std::string transformarEmDia(int dia);

            /**
             * @brief função que altera o valor digitado em inteiro para um char correspondente ao horario
             * @param hora recebe o inteiro digitado associado ao horario
             * @return retorna o horario associado ao número
             */
            std::string transformarEmHora(int hora);

            /**
             * @brief função que confere se o formato digitado pelo usuário é DD-MM-AA
             * @param data recebe a data cadastrada
             * @return verdadeiro ou falso 
             */
            bool validarFormatoData(const std::string& data) const;

            /**
             * @brief função que confere se o formato digitado pelo usuário é HH:MM
             * @param hora recebe a hora cadastrada
             * @return verdadeiro ou falso 
             */
            bool validarFormatoHora(const std::string& hora) const;

            /**
             * @brief função que imprime um quadro para cada sessão
             * @param sessao nome da sessao
             */
            void tituloSessao(const std::string& sessao) const;


};