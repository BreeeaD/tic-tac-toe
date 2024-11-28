CXX = g++
CXXFLAGS = -std=c++17 -I"E:/vcPKG/vcpkg/installed/x64-windows/include" -Wall -Wextra
LDFLAGS = -L"E:/vcPKG/vcpkg/installed/x64-windows/lib" -lsqlite3

LIBRARY = libgame.a

SOURCES = board.cpp player.cpp gameEngine.cpp cell.cpp point.cpp
HEADERS = board.hpp player.hpp gameEngine.hpp cell.hpp point.hpp
OBJECTS = $(SOURCES:.cpp=.o)

MAIN = main.cpp
EXECUTABLE = game

all: $(LIBRARY) $(EXECUTABLE)

$(LIBRARY): $(OBJECTS)
	@ar rcs $@ $^

$(EXECUTABLE): $(MAIN) $(LIBRARY)
	$(CXX) $(CXXFLAGS) $(MAIN) -o $(EXECUTABLE) $(LDFLAGS) -L. -lgame

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q *.o *.a $(EXECUTABLE)