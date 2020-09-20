BIN = snake.exe
SRC = src/program.c src/snake.c src/play.c src/grid.c src/apple.c

$(BIN): $(SRC)
	gcc $(SRC) -o $(BIN) -Wall -W -ansi -Werror -lSDL -lSDL_image -lSDL_ttf
	./$(BIN)
