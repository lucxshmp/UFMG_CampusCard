#include "menu.hpp"
#include "login.hpp"
#include <iostream>
#include "main_menu.hpp"

namespace media::ui {
    
    void Login::renderLogin(){
        std::string boasVindas = "Bem-vinde ao UFMG Campus Card";
        std::string margem(sizeof(boasVindas)+ 5, '=');
        std::cout << margem << '\n';
        std::cout << "|| " << boasVindas << " ||" << '\n';
        std::cout << margem << "\n\n";
    }
    void Login::exibirMenuLogin(Usuario& usuario) {
        int opcao;
        do {
            std::cout << "Menu de Login\n";
            std::cout << "1. Cadastrar\n";
            std::cout << "2. Sair\n";
            std::cout << "Escolha a opcao: ";
            std::cin >> opcao;

            switch (opcao) {
                case 1: {
                    long int matricula;
                    std::string nome, curso, email, endereco;
                    int fump;
                    long long int cpf;

                    std::cout << "Matricula: ";
                    std::cin >> matricula;
                    usuario.setMatricula(matricula);

                    std::cout << "Nome: ";
                    std::cin.ignore();
                    std::getline(std::cin, nome);
                    usuario.setNome(nome);

                    std::cout << "Curso: ";
                    std::getline(std::cin, curso);
                    usuario.setCurso(curso);

                    std::cout << "Email: ";
                    std::cin >> email;
                    usuario.setEmail(email);

                    std::cout << "Nivel FUMP: ";
                    std::cin >> fump;
                    usuario.setNivelFump(fump);

                    std::cout << "CPF: ";
                    std::cin >> cpf;
                    usuario.setCPF(cpf);

                    std::cout << "Endereco: ";
                    std::cin.ignore();
                    std::getline(std::cin, endereco);
                    usuario.setEndereco(endereco);

                    std::cout << "Cadastro realizado com sucesso!\n";
                    opcao = 2;
                    break;
                }

                case 2:
                    std::cout << "Saindo do programa.\n";
                    break;

                default:
                    std::cout << "Opcao invalida. Tente novamente.\n";
            }

        } while (opcao != 2);
    }

}