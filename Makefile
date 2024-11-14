CXX = g++
CXXFLAGS = -Wall -g -std=c++17 -fPIC -DYYDEBUG=1 $(shell pkg-config --cflags Qt5Widgets Qt5Network)
LDFLAGS = $(shell pkg-config --libs Qt5Widgets Qt5Network)

TARGET = html_parser
OBJS = ast.o lex.yy.o parser.tab.o parser.o renderer.o moc_renderer.o main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS) -lfl

moc_renderer.cpp: renderer.hpp
	moc renderer.hpp -o moc_renderer.cpp

lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS) lex.yy.c parser.tab.c parser.tab.h moc_renderer.cpp

.PHONY: all clean