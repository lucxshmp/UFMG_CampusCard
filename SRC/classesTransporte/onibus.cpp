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
      novoHorario.tmObj = {};

      cadastrarHorarios(novoHorario);

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
        // Converter tm para time_t
        std::time_t tempoEmTimeT = std::mktime(const_cast<std::tm*>(&horario.tmObj));

        // Verificar se a conversão foi bem-sucedida
        if (tempoEmTimeT == -1) {
            std::cout << "Erro ao converter tempo para struct tm." << std::endl;
        } else {
            std::tm* localTime = std::localtime(&tempoEmTimeT);

            if (localTime) {
                std::cout << std::put_time(localTime, "%H:%M:%S") << std::endl;
            } else {
                std::cout << "Erro ao converter tempo para struct tm." << std::endl;
            }
        }
    }
}

//função que permite cadastrar um novo horário
void Onibus::cadastrarHorarios(HorarioOnibus& novoHorario) {
    char resposta;

    do {
        std::string horaStr;

        // Cadastro do horário, porém com limitação.
        do {
            std::cout << "    > Digite o horário de saída do ônibus (formato: HH:MM): ";
            std::getline(std::cin, horaStr);
            novoHorario.tmObj.tm_hour = std::stoi(horaStr);

        } while (!validarFormatoHora(horaStr));

        // Adicione o novo horário ao vetor de horários
        horarios.push_back(novoHorario);

        // Perguntar ao usuário se deseja cadastrar um novo horário
        do {
            std::cout << "Deseja cadastrar um novo horário? (S/N): ";
            std::cin >> resposta;
            std::cin.ignore(); // Limpar o buffer do teclado

            if (resposta != 'S' && resposta != 's' && resposta != 'N' && resposta != 'n') {
                std::cout << "Opção inválida. Digite S para Sim ou N para Não." << std::endl;
            }
        } while (resposta != 'S' && resposta != 's' && resposta != 'N' && resposta != 'n');

    } while (resposta == 'S' || resposta == 's');
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
                std::cout << "Placa: " << horario.placa << " - Tipo: " << horario.tipo
                          << " - Horário: " << std::put_time(localTime, "%H:%M:%S") << std::endl;
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
  /*horarios.push_back({std::chrono::system_clock::now(), placa, {}, std::tm(), tipo});
  */

    // Finalmente, salve os ônibus
    salvarOnibus();
}

bool validarFormatoHora(const std::string& horaStr) {
    // Verifica se a string tem o formato esperado (HH:MM)
    if (horaStr.size() != 5) {
        std::cout << "Formato incorreto. O horário deve ter 5 caracteres." << std::endl;
        return false;
    }

    if (horaStr[2] != ':') {
        std::cout << "Formato incorreto. O terceiro caracter deve ser ':'." << std::endl;
        return false;
    }

    // Verifica se os caracteres antes e depois do ':' são dígitos
    if (!std::isdigit(horaStr[0]) || !std::isdigit(horaStr[1]) || !std::isdigit(horaStr[3]) || !std::isdigit(horaStr[4])) {
        std::cout << "Formato incorreto. Os caracteres antes e depois do ':' devem ser dígitos." << std::endl;
        return false;
    }

    // Verifica se as horas e minutos estão dentro dos limites corretos
    int horas = std::stoi(horaStr.substr(0, 2));
    int minutos = std::stoi(horaStr.substr(3, 2));

    if (horas < 0 || horas > 23 || minutos < 0 || minutos > 59) {
        std::cout << "Horário incorreto. As horas devem estar entre 00 e 23, e os minutos entre 00 e 59." << std::endl;
        return false;
    }

    return true; // O formato do horário está correto
}
