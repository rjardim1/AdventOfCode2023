//
// Created by Ruben Jardim on 09/12/2023.
//

#ifndef ADVENTOFCODE2023_DAY2_H
#define ADVENTOFCODE2023_DAY2_H

#include <regex>

using namespace std;

class Day2
{
public:
  static void SolveDay2();

private:
	enum EColour
	{
		eRed = 0,
		eGreen = 1,
		eBlue = 2,
		eInvalid = -1
	};

private:
	static int GetCubeCount(const EColour &cube_colour, const string &cubes_in_hand);
};


#endif //ADVENTOFCODE2023_DAY2_H
