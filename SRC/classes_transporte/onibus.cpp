#include "onibus.hpp"

#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>

void Onibus::cadastrarOnibus() {
    std::cout << "> Digite a linha do ônibus: ";
    std::getline(std::cin, linha);

    std::cout << "> Digite a placa do ônibus: ";
    std::getline(std::cin, placa);

    std::cout << "> Digite o tipo do ônibus sendo 'I' interno e 'E' externo: ";
    std::getline(std::cin, tipo);

    std::cout << "> Digite a marca do ônibus (fiat, volvo...): ";
    std::getline(std::cin, marca);

// Cadastra o ônibus com as informações básicas
HorarioOnibus horario;
    horario.linha = linha;
    horario.placa = placa;
    horario.tipo = tipo;
    horario.marca = marca;

do {
        std::cout << "> Digite o novo horário do ônibus (HH:MM): ";
        std::string novoHorario;
        std::getline(std::cin, novoHorario);

        // Adiciona o novo horário à lista de horários
        horario.horarios.push_back(novoHorario);

        // Pergunta ao usuário se deseja cadastrar outro horário
        std::cout << "Deseja cadastrar outro horário para este ônibus? (s/n): ";
        char resposta;
        std::cin >> resposta;
        std::cin.ignore();  // Limpa o buffer de entrada

        if (resposta != 's' && resposta != 'S') {
            break;  // Sai do loop se a resposta não for 's' ou 'S'

        }
    }
}


    } while (true);

    // Chama a função salvarOnibus para salvar as informações no arquivo
    std::vector<HorarioOnibus> onibusCadastradosTemp = {horario};
    salvarOnibus(onibusCadastradosTemp);
}

// função para exibir as informaçôes após o cadastro.
void Onibus::exibirInformacao() const {
    std::cout << "Informações salvas: \n" << std::endl;
    std::cout << "Linha: " << linha << std::endl;
    std::cout << "Placa: " << placa << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Marca: " << marca << std::endl;
}

void Onibus::editarOnibus() {
    std::cout << "Digite a placa do ônibus que deseja editar: ";
    std::string placaEditar;
    std::getline(std::cin, placaEditar);

    // Verifica se a placa existe no arquivo onibus.txt
    std::ifstream arquivo("onibus.txt");
    std::string linha;
    bool placaEncontrada = false;

    std::vector<HorarioOnibus> onibusCadastrados;

    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);

        HorarioOnibus horario;
        iss >> horario.linha >> horario.placa >> horario.tipo >> horario.marca;

        // Lê os horários restantes da linha
        std::string horarioStr;
        while (iss >> horarioStr) {
            horario.horarios.push_back(horarioStr);
        }

        onibusCadastrados.push_back(horario);

        if (horario.placa == placaEditar) {
            placaEncontrada = true;
            break;  // Placa encontrada, não é necessário continuar a busca
        }
    }

    arquivo.close();

    if (placaEncontrada) {
        // Placa encontrada, permitir edição
        auto it = std::find_if(onibusCadastrados.begin(), onibusCadastrados.end(), [&placaEditar](const HorarioOnibus& horario) {
            return horario.placa == placaEditar;
        });

        if (it != onibusCadastrados.end()) {
            // Ônibus encontrado, permitir edição
            std::cout << "Digite as novas informações do ônibus:" << std::endl;

            // Remove o ônibus antigo com base na placa
            onibusCadastrados.erase(it);

            // Cadastra o ônibus novamente com as novas informações
            cadastrarOnibusNovo(onibusCadastrados);

            std::cout << "Ônibus editado com sucesso!" << std::endl;
        } else {
            std::cerr << "Erro ao encontrar ônibus com placa " << placaEditar << std::endl;
        }
    } else {
        std::cout << "Ônibus com placa " << placaEditar << " ainda não cadastrado." << std::endl;
    }
}

void Onibus::exibirOnibusCadastrados() const {

    std::ifstream arquivo("onibus.txt");

    if (arquivo.is_open()) {
        std::cout << "---------------------------" << std::endl;
        std::cout << "    ÔNIBUS CADASTRADOS: " << std::endl;
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

void Onibus::carregarOnibus() {
    // Não é mais necessário carregar horários
}

void Onibus::salvarOnibus(const std::vector<HorarioOnibus>& onibusCadastrados) const {
    std::ofstream arquivo("onibus.txt");

    if (arquivo.is_open()) {
        // Itera sobre a lista de ônibus cadastrados
        for (const auto& onibus : onibusCadastrados) {
            arquivo << "Linha: "<< onibus.linha << " | Placa: " << onibus.placa << " | Tipo: " << onibus.tipo << " | Marca: " << onibus.marca;

            // Adiciona os horários do ônibus à linha do arquivo
            for (const auto& hora : onibus.horarios) {
                arquivo << " | Horário: " << hora;
            }

            arquivo << std::endl;
        }

        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
    }
}

void Onibus::cadastrarOnibusNovo(const std::vector<HorarioOnibus>& onibusCadastrados) {
    // Solicita as informações do novo ônibus
    std::cout << "> Digite a linha do ônibus: ";
    std::getline(std::cin, linha);

    std::cout << "> Digite a placa do ônibus: ";
    std::getline(std::cin, placa);

    std::cout << "> Digite o tipo do ônibus (I para interno, E para externo): ";
    std::getline(std::cin, tipo);

    std::cout << "> Digite a marca do ônibus: ";
    std::getline(std::cin, marca);

    // Cria um novo objeto HorarioOnibus com as informações fornecidas
    HorarioOnibus novoOnibus;
    novoOnibus.linha = linha;
    novoOnibus.placa = placa;
    novoOnibus.tipo = tipo;
    novoOnibus.marca = marca;

    // Solicita os horários do novo ônibus
    std::cout << "> Digite os horários do novo ônibus (separados por espaço): ";
    std::string horariosStr;
    std::getline(std::cin, horariosStr);

    std::istringstream iss(horariosStr);
    std::string horario;

    // Extrai os horários da string e adiciona à lista de horários
    while (iss >> horario) {
        novoOnibus.horarios.push_back(horario);
    }

    // Adiciona o novo ônibus à lista de ônibus cadastrados
    std::vector<HorarioOnibus> onibusCadastradosTemp = onibusCadastrados;
    onibusCadastradosTemp.push_back(novoOnibus);

    // Chama a função salvarOnibus para salvar as informações no arquivo
    salvarOnibus(onibusCadastradosTemp);
}
