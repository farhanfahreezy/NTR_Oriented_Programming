GPP				= g++

SOURCE			= src
OUTPUT			= bin

BIN_NAME		= ntr

CPPFLAGS		= -I$(SOURCE)

# build			- Builds a single executable file
build: all clean-obj

# all			- Compiles object files and build an executable
all: player
	@$(GPP) $(CPPFLAGS) $(OUTPUT)/*.o							-o $(OUTPUT)/$(BIN_NAME).exe

# player		- Builds all source files in the folder "Player"
player:
	@$(GPP) $(CPPFLAGS) -c $(SOURCE)/Player/Player.cpp			-o $(OUTPUT)/Player.o

# TODO: Add more recipes for other grouped source files

# clean-obj		- Removes all object files
clean-obj:
ifeq ($(OS),Windows_NT)
	@del /q $(OUTPUT)\\*.o
else
	@rm -f $(OUTPUT)/*.o
endif
