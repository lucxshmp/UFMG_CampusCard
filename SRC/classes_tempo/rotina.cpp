#include "rotina.hpp"
#include "validação.hpp"


    void Rotina::cadastrarDisciplina() {

        Validacao validacao;

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
                    std::cout << std::endl;
                    std::cout << std::setw(80) << std::setfill('-') << "" << std::endl;
                    std::cout << "Deseja cadastrar mais um horário para a disciplina? (S/N): ";
                    std::cin >> cadastrarMaisHorario;
                    validacao.validarSN(cadastrarMaisHorario);

                    //limpar buffer do teclado
                    if (cadastrarMaisHorario == 'S' || cadastrarMaisHorario == 's'){
                        std::cin.ignore();
                    }

                //sair do loop apenas quando o usuário não tiver mais horários para cadastrar
                }while (cadastrarMaisHorario == 'S' || cadastrarMaisHorario == 's');

            //adiciona as informaçoes ao vetor disciplina
            disciplinas.push_back(novaDisciplina);

            //possibilidade de cadastro de mais disciplinas
            std::cout << std::setw(80) << std::setfill('-') << "" << std::endl;
            std::cout << "Deseja cadastrar mais uma disciplina? (S/N):";
            std::cin >> cadastrarMaisDisciplina;
            validacao.validarSN(cadastrarMaisDisciplina);

            //limpar buffer do teclado
            if (cadastrarMaisDisciplina == 'S' || cadastrarMaisDisciplina == 's'){
                std::cin.ignore();
            }

        //sair do loop apenas quando o usuário não tiver mais disciplinas para cadastrar
        } while (cadastrarMaisDisciplina == 'S' || cadastrarMaisDisciplina == 's');

    }


    //função que permite realizar alterações nas disciplinas
    void Rotina::editar_disciplina(){

        //inserir a classe Valicao na função
        Validacao validacao;

        //Auxiliares inicializados
        int disci = 0;
        int func = 0;
        char realizarAlteracao = '\n';

        do{

            //perguntar qual disciplina o usuário quer alterar  
            std::cout << "Escolha o número correspente para alterar a disciplina" << std::endl;

            //Listar todas as disciplinas cadastradas
            for(int i=0; i<disciplinas.size(); i++){
                std::cout << "Digite "<< i+1 << disciplinas[i]._nome << std::endl;
            }

            std::cin >> disci;

            //Usuário escolhe qual informação deseja alterar
            std::cout << "Digite 1 - se você quiser alterar o nome" << std::endl;
            std::cout << "Digite 2 - se você quiser alterar o código" << std::endl;
            std::cout << "Digite 3 - se você quiser alterar a sala" << std::endl;
            std::cout << "Digite 4 - se você quiser alterar o prédio" << std::endl;
            std::cout << "Digite 5 - se você quiser alterar o horário" << std::endl;

            func = validacao.validarNumero(func);


            //switch que permite alterar a variavel desejada da disciplina
            switch(func){

                case 1:
                    std::cout << "Digite o novo nome: " << std::endl;
                    std::cin >> disciplinas[disci-1]._nome;
                    std::cout << "O novo nome é" << disciplinas[disci-1]._nome << std::endl;
                    break;

                case 2: 
                    std::cout << "Digite o novo código: " << std::endl;
                    std::cin >> disciplinas[disci-1]._codigo;
                    std::cout << "O novo código é" << disciplinas[disci-1]._codigo << std::endl;
                    break;

                case 3: 
                    std::cout << "Digite a nova sala: " << std::endl;
                    std::cin >> disciplinas[disci-1]._sala;
                    std::cout << "A nova sala é" << disciplinas[disci-1]._sala << std::endl;
                    break;

                case 4: 
                    std::cout << "Digite o novo prédio: " << std::endl;
                    std::cin >> disciplinas[disci-1]._predio;
                    std::cout << "O novo predio é" << disciplinas[disci-1]._predio << std::endl;
                    break;

                case 5: 
                    std::cout << "Digite o novo código: " << std::endl;
                    std::cin >> disciplinas[disci-1]._codigo;
                    std::cout << "O novo código é" << disciplinas[disci-1]._codigo << std::endl;
                    break;
                default:
                    std::cout << "Valor Inválido" << std::endl;
            }

            //Possibilidade de realizar mais alterações
            std::cout << "Deseja realizar mais alterações? (S/N): " << std::endl;
            std::cin >> realizarAlteracao;

            //limpar buffer
            if(realizarAlteracao == 'S' || realizarAlteracao == 's') std::cin.ignore();

        //condição parada do loop
        } while(realizarAlteracao == 'S' || realizarAlteracao == 's');

    }

    void Rotina::cadastrarDetalhes(Disciplina &novaDisciplina){

        /*cadastro de dados da disciplina colocando o nome e 
        as suas informaçoes em um vetor de disciplinas*/
        std::cout << std::endl;
        std::cout << std::setw(80) << std::setfill('*') << "" << std::endl;
        std::cout << std::setw(15) << std::setfill(' ') << std::left << "Cadastre a disciplina" << std::setw(25) << std::setfill(' ') << std::right << "" << std::endl;
        std::cout << std::setw(80) << std::setfill('*') << "" << std::endl;
        std::cout << std::endl;

        std::cout << "- Digite o código da disciplina: ";
        std::getline(std::cin, novaDisciplina._codigo);

        std::cout << "- Digite o nome da disciplina: ";
        std::getline(std::cin, novaDisciplina._nome);

        std::cout << "- Digite o prédio: ";
        std::getline(std::cin, novaDisciplina._predio);

        std::cout << "- Digite a sala: ";
        std::getline(std::cin, novaDisciplina._sala);

    }

    void Rotina::cadastrarHorarios(Horario &novoHorario){ 

    //Insreir classe validao na função
    Validacao validacao;
        do {

            // cadastro do dia, porém com limitação do dia das semanas ao usuário
            std::cout << "Escolha o dia da semana: " << std::endl;
            std::cout << "     1. Segunda  2. Terça  3. Quarta\n     4. Quinta   5. Sexta  6. Sábado\n";
            std::cin >> novoHorario._dia;
            std::cout << std::endl;
            novoHorario._dia = validacao.validarDia(novoHorario._dia);

            // cadastro do horário, porém com limitação.
            std::cout << "Escolha o horário: " << std::endl;
            std::cout << "     1. 19:00 a 20:40\n     2. 20:55 a 22:25\n";
            std::cin >> novoHorario._hora;
            std::cout << std::endl;
            novoHorario._hora = validacao.validarHorario(novoHorario._hora);

            // Verificar se já existe uma disciplina cadastrada no mesmo horário
            if (existeDisciplinaNoHorario(novoHorario._dia, novoHorario._hora)) {
                std::cout << "Já existe uma disciplina cadastrada nesse horário. Escolha outro horário.\n";
            } else {
                // Se não houver disciplina cadastrada no mesmo horário, sair do loop
                break;
            }
        } while (true);

    }

    void Rotina::informacoes_disciplina(){

        //inserir classe Validacao na função
        Validacao validacao;

        //loop que imprimi na tela as disciplinas cadastradas
        std::cout << std::setw(40) << std::setfill('=') << "" << std::endl;
        std::cout << std::setw(15) << std::setfill(' ') << std::left << "Informações disciplinas" << std::setw(25) << std::setfill(' ') << std::right << "" << std::endl;
        std::cout << std::setw(40) << std::setfill('=') << "" << std::endl;
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
