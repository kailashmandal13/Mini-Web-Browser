# Makefile for HTML parser

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Targets
TARGET = html_parser

# Files
FLEX_FILE = lexer.l
BISON_FILE = parser.y
AST_SRC = AST.cpp
AST_OBJ = AST.o
BISON_C_FILE = parser.tab.c
BISON_H_FILE = parser.tab.h
LEX_C_FILE = lex.yy.c

# Objects
OBJECTS = parser.tab.o lex.yy.o $(AST_OBJ)

# Rules
all: $(TARGET)

# Generate parser files from Bison
parser.tab.c parser.tab.h: $(BISON_FILE)
	bison -d $(BISON_FILE)

# Generate lexer file from Flex
lex.yy.c: $(FLEX_FILE)
	flex $(FLEX_FILE)

# Compile AST source file
$(AST_OBJ): $(AST_SRC)
	$(CXX) -c $(AST_SRC) $(CXXFLAGS)

# Compile Bison output file
parser.tab.o: parser.tab.c parser.tab.h
	$(CXX) -c parser.tab.c $(CXXFLAGS)

# Compile Flex output file
lex.yy.o: lex.yy.c
	$(CXX) -c lex.yy.c $(CXXFLAGS)

# Link all objects to create the executable
$(TARGET): $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

# Clean up build files
clean:
	rm -f *.o parser.tab.* lex.yy.c $(TARGET)
