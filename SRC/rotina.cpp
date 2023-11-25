
#include "rotina.hpp"

    void Rotina::cadastrarDisciplina() {

        char cadastrarMaisDisciplina = '\n';

        //loop de cadastro
        do{

            //inserir o struct disciplina na função
            Disciplina novaDisciplina;

            /*uso da função cadastarDetalhes para inserir detalhes
            sobre cada disciplina cadastrada*/
            cadastrarDetalhes(novaDisciplina);

            /*cadastro de horários em loop dada a possbilidade de 
            uma disciplina ser realizada em vários dias da semana 
            e em horários diferentes*/
            char cadastrarMaisHorario = '\n';
                do{ 

                    //inserir o struct horário na função
                    Horario novoHorario;

                    /*uso da função cadastarHorarios para inserir os 
                    horários de cada disciplina cadastrada*/
                    cadastrarHorarios(novoHorario);

                    //adiciona o horario ao vetor
                    novaDisciplina.horarios.push_back(novoHorario);

                    //possibilidade de cadastro de mais horários
                    std::cout << "Deseja cadastrar mais um horário para a disciplina? (S/N): ";
                    std::cin >> cadastrarMaisHorario;

                    //limpar buffer do teclado
                    if (cadastrarMaisHorario == 'S' || cadastrarMaisHorario == 's'){
                        std::cin.ignore();
                    }

                    while (!(cadastrarMaisHorario == 'S' || cadastrarMaisHorario == 's' || cadastrarMaisHorario == 'N' || cadastrarMaisHorario == 'n')) {
                        std::cout << "Escolha um valor válido (S/N): ";
                        std::cin >> cadastrarMaisHorario;
                    }

                //sair do loop apenas quando o usuário não tiver mais horários para cadastrar
                }while (cadastrarMaisHorario == 'S' || cadastrarMaisHorario == 's');

            //adiciona as informaçoes ao vetor disciplina
            disciplinas.push_back(novaDisciplina);

            //possibilidade de cadastro de mais disciplinas
            std::cout << "Deseja cadastrar mais uma disciplina? (S/N):";
            std::cin >> cadastrarMaisDisciplina;

            //limpar buffer do teclado
            if (cadastrarMaisDisciplina == 'S' || cadastrarMaisDisciplina == 's') {
                std::cin.ignore();
            }
            while (!(cadastrarMaisDisciplina == 'S' || cadastrarMaisDisciplina == 's' || cadastrarMaisDisciplina == 'N' || cadastrarMaisDisciplina == 'n')) {
                std::cout << "Escolha um valor válido (S/N): ";
                std::cin >> cadastrarMaisDisciplina;
            }

        //sair do loop apenas quando o usuário não tiver mais disciplinas para cadastrar
        } while (cadastrarMaisDisciplina == 'S' || cadastrarMaisDisciplina == 's');

    }


    //função que permite realizar alterações nas disciplinas
    void Rotina::editar_disciplina(){

        //Auxiliares
        int disci = 0;
        int func = 0;
        char realizarAlteracao;

        do{

            //perguntar qual disciplina o usuário quer alterar  
            std::cout << "Escolha o número correspente para alterar a disciplina" << std::endl;

            //Listar todas as disciplinas cadastradas
            for(int i=0; i<disciplinas.size(); i++){
                std::cout << "Digite "<< i+1 << " - " << disciplinas[i]._nome << std::endl;
            }

            std::cin >> disci;

            //Usuário escolhe qual informação deseja alterar
            std::cout << "Digite 1 - se você quiser alterar o nome" << std::endl;
            std::cout << "Digite 2 - se você quiser alterar o código" << std::endl;
            std::cout << "Digite 3 - se você quiser alterar a sala" << std::endl;
            std::cout << "Digite 4 - se você quiser alterar o prédio" << std::endl;
            std::cout << "Digite 5 - se você quiser alterar o horário" << std::endl;

            std::cin >> func;

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
            }

            //Possibilidade de realizar mais alterações
            std::cout << "Deseja realizar mais alterações? (S/N): " << std::endl;
            std::cin >> realizarAlteracao;

            //limpar buffer
            if(realizarAlteracao == 'S' || realizarAlteracao == 's') std::cin.ignore();

        //condição parada do loop
        } while(realizarAlteracao == 'S' || realizarAlteracao == 's');

    }

    std::string Rotina::transformarEmDia(int dia){
        
        /*switch que retorna um valor correspondente ao 
        número pré selecionado a um dia da semana */
        switch (dia) {
            case 1:
                return "Segunda";
            case 2:
                return "Terça";
            case 3:
                return "Quarta";
            case 4:
                return "Quinta";
            case 5:
                return "Sexta";
            case 6:
                return "Sábado";
            default:
                return "Dia inválido";
        }
    }

    std::string Rotina::transformarEmHora(int hora){

        /*switch que retorna um valor correspondente ao 
        número pré selecionado a um horário do turno
        noturno da universidade UFMG */
        switch (hora) {
            case 1:
                return "19:00 a 20:40";
            case 2:
                return "20:55 a 22:25";
            default:
                return "Hórario inválido";
        }
    }
    void Rotina::cadastrarDetalhes(Disciplina &novaDisciplina){
        /*cadastro de dados da disciplina colocando o nome e 
        as suas informaçoes em um vetor de disciplinas*/
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
        //cadastro do dia, porém com limitação do dia das semanas ao usuário
        std::cout << "Escolha o dia da semana:\n";
        std::cout << "  1. Segunda  2. Terça  3. Quarta\n  4. Quinta   5. Sexta  6. Sábado\n";
        std::cin >> novoHorario._dia;

        //se nenhum número válido for adicionado se pede para repetir o processo - //ver isso

        //cadastro do horario, porém com limitação.
        std::cout << "Escolha o horário: " << std::endl;
        std::cout << "  1. 19:00 a 20:40\n  2. 20:55 a 22:25\n";
        std::cin >> novoHorario._hora;

        //se nenhum número válido for adicionado se pede para repetir o processo
        while (novoHorario._hora < 1 || novoHorario._hora > 2){
        std::cout << "Escolha um valor válido: ";
        std::cin >> novoHorario._hora;
        }
    }


void Rotina::informacoes_disciplina(){

    //auxiliares
    std::string numerosdias[] = {"1", "2", "3", "4", "5", "6"}; 
    std::string numerohoras[] = {"1", "2"};
    std::string diaSemana[] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sabado"};
    std::string horario[] = {"19:00 a 20:40", "20:55 a 22:25"};

    //loop que imprimi na tela as disciplinas cadastradas
    for(int i = 0; i<disciplinas.size(); i++){
        std::cout << "- " << disciplinas[i]._nome << "(" << disciplinas[i]._codigo << ")" << std::endl;
        std::cout << "    " << disciplinas[i]._predio << "-" << disciplinas[i]._sala << std::endl;

        //loop para alterar horários 
        for(int j=0; j<disciplinas[i].horarios.size(); j++){
            std::cout << "    " << transformarEmDia(disciplinas[i].horarios[j]._dia) << " - " << transformarEmHora(disciplinas[i].horarios[j]._hora) << std::endl;
        }
        std::cout << "-----------------------------------------------" << std::endl;
    }

}

bool Rotina::existeDisciplinaNoHorario(int dia, int hora) const {
    for (const auto& disciplina : disciplinas) {
        for (const auto& horario : disciplina.horarios) {
            if (horario._dia == dia && horario._hora == hora) {
                return true;  // Disciplina já cadastrada no horário especificado
            }
        }
    }
    return false;  // Nenhuma disciplina cadastrada no horário especificado
}
