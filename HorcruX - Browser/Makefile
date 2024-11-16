# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -std=c++17 -fPIC -DYYDEBUG=1 \
           -I$(SRC_DIR) \
           -I$(BUILD_DIR) \
           -I$(CORE_DIR) \
           -I$(BROWSER_DIR) \
           -I$(NETWORK_DIR) \
           -I$(RENDERER_DIR) \
           -I$(UTILS_DIR) \
           $(shell pkg-config --cflags Qt5Widgets Qt5Network Qt5Concurrent)
LDFLAGS = $(shell pkg-config --libs Qt5Widgets Qt5Network Qt5Concurrent)

# Directories
SRC_DIR = src
BUILD_DIR = build
CORE_DIR = $(SRC_DIR)/core
BROWSER_DIR = $(SRC_DIR)/browser
NETWORK_DIR = $(SRC_DIR)/network
RENDERER_DIR = $(SRC_DIR)/renderer
UTILS_DIR = $(SRC_DIR)/utils

# Output
TARGET = $(BUILD_DIR)/html_parser

# Source files
SRCS = $(wildcard $(CORE_DIR)/*.cpp) \
       $(wildcard $(BROWSER_DIR)/*.cpp) \
       $(wildcard $(NETWORK_DIR)/*.cpp) \
       $(wildcard $(RENDERER_DIR)/*.cpp) \
       $(wildcard $(UTILS_DIR)/*.cpp) \
       $(SRC_DIR)/main.cpp

# Object files
OBJS = $(BUILD_DIR)/ast.o \
       $(BUILD_DIR)/lex.yy.o \
       $(BUILD_DIR)/parser.tab.o \
       $(BUILD_DIR)/parser.o \
       $(BUILD_DIR)/renderer.o \
       $(BUILD_DIR)/main.o \
       $(BUILD_DIR)/browser_window.o \
       $(BUILD_DIR)/tab_manager.o \
       $(BUILD_DIR)/network_manager.o \
       $(BUILD_DIR)/thread_pool_manager.o \
       $(BUILD_DIR)/history_manager.o \
       $(BUILD_DIR)/moc_renderer.o \
       $(BUILD_DIR)/moc_browser_window.o \
       $(BUILD_DIR)/moc_tab_manager.o \
       $(BUILD_DIR)/moc_network_manager.o \
       $(BUILD_DIR)/moc_history_manager.o

# MOC files
MOC_HEADERS = $(RENDERER_DIR)/renderer.hpp \
              $(BROWSER_DIR)/browser_window.hpp \
              $(BROWSER_DIR)/tab_manager.hpp \
              $(NETWORK_DIR)/network_manager.hpp \
              $(UTILS_DIR)/history_manager.hpp

MOC_SOURCES = $(addprefix $(BUILD_DIR)/moc_,$(notdir $(MOC_HEADERS:.hpp=.cpp)))

# Rules
all: create_dirs $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS) -lfl

# Create necessary directories
create_dirs:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p data/fetched_files
	@mkdir -p data/html_dataset

# MOC rules
$(BUILD_DIR)/moc_renderer.cpp: $(RENDERER_DIR)/renderer.hpp
	moc $< -o $@

$(BUILD_DIR)/moc_browser_window.cpp: $(BROWSER_DIR)/browser_window.hpp
	moc $< -o $@

$(BUILD_DIR)/moc_tab_manager.cpp: $(BROWSER_DIR)/tab_manager.hpp
	moc $< -o $@

$(BUILD_DIR)/moc_network_manager.cpp: $(NETWORK_DIR)/network_manager.hpp
	moc $< -o $@

$(BUILD_DIR)/moc_history_manager.cpp: $(UTILS_DIR)/history_manager.hpp
	moc $< -o $@

# MOC object compilation rules
$(BUILD_DIR)/moc_%.o: $(BUILD_DIR)/moc_%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Flex and Bison rules
$(BUILD_DIR)/lex.yy.c: $(CORE_DIR)/lexer.l $(BUILD_DIR)/parser.tab.h
	flex -o $@ $<

$(BUILD_DIR)/parser.tab.c $(BUILD_DIR)/parser.tab.h: $(CORE_DIR)/parser.y
	bison -d $< -o $(BUILD_DIR)/parser.tab.c

# Compilation rules
$(BUILD_DIR)/%.o: $(SRC_DIR)/*/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(BUILD_DIR)/%.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all clean create_dirs