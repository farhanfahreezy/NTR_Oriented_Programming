GPP				= g++

SOURCE_FOLDER	= src
OUTPUT_FOLDER	= bin
TEST_FOLDER		= test
TEST_BIN_FOLDER	= $(OUTPUT_FOLDER)/test

BIN_NAME		= ntr
# add the flag ARGS=... to supply make with additional g++ compile flags
CPPFLAGS		= -I$(SOURCE_FOLDER) $(ARGS)

### BUILD RECIPES ###
# build			- Builds a single executable file
build: build-all clean-obj

# build-all		- Compiles object files and builds a release-executable file
build-all: clean-obj all
	@$(GPP) $(CPPFLAGS) $(OUTPUT_FOLDER)/*.o									-o $(OUTPUT_FOLDER)/$(BIN_NAME).exe

### RELEASE COMPILE RECIPES ###
# all			- Compiles object files
all: game inv-holder card deck table player io

# game			- Builds all source files in the folder "Game"
game:
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_FOLDER)/Game/GameState.cpp					-o $(OUTPUT_FOLDER)/GameState.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_FOLDER)/Game/GameCommands.cpp				-o $(OUTPUT_FOLDER)/GameCommands.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_FOLDER)/Game/GameAbility.cpp				-o $(OUTPUT_FOLDER)/GameAbility.o

# inv-holder	- Builds all source files in the folder "InventoryHolder"
inv-holder:
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_FOLDER)/InventoryHolder/InventoryHolder.cpp	-o $(OUTPUT_FOLDER)/InventoryHolder.o

# card			- Builds all source files in the folder "Card"
card:
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_FOLDER)/Card/RegularCard.cpp				-o $(OUTPUT_FOLDER)/RegularCard.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_FOLDER)/Card/AbilityCard.cpp				-o $(OUTPUT_FOLDER)/AbilityCard.o

# deck			- Builds all source files in the folder "Deck"
deck:
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_FOLDER)/Deck/Deck.cpp						-o $(OUTPUT_FOLDER)/Deck.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_FOLDER)/Deck/RegularDeck.cpp				-o $(OUTPUT_FOLDER)/RegularDeck.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_FOLDER)/Deck/AbilityDeck.cpp				-o $(OUTPUT_FOLDER)/AbilityDeck.o

# table			- Builds all source files in the folder "Table"
table:
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_FOLDER)/Table/Table.cpp						-o $(OUTPUT_FOLDER)/Table.o

# player		- Builds all source files in the folder "Player"
player:
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_FOLDER)/Player/Player.cpp					-o $(OUTPUT_FOLDER)/Player.o

# io			- Builds all source files in the folder "IO"
io:
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_FOLDER)/IO/Command.cpp						-o $(OUTPUT_FOLDER)/Command.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_FOLDER)/IO/CommandParser.cpp				-o $(OUTPUT_FOLDER)/CommandParser.o

### UTILITIES ###
# clean-obj		- Removes all object files
clean-obj:
ifeq ($(OS),Windows_NT)
	@del /s /q $(OUTPUT_FOLDER)\\*.o
else
	@rm -f $(OUTPUT_FOLDER)/*.o
endif

### TESTS ###
# test-state
test-state: clean-obj testb-state
	@$(TEST_BIN_FOLDER)/GameStateTest.exe

testb-state: all
	@$(GPP) $(CPPFLAGS) $(TEST_FOLDER)/GameStateTest.cpp $(OUTPUT_FOLDER)/*.o -o $(TEST_BIN_FOLDER)/GameStateTest.exe

# test-regdeck
test-regdeck: clean-obj testb-regdeck
	@$(TEST_BIN_FOLDER)/RegularDeckTest.exe

testb-regdeck: all
	@$(GPP) $(CPPFLAGS) $(TEST_FOLDER)/RegularDeckTest.cpp $(OUTPUT_FOLDER)/*.o -o $(TEST_BIN_FOLDER)/RegularDeckTest.exe

# test-abdeck
test-abdeck: clean-obj testb-abdeck
	@$(TEST_BIN_FOLDER)/AbilityDeckTest.exe

testb-abdeck: all
	@$(GPP) $(CPPFLAGS) $(TEST_FOLDER)/AbilityDeckTest.cpp $(OUTPUT_FOLDER)/*.o -o $(TEST_BIN_FOLDER)/AbilityDeckTest.exe

# test-main
test-main: clean-obj testb-main
	@$(TEST_BIN_FOLDER)/main.exe

testb-main: all
	@$(GPP) $(CPPFLAGS) $(TEST_FOLDER)/main.cpp $(OUTPUT_FOLDER)/*.o -o $(TEST_BIN_FOLDER)/main.exe

# test-cmd
test-cmd: clean-obj testb-cmd
	@$(TEST_BIN_FOLDER)/CommandTest.exe

testb-cmd: io
	@$(GPP) $(CPPFLAGS) $(TEST_FOLDER)/CommandTest.cpp $(OUTPUT_FOLDER)/*.o -o $(TEST_BIN_FOLDER)/CommandTest.exe
