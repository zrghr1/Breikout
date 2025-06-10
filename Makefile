SRCS = ./src/main.cpp ./src/Game.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = prog

CXXFLAGS = -Wall

CC = clang++

LIBS = -lSDL3

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS)
