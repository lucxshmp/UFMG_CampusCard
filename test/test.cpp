#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "CarteiraEstudante.hpp"
#include "eventos.hpp"
#include "rotina.hpp" 
#include "validacao.hpp"
#include "MapasCampus.hpp"
#include "menuDepartamento.hpp"
#include "menuUteis.hpp"
#include "SalasUteis.hpp"
#include "MapasInterno.hpp"
#include "redirecionamento.hpp"
#include "menuMapas.hpp"


TEST_CASE("CarteiraEstudante - GerarCarteiraDigital") {
    CarteiraEstudante carteira;
    const char* arquivo = "carteira_teste.pdf";

    // Chame a função de geração
    carteira.GerarCarteiraDigital(arquivo);

    // Verifique se o arquivo foi criado
    std::ifstream file(arquivo);
    REQUIRE(file.good());
    file.close();

    // Remova o arquivo de teste
    std::remove(arquivo);
}

TEST_CASE("CarteiraEstudante - obterStatusValidade e definirStatusValidade") {
    CarteiraEstudante carteira;

    // Verifique o status de validade padrão
    CHECK(carteira.obterStatusValidade() == true);

    // Mude o status de validade e verifique novamente
    carteira.definirStatusValidade(false);
    CHECK(carteira.obterStatusValidade() == false);

    // Mude o status de validade novamente e verifique
    carteira.definirStatusValidade(true);
    CHECK(carteira.obterStatusValidade() == true);
}


    //TESTES CLASSES DE TEMPOS
    TEST_CASE("teste da validacao da data"){
        
        Validacao validacao;
    
        //teste de formatos de data válidos
        CHECK(validacao.validarFormatoData("01-01-2023") == true);
        CHECK(validacao.validarFormatoData("06-03-2026") == true);
    
        //teste de formatos de datas inválidas
        CHECK(validacao.validarFormatoData("01/01/2023") == false);
        CHECK(validacao.validarFormatoData("28-14-2023") == false);
        CHECK(validacao.validarFormatoData("42-11-2023") == false);
        CHECK(validacao.validarFormatoData("31-00-2023") == false);
    
    }
    
    
    TEST_CASE("teste da validacao da hora"){
        
        Validacao validacao;
        //teste de formatos de horas válidos
        CHECK(validacao.validarFormatoHora("12:00") == true);
        CHECK(validacao.validarFormatoHora("12:59") == true);
        CHECK(validacao.validarFormatoHora("03:40") == true);
        CHECK(validacao.validarFormatoHora("00:34") == true);
    
        //teste de formatos de horas inválidos
        CHECK(validacao.validarFormatoHora("50:00") == false);
        CHECK(validacao.validarFormatoHora("12/00") == false);
        CHECK(validacao.validarFormatoHora("12:68") == false);
    }
    
    
    TEST_CASE("teste de parsing de data e hora"){
        Eventos evento;
    
        //teste de parsing
        auto resultado = evento.parseDateTime("01/-01/-2023", "12:00");
        CHECK(resultado.time_since_epoch().count() > 0);
    }
    
    TEST_CASE("teste da ordenalização por prazos"){
        std::vector<Eventos> tarefas;
    
        //adicionando tarefa com prazo menor
        Eventos tarefa1;
        tarefa1.setNome("Tarefa 1");
        tarefa1.setData("21-12-2023");
        tarefa1.setHora("12:00");
    
        //adicionando tarefa com maior prazo
        Eventos tarefa2;
        tarefa2.setNome("Tarefa 2");
        tarefa2.setData("21-12-2024");
        tarefa2.setHora("14:00");
    
        //adicionado tarefa com prazo intermediário
        Eventos tarefa3;
        tarefa3.setNome("Tarefa 3");
        tarefa3.setData("21-12-2023");
        tarefa3.setHora("14:00");
    
        //adicionando tarefas no vetor 
        tarefas.push_back(tarefa1);
        tarefas.push_back(tarefa2);
        tarefas.push_back(tarefa3);
    
        //usando a função de ordenamento por prazos
        std::sort(tarefas.begin(), tarefas.end());
    
        //conferindo se elas estão na posição que deveriam
        CHECK(tarefas[0].getNome() == "Tarefa 1");
        CHECK(tarefas[1].getNome() == "Tarefa 3");
        CHECK(tarefas[2].getNome() == "Tarefa 2");
        
    }
    
    TEST_CASE("cadastro e leitura de arquivos"){
        std::vector<Eventos> tarefas;

        //adicionando uma tarefa a eventos
        Eventos tarefaOriginal;
        tarefaOriginal.setNome("Tarefa Original");
        tarefaOriginal.setDescricao("Descrição Original");
        tarefaOriginal.setData("29-12-2023");
        tarefaOriginal.setHora("12:00");
        tarefaOriginal.setDisciplina("Disciplina Original");

        tarefas.push_back(tarefaOriginal);

        //salvando a tarefa em um arquivo
        Eventos::salvarTarefasEmArquivo(tarefas, "test_arquivo.txt");

        tarefas.clear();

        //lendo a tarefa do arquivo
        Eventos::carregarTarefasDeArquivo(tarefas, "test_arquivo.txt");

        //verificando se elas são iguais
        REQUIRE(tarefas.size() == 1);
        CHECK(tarefas[0].getNome() == tarefaOriginal.getNome());
        CHECK(tarefas[0].getDescricao() == tarefaOriginal.getDescricao());
        CHECK(tarefas[0].getData() == tarefaOriginal.getData());
        CHECK(tarefas[0].getHora() == tarefaOriginal.getHora());
        CHECK(tarefas[0].getDisciplina() == tarefaOriginal.getDisciplina());
        
    }


    TEST_CASE("teste cadastro de disciplina"){
        Rotina rotina;

        //adicionando uma disciplina aos vetores
        Rotina::Disciplina disciplina;
        disciplina._codigo = "25263";
        disciplina._nome = "Disciplina Teste";
        disciplina._predio = "Prédio Teste";
        disciplina._sala = "Sala 101";

        Rotina::Horario horario1{1, 1};
        Rotina::Horario horario2{3, 2};

        disciplina.horarios.push_back(horario1);
        disciplina.horarios.push_back(horario2);
        
        rotina.cadastrarDisciplina();

        //obtendo as disciplinas cadastradas
        const auto& disciplinasCadastradas = rotina.getDisciplinas();

        //verificando se o cadastro está certo
        REQUIRE(disciplinasCadastradas.size() == 1);
        CHECK(disciplinasCadastradas[0]._codigo == disciplina._codigo);
        CHECK(disciplinasCadastradas[0]._nome == disciplina._nome);
        CHECK(disciplinasCadastradas[0]._predio == disciplina._predio);
        CHECK(disciplinasCadastradas[0]._sala == disciplina._sala);
        CHECK(disciplinasCadastradas[0].horarios == disciplina.horarios);
        
    }


    TEST_CASE("cadastro e leitura de um arquivo de disciplinas"){
        Rotina rotina;

        //adicionando uma disciplina
        Rotina::Disciplina disciplina;
        disciplina._codigo = "COD456";
        disciplina._nome = "Outra Disciplina";
        disciplina._predio = "Prédio Outro";
        disciplina._sala = "Sala 202";

        Rotina::Horario horario{2, 2};
        disciplina.horarios.push_back(horario);

        //adicionando-a a um arquivo
        rotina.salvarDisciplinasEmArquivo("test_disciplinas.txt");

        rotina.getDisciplinas().clear();

        //lendo as disciplinas do arquivo
        rotina.carregarDisciplinasDeArquivo("test_disciplinas.txt");

        //obtendo as disciplinas do vector
        const auto& disciplinasArquivo = rotina.getDisciplinas();

        //verificando se elas estão iguais
        REQUIRE(disciplinasArquivo.size() == 1);
        CHECK(disciplinasArquivo[0]._codigo == disciplina._codigo);
        CHECK(disciplinasArquivo[0]._nome == disciplina._nome);
        CHECK(disciplinasArquivo[0]._predio == disciplina._predio);
        CHECK(disciplinasArquivo[0]._sala == disciplina._sala);
        CHECK(disciplinasArquivo[0].horarios == disciplina.horarios);
        
    }

    TEST_CASE("teste para marcar outra disciplina no mesmo horário"){
        Rotina rotina;

        //adicionando a primeira disciplina
        Rotina::Disciplina disciplina1;
        disciplina1._codigo = "COD789";
        disciplina1._nome = "Disciplina Marcacao";
        disciplina1._predio = "Prédio Marcar";
        disciplina1._sala = "Sala 303";

        Rotina::Horario horario1{1, 1};
        Rotina::Horario horario2{1, 2};

        disciplina1.horarios.push_back(horario1);
        disciplina1.horarios.push_back(horario2);

        rotina.getDisciplinas().push_back(disciplina1);

        //adicionando disciplina ao mesmo horário
        Rotina::Disciplina disciplina2;
        disciplina2._codigo = "COD123";
        disciplina2._nome = "Outra Disciplina";
        disciplina2._predio = "Outro Prédio";
        disciplina2._sala = "Sala 101";

        Rotina::Horario horario3{1, 1};  
        Rotina::Horario horario4{2, 1};  

        disciplina2.horarios.push_back(horario3);
        disciplina2.horarios.push_back(horario4);

        rotina.getDisciplinas().push_back(disciplina2);

        CHECK(rotina.existeDisciplinaNoHorario(1, 1) == true);  
        CHECK(rotina.existeDisciplinaNoHorario(2, 1) == false);  
        CHECK(rotina.existeDisciplinaNoHorario(1, 2) == false); 
    
    }

    TEST_CASE("teste da grade semanal"){
        Rotina rotina;
        Grade_Semanal grade;

        //adicionando uma disciplina
        Rotina::Disciplina disciplina1;
        disciplina1._nome = "Disciplina 1";
        Rotina::Horario horario1{1, 2};
        disciplina1.horarios.push_back(horario1);

        Rotina::Disciplina disciplina2;
        disciplina2._nome = "Disciplina 2";
        Rotina::Horario horario2{2, 1};
        disciplina2.horarios.push_back(horario2);

        rotina.getDisciplinas().push_back(disciplina1);
        rotina.getDisciplinas().push_back(disciplina2);

        grade.criarGrade(rotina);

        std::vector<std::vector<std::string>> gradeSemanal = grade.getGradeSemanal();

        //verificacão se está correspondente ao esperado
        CHECK(gradeSemanal[1][1] == "Disciplina 1");  
        CHECK(gradeSemanal[2][2] == "Disciplina 2");  
        
    }
    //FIM DOS TESTES DE CLASSE DE TEMPO


    // menuDepartamento_test.cpp

TEST_CASE("MenuDepartamento - Redirecionamento de Links") {
    media::ui::MenuDepartamento menu;

    SUBCASE("Redirecionamento ICEx") {
        CHECK(menu.next(1) == nullptr);
    }

    SUBCASE("Redirecionamento Engenharia") {
        CHECK(menu.next(2) == nullptr);
    }

    SUBCASE("Redirecionamento FACE") {
        CHECK(menu.next(3) == nullptr);
    }

    SUBCASE("Redirecionamento IGC") {
        CHECK(menu.next(4) == nullptr);
    }

    SUBCASE("Redirecionamento Escola de Musica") {
        CHECK(menu.next(5) == nullptr);
    }

    SUBCASE("Redirecionamento ICB") {
        CHECK(menu.next(6) == nullptr);
    }
}

// menuUteis_test.cpp

TEST_CASE("MenuUteis - Cadastro de Sala") {
    media::ui::MenuUteis menu;

    SUBCASE("Cadastrar Sala") {
        CHECK(menu.next(1) == nullptr);
    }

    SUBCASE("Consultar Salas Cadastradas") {
        CHECK(menu.next(2) == nullptr);
    }

    SUBCASE("Salvar e Sair") {
        CHECK(menu.next(3) == nullptr);
    }
}

// SalasUteis_test.cpp


TEST_CASE("CadastroSala - Manipulação de Cadastro") {
    CadastroSala cadastro;

    SUBCASE("Cadastrar e Exibir Sala") {
        cadastro.cadastrarSala("Sala Teste", "Predio Teste", "123");
        CHECK_NOTHROW(cadastro.exibirSalas());
    }

    SUBCASE("Salvar e Carregar Cadastro") {
        cadastro.salvarCadastro();
        CadastroSala novoCadastro;
        CHECK_NOTHROW(novoCadastro.carregarCadastro());
    }
}

// redirecionamento_test.cpp

TEST_CASE("Redirecionamento - Testes de Redirecionamento") {
    SUBCASE("Redirecionamento para Link Válido") {
        std::string link = "https://github.com/luigidcsoares";
        CHECK_NOTHROW(Redirecionamento::redirecionarLink(link));
    }

    SUBCASE("Redirecionamento para Link Inválido") {
        std::string link = "link_invalido";
        CHECK_NOTHROW(Redirecionamento::redirecionarLink(link));
        // Aqui você pode adicionar uma verificação mais específica
        // para garantir que o redirecionamento para um link inválido
        // seja tratado conforme o esperado.
    }
}

// menuMapas_test.cpp

TEST_CASE("MenuMapas - Testes de Navegação") {
    media::ui::MenuMapas menu;

    SUBCASE("Navegação para Mapas dos Campi") {
        CHECK_NOTHROW(menu.next(1));
    }

    SUBCASE("Navegação para Mapas do Interno") {
        CHECK_NOTHROW(menu.next(2));
    }

    SUBCASE("Navegação com Opção Inválida") {
        CHECK(menu.next(3) == nullptr);
    }
}

// MapasInterno_test.cpp

TEST_CASE("MapasInterno - Testes de Redirecionamento") {
    media::ui::MapasInterno interno;

    SUBCASE("Redirecionamento para Linha 1") {
        CHECK_NOTHROW(interno.next(1));
    }

    SUBCASE("Redirecionamento para Linha 2") {
        CHECK_NOTHROW(interno.next(2));
    }

    SUBCASE("Redirecionamento para Linha 3") {
        CHECK_NOTHROW(interno.next(3));
    }

    SUBCASE("Redirecionamento para Linha 3 - Atendimento BH-Tec") {
        CHECK_NOTHROW(interno.next(4));
    }

    SUBCASE("Redirecionamento para Linha 4") {
        CHECK_NOTHROW(interno.next(5));
    }

    SUBCASE("Redirecionamento para Linha 4 - Atendimento McDonalds") {
        CHECK_NOTHROW(interno.next(6));
    }

    SUBCASE("Redirecionamento para Linha 4 - Atendimento McDonalds e BH-Tec") {
        CHECK_NOTHROW(interno.next(7));
    }

    SUBCASE("Redirecionamento para Linha Sabado") {
        CHECK_NOTHROW(interno.next(8));
    }

    SUBCASE("Navegação com Opção Inválida") {
        CHECK(interno.next(9) == nullptr);
    }
}

// MapasCampus_test.cpp


TEST_CASE("MapasCampus - Testes de Redirecionamento") {
    media::ui::MapasCampus campus;

    SUBCASE("Redirecionamento para Campus Pampulha") {
        CHECK_NOTHROW(campus.next(1));
    }

    SUBCASE("Redirecionamento para Campus Centro BH") {
        CHECK_NOTHROW(campus.next(2));
    }

    SUBCASE("Redirecionamento para Campus Montes Claros") {
        CHECK_NOTHROW(campus.next(3));
    }

    SUBCASE("Navegação com Opção Inválida") {
        CHECK(campus.next(4) == nullptr);
    }
}
