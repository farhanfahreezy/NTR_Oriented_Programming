GPP				= g++

SOURCE_FOLDER	= src
OUTPUT_FOLDER	= bin
TEST_FOLDER		= test
TEST_BIN_FOLDER	= $(OUTPUT_FOLDER)/test

BIN_NAME		= ntr

CPPFLAGS		= -I$(SOURCE_FOLDER)

### BUILD RECIPES ###
# build			- Builds a single executable file
build: build-all clean-obj

# build-all		- Compiles object files and builds a release-executable file
build-all: all
	@$(GPP) $(CPPFLAGS) $(OUTPUT_FOLDER)/*.o									-o $(OUTPUT_FOLDER)/$(BIN_NAME).exe

# all			- Compiles object files
all: game inv-holder card deck table player io

# game			- Builds all source files in the folder "Game"
game:
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_FOLDER)/Game/GameState.cpp					-o $(OUTPUT_FOLDER)/GameState.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_FOLDER)/Game/GameCommands.cpp				-o $(OUTPUT_FOLDER)/GameCommands.o

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
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_FOLDER)/IO/Terminal/Command.cpp				-o $(OUTPUT_FOLDER)/Command.o
	@$(GPP) $(CPPFLAGS) -c $(SOURCE_FOLDER)/IO/Terminal/CommandParser.cpp		-o $(OUTPUT_FOLDER)/CommandParser.o

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
test-state: testb-state clean-obj 
	@$(TEST_BIN_FOLDER)/GameStateTest.exe

testb-state: all
	@$(GPP) $(CPPFLAGS) $(TEST_FOLDER)/GameStateTest.cpp $(OUTPUT_FOLDER)/*.o -o $(TEST_BIN_FOLDER)/GameStateTest.exe

# test-regdeck
test-regdeck: testb-regdeck clean-obj 
	@$(TEST_BIN_FOLDER)/RegularDeckTest.exe

testb-regdeck: all
	@$(GPP) $(CPPFLAGS) $(TEST_FOLDER)/RegularDeckTest.cpp $(OUTPUT_FOLDER)/*.o -o $(TEST_BIN_FOLDER)/RegularDeckTest.exe

# test -abdeck
test-abdeck: testb-abdeck clean-obj 
	@$(TEST_BIN_FOLDER)/AbilityDeckTest.exe

testb-abdeck: all
	@$(GPP) $(CPPFLAGS) $(TEST_FOLDER)/AbilityDeckTest.cpp $(OUTPUT_FOLDER)/*.o -o $(TEST_BIN_FOLDER)/AbilityDeckTest.exe

test-main: testb-main clean-obj 
	@$(TEST_BIN_FOLDER)/main.exe

testb-main: all
	@$(GPP) $(CPPFLAGS) $(TEST_FOLDER)/main.cpp $(OUTPUT_FOLDER)/*.o -o $(TEST_BIN_FOLDER)/main.exe
