CC = g++
CFLAGS = -c -Wall -std=c++11
LDFLAGS =
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:src/%.cpp=build/%.o)
EXECUTABLE = tron

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS) -lSDL2

build/%.o: src/%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(EXECUTABLE) build/*.o