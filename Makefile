BIN = snake
SRC = program.c snake.c play.c grid.c apple.c

$(BIN): $(SRC)
	gcc $(SRC) -o $(BIN) -Wall -W -ansi -Werror -lSDL -lSDL_image -lSDL_ttf
	./$(BIN)
