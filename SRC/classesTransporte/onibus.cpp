  #include "onibus.hpp"

  #include <iomanip>
  #include <iostream>
  #include <fstream>
  #include <ctime>
  #include <algorithm>

void Onibus::cadastrarOnibus() {
    std::cout << "> Digite a linha do ônibus: ";
    std::getline(std::cin, linha);

    std::cout << "> Digite a placa do ônibus: ";
    std::getline(std::cin, placa);

    std::cout << "> Digite o tipo do ônibus (interno ou externo): ";
    std::getline(std::cin, tipo);

    std::cout << "> Digite a marca do ônibus: ";
    std::getline(std::cin, marca);

HorarioOnibus novoHorario;
    novoHorario.horario = std::chrono::system_clock::now();
    novoHorario.placa = placa;
    novoHorario.tmObj = {}; // Isso inicializa todos os membros de tmObj para zero
    horarios.push_back(novoHorario);

    // Finalmente, salve os ônibus
    salvarOnibus();
}

// função para exibir as informações cadastradas do onibus
  void Onibus::exibirInformacao() const {
      std::cout << "Informações salvas: \n\n" <<  std::endl;
      std::cout << "Linha: " << linha << std::endl;
      std::cout << "Placa: " << placa << std::endl;
      std::cout << "Tipo: " << tipo << std::endl;
      std::cout << "Marca: " << marca << std::endl;
      
  }

  void Onibus::exibirHorarios() const {
      std::cout << "Horários dos ônibus cadastrados:" << std::endl;

      for (const auto& horario : horarios) {
          std::time_t tempoEmTimeT = std::chrono::system_clock::to_time_t(horario.horario);
          std::tm* localTime = std::localtime(&tempoEmTimeT);

          if (localTime) {
              std::cout << std::put_time(localTime, "%H:%M:%S") << std::endl;
          } else {
              std::cout << "Erro ao converter tempo para struct tm." << std::endl;
          }
      }
  }

  //função que permite cadastrar um novo horário
void Onibus::adicionarHorario() {
    // Exibir ônibus cadastrados para que o usuário escolha a placa
    exibirOnibusCadastrados();

    // Permita que o usuário selecione a placa do ônibus
    std::cout << "> Digite a placa do ônibus para adicionar um novo horário: ";
    std::string placaEscolhida;
    std::getline(std::cin, placaEscolhida);

    // Verificar se a placa escolhida está cadastrada
    auto it = std::find_if(horarios.begin(), horarios.end(), [&placaEscolhida](const HorarioOnibus& horario) {
        return horario.placa == placaEscolhida;
    });

    if (it != horarios.end()) {
        // Permita que o usuário informe um novo horário
        std::cout << "> Digite o novo horário (formato HH:MM:SS): ";
        std::tm novoHorarioTM = {};

        while (!(std::cin >> std::get_time(&novoHorarioTM, "%T")) || std::cin.peek() != '\n') {
            std::cout << "Entrada inválida. Digite novamente: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Converta o novo horário para std::chrono::system_clock::time_point
        auto novoHorario = std::chrono::system_clock::from_time_t(std::mktime(&novoHorarioTM));

        // Adicione o novo horário ao vetor de horários
        it->horario = novoHorario;

        std::cout << "Novo horário cadastrado com sucesso para o ônibus com placa " << placaEscolhida << "!" << std::endl;
    } else {
        std::cout << "Ônibus com placa " << placaEscolhida << " não encontrado." << std::endl;
    }
}

// função que permite alterar as informações de um ônibus
void Onibus::editarOnibus() {
    std::cout << "Digite a placa do ônibus que deseja editar: ";
    std::string placaEditar;
    std::getline(std::cin, placaEditar);

    // Verifica se a placa existe no arquivo onibus.txt
    std::ifstream arquivo("onibus.txt");
    std::string linha;
    bool placaEncontrada = false;

    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        std::tm tmObj;
        std::string placaArquivo;

        // Extrai horário e placa do arquivo
        if (iss >> std::get_time(&tmObj, "%H:%M:%S") >> placaArquivo) {
            if (placaArquivo == placaEditar) {
                placaEncontrada = true;
                break;  // Placa encontrada, não é necessário continuar a busca
            }
        }
    }

    arquivo.close();

    if (placaEncontrada) {
        // Placa encontrada, permitir edição
        auto it = std::find_if(horarios.begin(), horarios.end(), [&placaEditar](const HorarioOnibus& horario) {
            return horario.placa == placaEditar;
        });

        if (it != horarios.end()) {
            // Ônibus encontrado, permitir edição
            std::cout << "Digite as novas informações do ônibus:" << std::endl;

            // Remove o ônibus antigo com base na placa
            horarios.erase(it);

            // Cadastra o ônibus novamente com as novas informações
            cadastrarOnibus();

            std::cout << "Ônibus editado com sucesso!" << std::endl;
        } else {
            std::cerr << "Erro ao encontrar ônibus com placa " << placaEditar << std::endl;
        }
    } else {
        std::cout << "Ônibus com placa " << placaEditar << " ainda não cadastrado." << std::endl;
    }
}

  // Função para pegar os ônibus cadastrados.
  const std::vector<HorarioOnibus>& Onibus::getOnibusCadastrados() const {
      return horarios;
  }

  // Função que retorna os ônibus cadastrados
void Onibus::exibirOnibusCadastrados() const {
    const auto& onibusCadastrados = this->getOnibusCadastrados();

    if (onibusCadastrados.empty()) {
        std::cout << "Nenhum ônibus cadastrado." << std::endl;
    } else {
        std::cout << "Ônibus cadastrados:" << std::endl;

        for (const auto& horario : onibusCadastrados) {
            std::time_t tempoEmTimeT = std::chrono::system_clock::to_time_t(horario.horario);
            std::tm* localTime = std::localtime(&tempoEmTimeT);

            if (localTime) {
                std::cout << "Placa: " << horario.placa << " - Tipo: " << tipo << " - Horário: " << std::put_time(localTime, "%H:%M:%S") << std::endl;
            } else {
                std::cout << "Erro ao converter tempo para struct tm." << std::endl;
            }
        }
    }
}


  // Função para carregar os ônibus do arquivo
void Onibus::carregarOnibus() {
    std::ifstream arquivo("onibus.txt");

    if (arquivo.is_open()) {
        horarios.clear();

        HorarioOnibus horario;
        std::string linha;

        while (std::getline(arquivo, linha)) {
            std::istringstream iss(linha);

            // Extrai horário e placa
            if (iss >> std::get_time(&horario.tmObj, "%H:%M:%S") >> horario.placa) {
                horario.horario = std::chrono::system_clock::from_time_t(std::mktime(&horario.tmObj));
                horarios.push_back(horario);
            }
        }

        arquivo.close();
        std::cout << "\n\n" << std::endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo para leitura." << std::endl;
    }
}

//função que armazena os onibus cadastrados
void Onibus::salvarOnibus() const {
    std::ofstream arquivo("onibus.txt");

    if (arquivo.is_open()) {
        for (const auto& horario : horarios) {
            arquivo << formatarOnibus(horario) << std::endl;
        }

        arquivo.close();
        std::cout << "\n" << std::endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
    }
}

//função para levar os valores do onibus para o arquivo

std::string Onibus::formatarOnibus(const HorarioOnibus& horario) const {
    std::time_t tempoEmTimeT = std::chrono::system_clock::to_time_t(horario.horario);
    std::tm* localTime = std::localtime(&tempoEmTimeT);

    std::ostringstream formattedData;

    if (localTime) {
        formattedData << std::put_time(localTime, "%H:%M:%S") << " " << horario.placa;
    } else {
        std::cerr << "Erro ao converter tempo para struct tm." << std::endl;
    }

    return formattedData.str();
}

//função para salvar as novas informações do onibus
void Onibus::cadastrarOnibusNovo() {
    std::cout << "> Digite a linha do ônibus: ";
    std::getline(std::cin, linha);

    std::cout << "> Digite a placa do ônibus: ";
    std::getline(std::cin, placa);

    std::cout << "> Digite o tipo do ônibus (interno ou externo): ";
    std::getline(std::cin, tipo);

    std::cout << "> Digite a marca do ônibus: ";
    std::getline(std::cin, marca);

    // Adicione o novo ônibus à lista de horários
  horarios.push_back({std::chrono::system_clock::now(), placa, std::tm(), tipo});


    // Finalmente, salve os ônibus
    salvarOnibus();
}
