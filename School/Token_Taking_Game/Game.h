#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>

using std::ostream;
using std::vector;

class Game {
public:

	//Constructor
	Game(unsigned int, unsigned int);

	//Class-member Functions
	bool play(unsigned int);
	void print_result(ostream&) const;

private:

	//Data Fields
	const unsigned int target;
	unsigned int turns;
	vector<char> path;

};

#endif