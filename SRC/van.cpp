#include "van.hpp"  // Altere o nome do arquivo para van.hpp
#include "interface.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>

void Van::cadastrarVan() {  // Altere o nome da função
    std::cout << "> Digite a linha da van: ";
    std::getline(std::cin, linha);

    std::cout << "> Digite a placa da van: ";
    std::getline(std::cin, placa);

    std::cout << "> Digite o tipo da van sendo 'I' interno e 'E' externo: ";
    std::getline(std::cin, tipo);

    std::cout << "> Digite a marca da van (fiat, volvo...): ";
    std::getline(std::cin, marca);

    // Cadastra a van com as informações básicas
    HorarioVan horario;  // Altere o nome da estrutura
    horario.linha = linha;
    horario.placa = placa;
    horario.tipo = tipo;
    horario.marca = marca;

    do {
        std::cout << "> Digite o novo horário da van (HH:MM): ";
        std::string novoHorario;
        std::getline(std::cin, novoHorario);

        // Adiciona o novo horário à lista de horários
        horario.horarios.push_back(novoHorario);

        // Pergunta ao usuário se deseja cadastrar outro horário
        std::cout << "Deseja cadastrar outro horário para esta van? (s/n): ";
        char resposta;
        std::cin >> resposta;
        std::cin.ignore();  // Limpa o buffer de entrada

        if (resposta != 's' && resposta != 'S') {
            break;  // Sai do loop se a resposta não for 's' ou 'S'
        }

    } while (true);

    // Chama a função salvarVans para salvar as informações no arquivo
    std::vector<HorarioVan> vansCadastradasTemp = {horario};  // Altere o nome da estrutura
    salvarVans(vansCadastradasTemp);  // Altere o nome da função
}

void Van::exibirInformacao() const {
    std::cout << "Informações salvas: \n" << std::endl;
    std::cout << "Linha: " << linha << std::endl;
    std::cout << "Placa: " << placa << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Marca: " << marca << std::endl;
}

void Van::editarVan() {  // Altere o nome da função
    std::cout << "Digite a placa da van que deseja editar: ";
    std::string placaEditar;
    std::getline(std::cin, placaEditar);

    // Verifica se a placa existe no arquivo vans.txt
    std::ifstream arquivo("vans.txt");  // Altere o nome do arquivo
    std::string linha;
    bool placaEncontrada = false;

    std::vector<HorarioVan> vansCadastradas;  // Altere o nome da estrutura

    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);

        HorarioVan horario;  // Altere o nome da estrutura
        iss >> horario.linha >> horario.placa >> horario.tipo >> horario.marca;

        // Lê os horários restantes da linha
        std::string horarioStr;
        while (iss >> horarioStr) {
            horario.horarios.push_back(horarioStr);
        }

        vansCadastradas.push_back(horario);

        if (horario.placa == placaEditar) {
            placaEncontrada = true;
            break;  // Placa encontrada, não é necessário continuar a busca
        }
    }

    arquivo.close();

    if (placaEncontrada) {
        // Placa encontrada, permitir edição
        auto it = std::find_if(vansCadastradas.begin(), vansCadastradas.end(), [&placaEditar](const HorarioVan& horario) {
            return horario.placa == placaEditar;
        });

        if (it != vansCadastradas.end()) {
            // Van encontrada, permitir edição
            std::cout << "Digite as novas informações da van:" << std::endl;

            // Remove a van antiga com base na placa
            vansCadastradas.erase(it);

            // Cadastra a van novamente com as novas informações
            cadastrarVanNova(vansCadastradas);  // Altere o nome da função

            std::cout << "Van editada com sucesso!" << std::endl;
        } else {
            std::cerr << "Erro ao encontrar van com placa " << placaEditar << std::endl;
        }
    } else {
        std::cout << "Van com placa " << placaEditar << " ainda não cadastrada." << std::endl;
    }
}

void Van::exibirVansCadastradas() const {  // Altere o nome da função
    std::ifstream arquivo("vans.txt");  // Altere o nome do arquivo

    if (arquivo.is_open()) {
        std::cout << "---------------------------" << std::endl;
        std::cout << "    VANS CADASTRADAS: " << std::endl;  // Altere a mensagem
        std::cout << "---------------------------" << std::endl;

        std::string linha;
        while (std::getline(arquivo, linha)) {
            std::cout << linha << std::endl;
        }

        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo para leitura." << std::endl;
    }
}

void Van::carregarVans() {  // Altere o nome da função
    // Não é mais necessário carregar horários
}

void Van::salvarVans(const std::vector<HorarioVan>& vansCadastradas) const {  // Altere o nome da função
    std::ofstream arquivo("vans.txt");  // Altere o nome do arquivo

    if (arquivo.is_open()) {
        // Itera sobre a lista de vans cadastradas
        for (const auto& van : vansCadastradas) {  // Altere o nome da estrutura
            arquivo << "Linha: " << van.linha << " | Placa: " << van.placa << " | Tipo: " << van.tipo << " | Marca: " << van.marca;  // Altere o nome da estrutura

            // Adiciona os horários da van à linha do arquivo
            for (const auto& hora : van.horarios) {
                arquivo << " | Horário: " << hora;
            }

            arquivo << std::endl;
        }

        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
    }
}

void Van::cadastrarVanNova(const std::vector<HorarioVan>& vansCadastradas) {  // Altere o nome da função
    // Solicita as informações da nova van
    std::cout << "> Digite a linha da van: ";
    std::getline(std::cin, linha);

    std::cout << "> Digite a placa da van: ";
    std::getline(std::cin, placa);

    std::cout << "> Digite o tipo da van (I para interno, E para externo): ";
    std::getline(std::cin, tipo);

    std::cout << "> Digite a marca da van: ";
    std::getline(std::cin, marca);

    // Cria um novo objeto HorarioVan com as informações fornecidas
    HorarioVan novaVan;  // Altere o nome da estrutura
    novaVan.linha = linha;
    novaVan.placa = placa;
    novaVan.tipo = tipo;
    novaVan.marca = marca;

    // Solicita os horários da nova van
    std::cout << "> Digite os horários da nova van (separados por espaço): ";
    std::string horariosStr;
    std::getline(std::cin, horariosStr);

    std::istringstream iss(horariosStr);
    std::string horario;

    // Extrai os horários da string e adiciona à lista de horários
    while (iss >> horario) {
        novaVan.horarios.push_back(horario);
    }

    // Adiciona a nova van à lista de vans cadastradas
    std::vector<HorarioVan> vansCadastradasTemp = vansCadastradas;  // Altere o nome da estrutura
    vansCadastradasTemp.push_back(novaVan);

    // Chama a função salvarVans para salvar as informações no arquivo
    salvarVans(vansCadastradasTemp);  // Altere o nome da função
}
