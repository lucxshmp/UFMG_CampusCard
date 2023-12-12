#include "eventos.hpp"
#include "validacao.hpp"
#include "interface.hpp"
#include "rotina.hpp"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>

    //função que adiciona uma tarefa ao vetor tarefas
    void Eventos::adicionarTarefas(std::vector<Eventos>& tarefas){

        //ler arquivo tarefas
        carregarTarefasDeArquivo(tarefas, "tarefas.txt");
        
        //adicionar classe Validacao e Interface
        Validacao validacao;
        Interface interface;
        interface.tituloSessao("Adicionar Tarefas");

        //auxiliar do loop
        char cadastrarMaisTarefas;

        //loop para se cadastrar mais de uma tarefa
        do {

            //inserir dados as tarefas
            std::cout << "> Digite o nome da tarefa: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, _nome);

            std::cout << "> Digite a descrição da tarefa: ";
            std::getline(std::cin, _descricao);

            //validar data
            do {
                std::cout << "> Digite a data de vencimento da tarefa (formato: DD-MM-AAAA): ";
                std::getline(std::cin, _data);
            } while (!validacao.validarFormatoData(_data));

            //validar hora
            do {
                std::cout << "> Digite a hora de vencimento da tarefa (formato: HH:MM): ";
                std::getline(std::cin, _hora);
            } while (!validacao.validarFormatoHora(_hora));

            std::cout << "> Digite a disciplina da tarefa: ";
            std::getline(std::cin, _disciplina);

            deadline = parseDateTime(_data, _hora);

            //adicionar tarefa ao vetor
            tarefas.push_back(*this);

             // opção de cadastro de mais tarefas
            std::cout << std::endl << ">>> Deseja cadastrar mais tarefas? (S/N): ";
            std::cin >> cadastrarMaisTarefas;
            
            validacao.validarSN(cadastrarMaisTarefas);
            std::cout << std::endl;
            if(cadastrarMaisTarefas == 's' || cadastrarMaisTarefas == 'S') std::cout << "  Cadastrar nova Tarefa" << std::endl;
            std::cin.ignore();

        //condição de parada do loop
        } while (cadastrarMaisTarefas == 'S' || cadastrarMaisTarefas == 's');

        //adicionar tarefa cadastrada em um arquivo
        salvarTarefasEmArquivo(tarefas, "tarefas.txt");

    }

    //função que ordena a exibição da lista por prazo
    void Eventos::exibirPorPrazo(std::vector<Eventos>& tarefas){ 

        //lendo arquivo tarefas
        carregarTarefasDeArquivo(tarefas, "tarefas.txt");

       //adicionar classe Validacao e Interface
        Validacao validacao;
        Interface interface;
        interface.tituloSessao("Lista de Tarefas Ordenadas por Prazo");

        //copia o vetor
        std::vector<Eventos> tarefasCopia = tarefas;  

        //organiza a cópia por prazo
        std::sort(tarefasCopia.begin(), tarefasCopia.end()); 

        //chama a função que imprime
        for (const auto& tarefas : tarefasCopia) {
            tarefas.displayTarefa();
        }
    }

    //função que imprime a lista
    void Eventos::displayTarefa() const {
        auto tempoRestante = tempo();

        std::cout << "Tarefa: " << _nome << "\n"
                  << "Descrição: " << _descricao << "\n"
                  << "Disciplina: " << _disciplina << "\n"
                  << "Prazo: ";

        //analisa se o prazo já venceu
        if (tempoRestante.first < 0) {
            std::cout << "(!) Vencido (!)" << std::endl;
        } else {
            std::cout << tempoRestante.first << " dias e " << tempoRestante.second << " horas\n";
        }
        std::cout << "-----------------------------------" << std::endl;
    }

    //função que permite a possibilidade de editar tarefas
    void Eventos::editarTarefas(std::vector<Eventos>& tarefas) {
        
        //ler o arquivo tarefas
        carregarTarefasDeArquivo(tarefas, "tarefas.txt");

        //adicionar classe Validacao e interface
        Validacao validacao;
        Interface interface;
        interface.tituloSessao("Editar tarefas");

        //tarefas com index
        int tarefaIndex = 0;

        //auxiliar no loop
        char realizarAlteracao ='\n';

        //loop que permite mais edições
        do{


            //lista todas as tarefas cadastradas
            for (int i = 0; i < tarefas.size(); i++) {
                std::cout << "> Digite " << i + 1 << " para editar: " << tarefas[i]._nome << std::endl;
            }
            std::cout << std::endl;
            std::cout << ">>> Escolha ";
            tarefaIndex = validacao.validarNumero(tarefaIndex);
            std::cout << std::endl;
            //levar o indíce a zero
            tarefaIndex--;

            //analise do indíce
            if (tarefaIndex >= 0 && tarefaIndex < tarefas.size()) {

                std::cout << " Escolha o atributo a ser editado:\n"
                          << "    1. Nome\n"
                          << "    2. Descrição\n"
                          << "    3. Data\n"
                          << "    4. Hora\n"
                          << "    5. Disciplina\n"
                          << "    >> Escolha: ";

                int escolha = 0;
                escolha = validacao.validarNumero(escolha);
                std::cin.ignore(); // Limpar o buffer de entrada
                std::cout << std::endl;

                //switch que altera o desejado pelo usuário
                switch (escolha) {
                    case 1:
                        std::cout << "    > Digite o novo nome: ";
                        std::getline(std::cin, tarefas[tarefaIndex]._nome);
                        break;
                    case 2:
                        std::cout << "    > Digite a nova descrição: ";
                        std::getline(std::cin, tarefas[tarefaIndex]._descricao);
                        break;
                case 3:
                    //permitir só entrada válida
                    do{
                        std::cout << "    > Digite a nova Hora de vencimento da tarefa (formato: HH:MM): ";
                        std::getline(std::cin, tarefas[tarefaIndex]._data);
                    }while (!validacao.validarFormatoData(tarefas[tarefaIndex]._hora));

                    // Recalcular o prazo após alterar a data
                    tarefas[tarefaIndex].deadline = parseDateTime(tarefas[tarefaIndex]._data, tarefas[tarefaIndex]._hora);
                    break;
                case 4:
                    //permitir só entrada válida
                    do{
                        std::cout << "    > Digite a nova hora de vencimento da tarefa (formato: HH:MM): ";
                        std::getline(std::cin, tarefas[tarefaIndex]._hora);
                    }while (!validacao.validarFormatoHora(tarefas[tarefaIndex]._hora));

                    // Recalcular o prazo após alterar a hora
                    tarefas[tarefaIndex].deadline = parseDateTime(tarefas[tarefaIndex]._data, tarefas[tarefaIndex]._hora);
                    break;
                    case 5:
                        std::cout << "    > Digite a nova disciplina: ";
                        std::getline(std::cin, tarefas[tarefaIndex]._disciplina);
                        break;
                    default:
                        std::cout << "(!) Escolha inválida. " << std::endl;
                        break;
                }
            }else{
                std::cout << "Índice inválido. " << std::endl;
            }

            //possibilidade de realizar mais alterações
            std::cout << std::endl;
            std::cout << ">>> Deseja realizar mais alterações? (S/N): " << std::endl;
            std::cin >> realizarAlteracao;
            validacao.validarSN(realizarAlteracao);


            //limpar buffer
            if(realizarAlteracao == 'S' || realizarAlteracao == 's') std::cin.ignore();

        //condição parada do loop
        }while(realizarAlteracao == 'S' || realizarAlteracao == 's');
        
        //adicionando alterações no arquivo
        salvarTarefasEmArquivo(tarefas, "tarefas.txt");

    }

    //função que calcula o prazo
    std::pair<int, int> Eventos::tempo() const {

        //obtem o tempo atual
        auto now = std::chrono::system_clock::now();

        //subtrai o tempo cadastrado pelo atual
        auto duration = std::chrono::duration_cast<std::chrono::hours>(deadline - now);

        //converte em horas e dias
        int dias = duration.count() / 24;  
        int horas = duration.count() % 24;

        return {dias, horas};
    }

   //pperador de comparação 
    bool Eventos::operator<(const Eventos& outros) const {
        return deadline < outros.deadline;
    }

    //converter o dado cadastrado pelo usuário em tempo que pode ser realizado operações
    std::chrono::system_clock::time_point Eventos::parseDateTime(const std::string& date, const std::string& time) const {
        std::tm tm = {};
        std::istringstream dateStream(date + " " + time);
        dateStream >> std::get_time(&tm, "%d-%m-%Y %H:%M");

        //configura para o fuso de Brasília
        std::chrono::minutes brtOffset = std::chrono::minutes(+240);

        auto timePoint = std::chrono::system_clock::from_time_t(std::mktime(&tm)) + brtOffset;

        return timePoint;
    }


    void Eventos::salvarTarefasEmArquivo(const std::vector<Eventos>& tarefas, const std::string& nomeArquivo) {
        
        std::ofstream arquivo(nomeArquivo);

        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo para escrita.\n";
            return;
        }

        for (const auto& tarefa : tarefas) {
            arquivo << "Nome:" << tarefa._nome << ";"
                    << "Descrição:" << tarefa._descricao << ";"
                    << "Data:" << tarefa._data << ";"
                    << "Hora:" << tarefa._hora << ";"
                    << "Disciplina:" << tarefa._disciplina << "\n";
        }
    arquivo.close();
    }

    // Adaptação para carregar tarefas de arquivo
    void Eventos::carregarTarefasDeArquivo(std::vector<Eventos>& tarefas, const std::string& nomeArquivo) {
    tarefas.clear();

    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para leitura.\n";
        return;
    }

    std::string linha;

    while (std::getline(arquivo, linha)) {
        
        std::istringstream ss(linha);
        std::string token;
        Eventos novaTarefa;

        while (std::getline(ss, token, ';')) {
            std::istringstream tokenStream(token);
            std::string chave, valor;
            std::getline(tokenStream, chave, ':');
            std::getline(tokenStream, valor);

            if (chave == "Nome") {
                novaTarefa._nome = valor;
            } else if (chave == "Descrição") {
                novaTarefa._descricao = valor;
            } else if (chave == "Data") {
                novaTarefa._data = valor;
            } else if (chave == "Hora") {
                novaTarefa._hora = valor;
            } else if (chave == "Disciplina") {
                novaTarefa._disciplina = valor;
            }
            // Adiciona a tarefa ao vetor
            tarefas.push_back(novaTarefa);
        }
        arquivo.close();
    }
}

  //funções set
    void Eventos::setNome(const std::string& nome){
        _nome = nome;
    }

    void Eventos::setDescricao(const std::string& descricao){
        _descricao = descricao;
    }

    void Eventos::setData(const std::string& data){
        _data = data;
        deadline = parseDateTime(_data, _hora);
        }

    void Eventos::setHora(const std::string& hora){
        _hora = hora;

        deadline = parseDateTime(_data, _hora);
    }

    void Eventos::setDisciplina(const std::string& disciplina){
        _disciplina = disciplina;
    }

  //funções get
    std::string Eventos::getNome() const {
        return _nome;
    }

    std::string Eventos::getDescricao() const {
        return _descricao;
    }

    std::string Eventos::getData() const {
        return _data;
    }

    std::string Eventos::getHora() const {
        return _hora;
    }

    std::string Eventos::getDisciplina() const {
        return _disciplina;
    }




