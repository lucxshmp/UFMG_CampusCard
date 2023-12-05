#include "rotina.hpp"
#include "validacao.hpp"



    void Rotina::cadastrarDisciplina(){

        carregarDisciplinasDeArquivo("discplinas.txt");

        //adicionar classe Validacao
        Validacao validacao;
        Interface interface;
        interface.tituloSessao("Cadastrar Disciplinas");

        //inicializa com vazio o char
        char cadastrarMaisDisciplina = '\n';

        //loop de cadastro
        do{

            //inserir o vetor de struct Disciplina na função
            Disciplina novaDisciplina;

            /*uso da função cadastarDetalhes para inserir detalhes
            sobre cada disciplina cadastrada*/
            cadastrarDetalhes(novaDisciplina);

            /*cadastro de horários em loop dada a possbilidade de 
            uma disciplina ser realizada em vários dias da semana 
            e em horários diferentes*/
            char cadastrarMaisHorario = '\n';
                do{ 

                    //inserir o vetor de struct Horário na função
                    Horario novoHorario;

                    /*uso da função cadastarHorarios para inserir os 
                    horários de cada disciplina cadastrada*/
                    cadastrarHorarios(novoHorario);

                    //adiciona o horario ao vetor
                    novaDisciplina.horarios.push_back(novoHorario);

                    //possibilidade de cadastro de mais horários
                    
                    std::cout << ">>> Deseja cadastrar mais um horário para a disciplina? (S/N): ";
                    std::cin >> cadastrarMaisHorario;
                    validacao.validarSN(cadastrarMaisHorario);
                    std::cout << std::endl;

                    //limpar buffer do teclado
                    if (cadastrarMaisHorario == 'S' || cadastrarMaisHorario == 's'){
                        std::cin.ignore();
                    }

                //sair do loop apenas quando o usuário não tiver mais horários para cadastrar
                }while (cadastrarMaisHorario == 'S' || cadastrarMaisHorario == 's');

            //adiciona as informaçoes ao vetor disciplina
            disciplinas.push_back(novaDisciplina);

            //possibilidade de cadastro de mais disciplinas
            std::cout << std::setw(60) << std::setfill('-') << "" << std::endl;
            std::cout << ">>> Deseja cadastrar mais uma disciplina? (S/N):";
            std::cin >> cadastrarMaisDisciplina;
            validacao.validarSN(cadastrarMaisDisciplina);
            std::cout << std::endl;

            //limpar buffer do teclado
            if (cadastrarMaisDisciplina == 'S' || cadastrarMaisDisciplina == 's'){
                std::cin.ignore();
            }

        //sair do loop apenas quando o usuário não tiver mais disciplinas para cadastrar
        } while (cadastrarMaisDisciplina == 'S' || cadastrarMaisDisciplina == 's');

        salvarDisciplinasEmArquivo("disciplinas.txt");
    
    }

    //função que permite realizar alterações nas disciplinas
    void Rotina::editar_disciplina(){

        carregarDisciplinasDeArquivo("disciplinas.txt");

        //inserir a classe Valicao na função
        Validacao validacao;
        Interface interface;
        interface.tituloSessao("Editar Disciplinas");

        //Auxiliares inicializados
        int aux = 0;
        int func = 0;
        char realizarAlteracao = '\n';

        do{

            //perguntar qual disciplina o usuário quer alterar  
            std::cout << "DISCIPLINAS CADASTRADAS" << std::endl;

            //Listar todas as disciplinas cadastradas
            for(int i=0; i<disciplinas.size(); i++){
                std::cout << "   " << i+1 << ". " << disciplinas[i]._nome << std::endl;
            }
            std::cout << "Escolha o número correspente para alterar a disciplina: " << std::endl;
            
            aux = validacao.validarNumero(aux);
            std::cout << std::endl;

            //Usuário escolhe qual informação deseja alterar
            std::cout << "    Escolha o atributo a ser editado:\n"
                          << "     1. Nome\n"
                          << "     2. Código\n"
                          << "     3. Sala\n"
                          << "     4. Prédio\n"
                          << "     5. Horário\n"
                          << "     >> Escolha: ";

            func = validacao.validarNumero(func);
            std::cout << std::endl;

            //switch que permite alterar a variavel desejada da disciplina
            switch(func){

                case 1:
                    std::cout << "    > Digite o novo nome: ";
                    std::cin >> disciplinas[func-1]._nome;
                    break;

                case 2: 
                    std::cout << "Digite o novo código: ";
                    std::cin >> disciplinas[func-1]._codigo;
                    break;

                case 3: 
                    std::cout << "Digite a nova sala: ";
                    std::cin >> disciplinas[func-1]._sala;
                    break;

                case 4: 
                    std::cout << "Digite o novo prédio: ";
                    std::cin >> disciplinas[func-1]._predio;
                    break;

                case 5: 
                    std::cout << "Digite o novo código: ";
                    std::cin >> disciplinas[func-1]._codigo;
                    break;
              
                default:
                    std::cout << "Valor Inválido" << std::endl;
            }

            std::cout << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),   '\n');

            //Possibilidade de realizar mais alterações
            std::cout << ">>> Deseja realizar mais alterações? (S/N): ";
            std::cin >> realizarAlteracao;
            validacao.validarSN(realizarAlteracao);
            std::cout << std::endl;

            //limpar buffer
            if(realizarAlteracao == 'S' || realizarAlteracao == 's') std::cin.ignore();

        //condição parada do loop
        } while(realizarAlteracao == 'S' || realizarAlteracao == 's');
     
        salvarDisciplinasEmArquivo("disciplinas.txt");

    }

    void Rotina::cadastrarDetalhes(Disciplina &novaDisciplina){

        /*cadastro de dados da disciplina colocando o nome e 
        as suas informaçoes em um vetor de disciplinas*/
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "> Digite o código da disciplina: ";
        std::getline(std::cin, novaDisciplina._codigo);

        std::cout << "> Digite o nome da disciplina: ";
        std::getline(std::cin, novaDisciplina._nome);

        std::cout << "> Digite o prédio: ";
        std::getline(std::cin, novaDisciplina._predio);

        std::cout << "> Digite a sala: ";
        std::getline(std::cin, novaDisciplina._sala);

    }

    void Rotina::cadastrarHorarios(Horario &novoHorario){ 

    //Insreir classe validao na função
    Validacao validacao;
        do {

            // cadastro do dia, porém com limitação do dia das semanas ao usuário
            std::cout << std::endl;
            std::cout << " DIAS DA SEMANA " << std::endl;
            std::cout << " 1. Segunda\n 2. Terça\n 3. Quarta\n 4. Quinta\n 5. Sexta\n 6. Sábado" << std::endl;
            std::cout << std::endl;
            std::cout << "> Escolha o dia da semana: ";
            std::cin >> novoHorario._dia;
            novoHorario._dia = validacao.validarDia(novoHorario._dia);

            // cadastro do horário, porém com limitação.
            std::cout << std::endl;
            std::cout << " HORÁRIOS NOTURNO " << std::endl;
            std::cout << " 1. 19:00 a 20:40\n 2. 20:55 a 22:25" << std::endl;
            std::cout << std::endl;
            std::cout << "> Escolha o horário de aula: ";
            std::cin >> novoHorario._hora;
            novoHorario._hora = validacao.validarHorario(novoHorario._hora);
            std::cout << std::endl;

            //verificar se já existe uma disciplina cadastrada no mesmo horário
            if (existeDisciplinaNoHorario(novoHorario._dia, novoHorario._hora)) {
                std::cout << "(!) Já existe uma disciplina cadastrada nesse horário.\n(!) Escolha outro horário.\n";
            } else {
                //se não houver disciplina cadastrada no mesmo horário, sair do loop
                break;
            }
        } while (true);

    }

    void Rotina::informacoes_disciplina(){

        carregarDisciplinasDeArquivo("disciplinas.txt");

        //inserir classe Validacao na função
        Validacao validacao;
        Interface interface;
        interface.tituloSessao("Informações das disciplinas");

        //loop que imprimi na tela as disciplinas cadastradas

        for(int i = 0; i<disciplinas.size(); i++){
            std::cout << "- " << disciplinas[i]._nome << "(" << disciplinas[i]._codigo << ")" << std::endl;
            std::cout << "    Prédio - " << disciplinas[i]._predio << ", sala " << disciplinas[i]._sala << std::endl;

            //loop para alterar horários 
            for(int j=0; j<disciplinas[i].horarios.size(); j++){
                std::cout << "    " << validacao.transformarEmDia(disciplinas[i].horarios[j]._dia) << " - " << validacao.transformarEmHora(disciplinas[i].horarios[j]._hora) << std::endl;
            }
            std::cout << std::setw(40) << std::setfill('-') << "" << std::endl;
        }

    }

    //conferir se existe disciplina cadastrada em um horário
    bool Rotina::existeDisciplinaNoHorario(int dia, int hora) const {

        //inicia o loop se tiver disciplina cadastrada
        for (const auto& disciplina : disciplinas) {
            for (const auto& horario : disciplina.horarios) {
                if (horario._dia == dia && horario._hora == hora) {
                    return true;  
                }
            }
        }
        return false; //não possui cadastradas 
    }

    //getDisciplina
    const std::vector<Rotina::Disciplina>& Rotina::getDisciplinas() const {
        return disciplinas;
    }
        
    //adicionar disciplina no arquivo
    void Rotina::salvarDisciplinasEmArquivo(const std::string& nomeArquivo) const {
        std::ofstream arquivo(nomeArquivo);

        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo para escrita.\n";
            return;
        }

        // Escrever as disciplinas no formato CSV
        for (const auto& disciplina : disciplinas) {
            arquivo << "Código:" << disciplina._codigo << ";"
                    << "Nome:" << disciplina._nome << ";"
                    << "Prédio:" << disciplina._predio << ";"
                    << "Sala:" << disciplina._sala << ";"
                    << "Horários:";

            for (const auto& horario : disciplina.horarios) {
                arquivo << horario._dia << " " << horario._hora << " ";
            }

            arquivo << ";\n";
        }

        arquivo.close();
    }

    //função que carrega um arquivo, fazendo sua leitura 
    void Rotina::carregarDisciplinasDeArquivo(const std::string& nomeArquivo) {
        disciplinas.clear(); 

        std::ifstream arquivo(nomeArquivo);

        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo para leitura.\n";
            return;
        }

        std::string linha;

        while (std::getline(arquivo, linha)) {
            std::istringstream ss(linha);
            std::string token;

            Disciplina novaDisciplina;
            Horario novoHorario;

            while (std::getline(ss, token, ';')) {
                std::istringstream tokenStream(token);
                std::string chave, valor;
                std::getline(tokenStream, chave, ':');
                std::getline(tokenStream, valor);

                if (chave == "Código") {
                    novaDisciplina._codigo = valor;
                } else if (chave == "Nome") {
                    novaDisciplina._nome = valor;
                } else if (chave == "Prédio") {
                    novaDisciplina._predio = valor;
                } else if (chave == "Sala") {
                    novaDisciplina._sala = valor;
                } else if (chave == "Horários") {
                    std::istringstream horarioStream(valor);
                    while (horarioStream >> novoHorario._dia >> novoHorario._hora) {
                        novaDisciplina.horarios.push_back(novoHorario);
                    }
                }
            }

            //incluir arquivo no vetor disciplina
            disciplinas.push_back(novaDisciplina);
        }

        arquivo.close();
    }