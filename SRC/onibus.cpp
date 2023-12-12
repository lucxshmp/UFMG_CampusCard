#include "onibus.hpp"

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>

void Onibus::cadastrarOnibus() {
  std::cout << "> Digite a linha do ônibus: ";
  std::cin.ignore(); // Limpa o buffer de entrada
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
    std::cin.ignore(); // Limpa o buffer de entrada

    if (resposta != 's' && resposta != 'S') {
      break; // Sai do loop se a resposta não for 's' ou 'S'
    }

  } while (true);

  // Chama a função salvarOnibus para salvar as informações no arquivo
  std::vector<HorarioOnibus> onibusCadastradosTemp = {horario};
  salvarOnibus(onibusCadastradosTemp);
}

// função para exibir as informaçôes após o cadastro.
void Onibus::exibirInformacao() const {
  std::cout << "\nInformações salvas: \n" << std::endl;
  std::cout << "Linha: " << linha << std::endl;
  std::cout << "Placa: " << placa << std::endl;
  std::cout << "Tipo: " << tipo << std::endl;
  std::cout << "Marca: " << marca << std::endl;
}

// função que permite editar um onibus salvo no arquivo .txt
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
    std::vector<std::string> tokens;
    std::string token;

    while (std::getline(iss, token, ';')) {
      tokens.push_back(token);
    }

    if (tokens.size() >= 4) {
      HorarioOnibus horario;
      horario.linha = tokens[0];
      horario.placa = tokens[1];
      horario.tipo = tokens[2];
      horario.marca = tokens[3];

      for (size_t i = 4; i < tokens.size(); ++i) {
        horario.horarios.push_back(tokens[i]);
      }

      onibusCadastrados.push_back(horario);

      if (horario.placa == placaEditar) {
        placaEncontrada = true;
        // Não interrompa o loop aqui, pois ainda precisamos percorrer todo o
        // arquivo
      }
    }
  }

  arquivo.close();

  if (placaEncontrada) {
    // Placa encontrada, permitir edição
    auto it = std::find_if(onibusCadastrados.begin(), onibusCadastrados.end(),
                           [&placaEditar](const HorarioOnibus &horario) {
                             return horario.placa == placaEditar;
                           });

    if (it != onibusCadastrados.end()) {
      // Ônibus encontrado, permitir edição
      std::cout << "Digite as novas informações do ônibus:" << std::endl;

      // Edita o ônibus diretamente no vetor
      cadastrarOnibusNovo(onibusCadastrados, it);

      std::cout << "Ônibus editado com sucesso!" << std::endl;
    } else {
      std::cerr << "Erro ao encontrar ônibus com placa " << placaEditar
                << std::endl;
    }
  } else {
    std::cout << "Ônibus com placa " << placaEditar << " ainda não cadastrado."
              << std::endl;
  }

  // Salva todos os ônibus de volta no arquivo
  salvarOnibus(onibusCadastrados);
}

// função que exibe os onibus cadastrados
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

// Alteração na função salvarOnibus

void Onibus::salvarOnibus(
    const std::vector<HorarioOnibus> &onibusCadastrados) const {
  std::ofstream arquivo("onibus.txt",
                        std::ios::app); // Abre o arquivo no modo append

  if (arquivo.is_open()) {
    // Itera sobre a lista de ônibus cadastrados
    for (const auto &onibus : onibusCadastrados) {
      arquivo << onibus.linha << ';' << onibus.placa << ';' << onibus.tipo
              << ';' << onibus.marca;

      for (const auto &hora : onibus.horarios) {
        arquivo << ';' << hora;
      }

      arquivo << std::endl; // Adiciona uma quebra de linha após cada registro
    }

    arquivo.close();
  } else {
    std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
  }
}

// onibus.cpp
void Onibus::cadastrarOnibusNovo(std::vector<HorarioOnibus> &onibusCadastrados, std::vector<HorarioOnibus>::iterator it) {
  // Solicita as informações do novo ônibus
  std::cout << "> Digite a linha do ônibus: ";
  std::getline(std::cin, it->linha);

  std::cout << "> Digite a placa do ônibus: ";
  std::getline(std::cin, it->placa);

  std::cout << "> Digite o tipo do ônibus (I para interno, E para externo): ";
  std::getline(std::cin, it->tipo);

  std::cout << "> Digite a marca do ônibus: ";
  std::getline(std::cin, it->marca);

  // Limpa os horários antigos do ônibus
  it->horarios.clear();

  // Solicita os novos horários do ônibus
  std::cout << "> Digite os horários do ônibus (separados por espaço): ";
  std::string horariosStr;
  std::getline(std::cin, horariosStr);

  std::istringstream iss(horariosStr);
  std::string horario;

  // Extrai os horários da string e adiciona à lista de horários
  while (iss >> horario) {
    it->horarios.push_back(horario);
  }
}
