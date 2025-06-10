SRCS = ./src/main.cpp ./src/Game.cpp ./src/utils/TextureManager.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = prog

CXXFLAGS = -Wall

CC = clang++

LIBS = -lSDL3 -lSDL3_image

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS)
