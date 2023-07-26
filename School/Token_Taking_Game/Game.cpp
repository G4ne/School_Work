#include "Game.h"


//Constructor
Game::Game(unsigned int target, unsigned int turns) : target(target), turns(turns) {
	path.resize(0);
}


/* Plays a session of the game with the given amount of tokens
* @param tokens: This is the given amount of tokens
* @return: Returns true if a valid path is found and false if one is not found
*/
bool Game::play(unsigned int tokens) {

	if (tokens == target) { return true; }
	else if (turns == 0) { return false; }
	else {

		turns--;
		path.push_back('A');
		if (play(tokens + 39)) { return true; }
		else {
			
			turns++;
			path.pop_back();

		}

		if (!(tokens % 2)) {

			turns--;
			path.push_back('B');

			if (play(tokens / 2)) { return true; }
			else {

				turns++;
				path.pop_back();

			}

		}
		return false;
	}

}



/* Prints the result of a played game to a given ostream
* @param out: The ostream to output the game's result to
*/
void Game::print_result(ostream& out) const {

	if (path.empty()) {
		out << "Dead End" << std::endl;
	}
	else {
		for (unsigned int i = 0; i < path.size(); i++) { out << path.at(i); }
		out << std::endl;
	}

}