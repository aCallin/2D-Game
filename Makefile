CC = g++
EXEC = Game.exe

SRC = src/Main.cpp\
	  src/Engine.cpp\
	  src/Scene.cpp\
	  src/Button.cpp\
	  src/MainMenuScene.cpp\
	  src/OptionsScene.cpp\
	  src/Player.cpp\
	  src/PlayerController.cpp\
	  src/PlayerDrawer.cpp\
	  src/PlayingScene.cpp
OBJ = $(patsubst src/%.cpp,obj/%.o,$(SRC))

INCLUDES = -I"SFML-2.5.1/include"
LIBRARIES = -L"SFML-2.5.1/lib"\
			-lsfml-system\
			-lsfml-window\
			-lsfml-graphics\
			-lsfml-audio\
			-lsfml-network

.PHONY: all
all: $(OBJ)
	$(CC) $^ -o $(EXEC) $(LIBRARIES)

.PHONY: run
run: all
	@$(EXEC)

.PHONY: clean
clean:
	@IF EXIST obj RMDIR /S /Q obj
	@IF EXIST $(EXEC) DEL /F /Q $(EXEC)

$(OBJ): obj/%.o : src/%.cpp
	@IF NOT EXIST obj MKDIR obj
	$(CC) $(INCLUDES) -c $< -o $@
