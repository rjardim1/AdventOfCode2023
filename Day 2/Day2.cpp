//
// Created by Ruben Jardim on 09/12/2023.
//

#include <iostream>
#include <fstream>
#include <sstream>

#include "Day2.h"

using namespace std;

struct SCubes
{
	uint Red;
	uint Green;
	uint Blue;

	SCubes(const int &red, const int &green, const int &blue)
		: Red(red), Green(green), Blue(blue)
	{
	}
};

void Day2::SolveDay2()
{
	cout << "Day 2" << endl;
	fstream input_file("/Users/rubenj/AdventOfCode2023/Day 2/input2.txt");
	string line;

	const regex reg("(Game) [0-9]+");
	const char separator = ';';

	while (getline(input_file, line))
	{
		vector<SCubes> stored_cubes;
		if (regex_search(line, reg))
		{
			vector<string> set_of_cubes;
			string cubes;
			stringstream line_stream(line);

			while (getline(line_stream, cubes, separator))
			{
				set_of_cubes.emplace_back(cubes);
			}

			for(const auto &cube : set_of_cubes)
			{
				stringstream line_stream2(cube);
				string cube_str;
				const char cube_seperator = ',';

				while(getline(line_stream2, cube_str, cube_seperator))
				{
					int red_cubes = GetCubeCount(eRed, cube_str);
					int green_cubes = GetCubeCount(eGreen, cube_str);
					int blue_cubes = GetCubeCount(eBlue, cube_str);


				}
			}

			return;
		}
	}
}

int Day2::GetCubeCount(const EColour &cube_colour, const string &cubes_in_hand)
{
	string cube_colour_str = "none";
	switch(cube_colour)
	{
		case eRed:
		{
			cube_colour_str = "red";

			stringstream line_stream2(cubes_in_hand);
			string cube_str;
			const char cube_seperator = ':';

			while(getline(line_stream2, cube_str, cube_seperator))
			{

			}
			break;
		}
		case eGreen:
			cube_colour_str = "green";
			break;
		case eBlue:
			cube_colour_str = "blue";
			break;
		case eInvalid:
		default:
			break;
	}

	if(cubes_in_hand.find(cube_colour_str) != string::npos)
	{

	}
}
