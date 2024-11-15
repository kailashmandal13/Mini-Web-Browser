CXX = g++
CXXFLAGS = -Wall -g -std=c++17 -fPIC -DYYDEBUG=1 \
           $(shell pkg-config --cflags Qt5Widgets Qt5Network Qt5Concurrent)
LDFLAGS = $(shell pkg-config --libs Qt5Widgets Qt5Network Qt5Concurrent)

TARGET = html_parser
OBJS = ast.o lex.yy.o parser.tab.o parser.o renderer.o main.o \
       browser_window.o tab_manager.o network_manager.o thread_pool_manager.o \
       moc_renderer.o moc_browser_window.o moc_tab_manager.o \
       moc_network_manager.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS) -lfl

# MOC rules for Qt classes
moc_renderer.cpp: renderer.hpp
	moc renderer.hpp -o moc_renderer.cpp

moc_browser_window.cpp: browser_window.hpp
	moc browser_window.hpp -o moc_browser_window.cpp

moc_tab_manager.cpp: tab_manager.hpp
	moc tab_manager.hpp -o moc_tab_manager.cpp

moc_network_manager.cpp: network_manager.hpp
	moc network_manager.hpp -o moc_network_manager.cpp

lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS) lex.yy.c parser.tab.c parser.tab.h \
	moc_renderer.cpp moc_network_manager.cpp moc_browser_window.cpp \
	moc_tab_manager.cpp

.PHONY: all clean