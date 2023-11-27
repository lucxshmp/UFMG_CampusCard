#include "CarteiraEstudante.hpp"


CarteiraEstudante::CarteiraEstudante() : ValidadeCarteira(true) {}

/// @brief função que gera um pdf com uma carteira de estudante virtual atraves
/// da biblioteca "libharu"
/// @param nomeArquivo que você quer gerar 
void CarteiraEstudante::GerarCarteiraDigital(const char* nomeArquivo) {
    
    Usuario AlunoCarteirinha;
    
    /// tratar dados para serem compatíveis com a biblioteca que gera pdf 
    std::string nome = AlunoCarteirinha.getNome();
    long int matricula = AlunoCarteirinha.getMatricula();
    std::string stringMatricula = std::to_string(matricula);
    std::string curso = AlunoCarteirinha.getCurso();
    long int cpf = AlunoCarteirinha.getCPF();
    std::string stringCPF = std::to_string(cpf);
    
    /// inicializar a biblioteca Haru
    HPDF_Doc pdf = HPDF_New(NULL, NULL);
    if (!pdf) {
        std::cerr << "Falha ao criar o documento PDF." << std::endl;
        return;
    }

    /// Adicionar uma página ao documento
    HPDF_Page page = HPDF_AddPage(pdf);
    if (!page) {
        std::cerr << "Falha ao adicionar a página ao documento PDF." << std::endl;
        HPDF_Free(pdf);
        return;
    }

    /// configurar o tamanho da página
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);

    /// inserir texto na página
    HPDF_Page_BeginText(page);

    /// nome da universidade
    HPDF_Page_SetFontAndSize(page, HPDF_LoadTTFont(pdf, "Helvetica-Bold", HPDF_TRUE), 16);
    HPDF_Page_MoveTextPos(page, 50, 750); // Posição centralizada na página
    HPDF_Page_ShowText(page, "Universidade Federal de Minas Gerais");

    /// informações do aluno
    HPDF_Page_SetFontAndSize(page, HPDF_LoadTTFont(pdf, "Helvetica", HPDF_TRUE), 12);
    HPDF_Page_MoveTextPos(page, 50, 700); // Posição do texto na página

    HPDF_Page_ShowText(page, "Nome: ");
    HPDF_Page_ShowText(page, nome.c_str());

    HPDF_Page_MoveTextPos(page, 0, -15);
    
    HPDF_Page_ShowText(page, "Matrícula: ");
    HPDF_Page_ShowText(page, stringMatricula.c_str());
    
    HPDF_Page_MoveTextPos(page, 0, -15);
    
    HPDF_Page_ShowText(page, "Curso: ");
    HPDF_Page_ShowText(page, curso.c_str());
    
    HPDF_Page_MoveTextPos(page, 0, -15);
    
    HPDF_Page_ShowText(page, "CPF: ");
    HPDF_Page_ShowText(page, stringCPF.c_str());

    HPDF_Page_EndText(page);

    /// salvar o PDF no arquivo
    HPDF_SaveToFile(pdf, nomeArquivo);

    /// liberar memoria
    HPDF_Free(pdf);

    std::cout << "Carteira de Estudante gerada com sucesso: " << nomeArquivo << std::endl;
}


/// @brief função que dá informações sobre a carteira fisica do estudante
/// @return a validade da carteira fisica
bool CarteiraEstudante::obterStatusValidade() const {
    return ValidadeCarteira;
}

/// @brief: função que muda o status da validade de uma carteira fisica em caso de perda
/// @param: valor que você quer setar na carteirinha fisica (true = valida, false =  invalida) 
void CarteiraEstudante::definirStatusValidade(bool novo_status) {
    ValidadeCarteira = novo_status;
}

