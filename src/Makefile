CC = g++
CFLAGS = -g
LDFLAGS = -lGL -lGLU -lBox2D -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

exec = ../space-game
headers = $(wildcard *.h)
sources = $(wildcard *.cpp)
objects = $(sources:.cpp=.o)


all: $(exec)

$(exec): $(objects)
	$(CC) -o $(exec) $(objects) $(CFLAGS) $(LDFLAGS)

%.o: %.cpp $(headers)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:  
	rm -f $(objects) $(exec)
