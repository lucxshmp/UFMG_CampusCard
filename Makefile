# Makefile para o projeto UFMG CampusCard

# Diretórios
BASE_DIR := ..\UFMG_CampusCard
SRC_DIR := $(BASE_DIR)\SRC
INCLUDE_DIR := $(BASE_DIR)\Include
TEST_DIR := ..\tpfinal\UFMG_CampusCard\test
BUILD_DIR := $(BASE_DIR)\build1

# Arquivos
MAIN_SRC := $(BASE_DIR)\main.cpp
REDIREC_SRC := $(SRC_DIR)\redirecionamento.cpp

# Subdiretórios
SUBDIRS_SRC := $(SRC_DIR)\classes_apoio $(SRC_DIR)\classes_identificacao $(SRC_DIR)\classes_mapas \
           	   $(SRC_DIR)\classes_menu $(SRC_DIR)\classes_salas $(SRC_DIR)\classes_tempo \
               $(SRC_DIR)\classes_transacoes $(SRC_DIR)\classes_transporte

SUBDIRS_INCLUDE := $(INCLUDE_DIR)\classes_apoio $(INCLUDE_DIR)\classes_identificacao \
                   $(INCLUDE_DIR)\classes_mapas $(INCLUDE_DIR)\classes_menu \
                   $(INCLUDE_DIR)\classes_salas $(INCLUDE_DIR)\classes_tempo \
                   $(INCLUDE_DIR)\classes_transacoes $(INCLUDE_DIR)\classes_transporte

SUBDIRS := $(SUBDIRS_SRC) $(SUBDIRS_INCLUDE) 

# Bibliotecas
DOCTEST_DIR := $(BASE_DIR)\build\doctest-master
LIBHARU_DIR := $(BASE_DIR)\build\libharu
LIBHARU_INCLUDE := $(LIBHARU_DIR)\build\src

# Compilador e flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall
LDFLAGS := -L$(LIBHARU_DIR) -libhpdf.dll

# Inclui diretórios
INCLUDE := -I$(INCLUDE_DIR) -I$(DOCTEST_DIR) -I$(LIBHARU_INCLUDE) $(foreach dir,$(SUBDIRS),-I$(dir))

SRC_FILES := $(wildcard $(SRC_DIR)\*.cpp $(addsuffix \*.cpp,$(SUBDIRS_SRC)))
OBJ_FILES := $(patsubst $(SRC_DIR)\%.cpp,$(BUILD_DIR)\%.o,$(SRC_FILES))

# Dependências
DEP_FILES := $(OBJ_FILES:.o=.d)

# Alvo principal
MAIN_EXEC := $(BUILD_DIR)\main.exe

# Alvo para testes
TEST_EXEC := $(BUILD_DIR)\tests.exe

# Alvo padrão
all: $(MAIN_EXEC)

# Alvo para executável principal
$(MAIN_EXEC): $(OBJ_FILES) $(MAIN_SRC) $(REDIREC_SRC)
	@mkdir -p $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -MMD -MP -c $(MAIN_SRC) -o $(BUILD_DIR)\main.o
	@$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) $(OBJ_FILES) $(BUILD_DIR)\main.o $(REDIREC_SRC) -o $(MAIN_EXEC)

# Alvo para executar os testes
test: $(TEST_EXEC)
	@set PATH=$(LIBHARU_DIR);%PATH% & $(TEST_EXEC)

# Alvo para executável de testes
$(TEST_EXEC): $(OBJ_FILES) $(wildcard $(TEST_DIR)\*.cpp)
	@mkdir -p $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -I$(DOCTEST_DIR) -MMD -MP -c $(wildcard $(TEST_DIR)\*.cpp) -o $(BUILD_DIR)\tests.o
	@$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) $(OBJ_FILES) $(BUILD_DIR)\tests.o -o $(TEST_EXEC)

# Regra padrão para compilação de arquivos fonte
$(BUILD_DIR)\%.o: $(SRC_DIR)\%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -MMD -MP -c $< -o $@

# Inclui as dependências
-include $(DEP_FILES)

# Alvo para limpeza
clean:
	@del /Q $(BUILD_DIR)

.PHONY: all test clean
