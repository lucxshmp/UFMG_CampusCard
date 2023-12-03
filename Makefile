PROJECT_NAME := ufmgcampuscard

CXX = g++
CXXFLAGS = -std=c++17 -Wall

ST_LIB_PATH := ../ufmg_campuscard/build

INC_DIR = include

SRC_DIR := SRC
TEST_DIR := test 

BIN_DIR := bin
BUILD_DIR := build

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp $(SRC_DIR)/*/*/*.cpp)
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

DEP_FILES := $(SRC_FILES:.cpp=.d)
DEP_FILES += $(TEST_FILES:.cpp=.d)

OBJ_SRC_FILES := $(SRC_FILES:.cpp=.o)
OBJ_TEST_FILES := $(TEST_FILES:.cpp=.o)

-include $(addprefix $(BUILD_DIR)/,$(DEP_FILES))

$(BIN_DIR)/main: $(addprefix $(BUILD_DIR)/,$(OBJ_SRC_FILES))
	@echo "🔧 Building executable 'main' ..."
	@mkdir -p $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) $^ -o $@

run: $(BIN_DIR)/main
	@LD_LIBRARY_PATH=$(ST_LIB_PATH) $(BIN_DIR)/main

build: $(BUILD_DIR)/$(PROJECT_NAME)

$(BUILD_DIR)/$(PROJECT_NAME): $(addprefix $(BUILD_DIR)/,$(OBJ_SRC_FILES))
	@echo "🔧 Preparing library ..."
	@mkdir -p $(BUILD_DIR)
	@$(CXX) -shared $^ -o $(BUILD_DIR)/$(PROJECT_NAME)

$(BUILD_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "🏛️ Building $< ..."
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -D STORAGE_DIR=\"$(STORAGE_DIR)\" -MMD -MP -c $< -o $@ -fPIC

test: $(addprefix $(BIN_DIR)/,$(TEST_FILES))

clean:
	@echo "🧹 Cleaning ..."
	@rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: test