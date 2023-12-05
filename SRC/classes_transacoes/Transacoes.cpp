#include "./Transacoes.hpp"
#include <hpdf.h>


Saldo saldo;
Usuario usuario;

//inicializando a classe
Transacoes::Transacoes(){
    confirma_pagamento=false;
    confirma_deposito=false;
}
//Getters
bool Transacoes::get_pagamento(){
    return confirma_pagamento;
}
bool Transacoes::get_deposito(){
    return confirma_deposito;
}
//--------------------------------------------------
//Setters
void Transacoes::set_pagamento(bool pagamento){
    confirma_pagamento= pagamento;
}
void Transacoes::set_deposito(bool deposito){
    confirma_deposito= deposito;
}
//---------------------------------------------------

void Transacoes::pagamento(){
    if (confirma_pagamento==true){
        saldo.diminuir_saldo(usuario.getNivelFump());
        std::cout<<"Pagamento confirmado"<<std::endl;
    }
    else{
        std::cout<<"Houve um erro no pagamento"<<std::endl;
    }
}
void Transacoes::deposito(double valor){
    if (confirma_deposito==true){
        saldo.adicionar_saldo(valor); //O zero é apenas um valor qualquer para completar a lógica da transação. Será modificado.
        std::cout<<"Deposito confirmado"<<std::endl;
    }
    else{
        std::cout<<"Houve um erro no deposito"<<std::endl;
    }
}
void Transacoes::consultar_saldo(){
    std::cout<<"Saldo Atual: "<<saldo.retornar_saldo_atual()<<std::endl;
}

void preenche_pdf(HPDF_Page page) {
    const char* imagemArquivo = "./brasao.png";
    HPDF_Image imagem = HPDF_LoadPngImageFromFile(page->pdf, imagemArquivo);
    if (imagem) {
        // Ajustar o tamanho da imagem conforme necessário
        HPDF_REAL largura = HPDF_Image_GetWidth(imagem);
        HPDF_REAL altura = HPDF_Image_GetHeight(imagem);

        // Posicionar e desenhar a imagem na página
        HPDF_Page_DrawImage(page, imagem, 50, 50, largura, altura);
    } else {
        std::cerr << "Erro ao carregar a imagem: " << imagemArquivo << std::endl;
    }
    // Adicionar texto à página
    HPDF_Page_BeginText(page);
    HPDF_Page_MoveTextPos(page, 50, HPDF_Page_GetHeight(page) - 50);
    HPDF_Page_ShowText(page, "MINISTERIO DA FAZENDA");
    HPDF_Page_ShowText(page, "SECRETARIA DO TESOURO NACIONAL");
    HPDF_Page_EndText(page);

    
}


void gerar_GRU(const char* guia) {
    // Inicializar o documento PDF
    HPDF_Doc pdf = HPDF_New(NULL, NULL);
    if (!pdf) {
        std::cerr << "Erro ao criar o documento PDF." << std::endl;
        return;
    }

    // Adicionar uma página ao documento
    HPDF_Page page = HPDF_AddPage(pdf);
    if (!page) {
        std::cerr << "Erro ao adicionar página ao documento PDF." << std::endl;
        HPDF_Free(pdf);
        return;
    }

    // Definir o tamanho da página como A4 (opcional)
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);

    // Adicionar conteúdo à página
    preenche_pdf(page);

    // Iniciar a gravação no arquivo
    if (HPDF_SaveToFile(pdf, guia) != HPDF_OK) {
        std::cerr << "Erro ao salvar o arquivo PDF." << std::endl;
        HPDF_Free(pdf);
        return;
    }

    // Liberar recursos
    HPDF_Free(pdf);

    std::cout << "Guia de pagamento gerada com sucesso: " << guia << std::endl;
}