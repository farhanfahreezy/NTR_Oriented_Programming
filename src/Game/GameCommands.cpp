#include "GameCommands.hpp"

bool GameCommands::initialized = false;

/** TODO: Define all available commands as member static constants here
 *  const GameCommands::COMMAND_NAME = Command::withName(...)
 *      .addArg(..., ...)
 *      .addArg(..., ...)
 *      ...
 *      .handles([](vector<string>& argv)->bool{
 *          ...
 *      });
*/

void GameCommands::init(){
    /** TODO: Register all member commands to the parser
     *  CommandParser.reg(COMMAND_NAME);
     *  ...
    */

    initialized = true;
}
