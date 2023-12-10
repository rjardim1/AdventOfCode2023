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

            for(const auto &cubes : set_of_cubes)
            {
                stringstream line_stream2(cubes);
                string cube_str;
                const char cube_seperator = ',';

                int red_cubes = 0;
                int green_cubes = 0;
                int blue_cubes = 0;

                while(getline(line_stream2, cube_str, cube_seperator))
                {
                    if(cube_str.find("red") != string::npos)
                    {
                        red_cubes = GetCubeCount("red", cube_str);
                    }
                    else if(cube_str.find("green") != string::npos)
                    {
                        green_cubes = GetCubeCount("green", cube_str);
                    }
                    else if(cube_str.find("blue") != string::npos)
                    {
                        blue_cubes = GetCubeCount("blue", cube_str);
                    }
                }
            }

            return;
        }
    }
}

int Day2::GetCubeCount(const string &colour, const string &cubes_in_hand)
{
    if(colour == "red")
    {
        stringstream line_stream2(cubes_in_hand);
        string cube_str;
        const char cube_seperator = ':';

        while (getline(line_stream2, cube_str, cube_seperator))
        {
            if (cube_str.find(colour) != string::npos)
            {
                const_cast<string &>(cubes_in_hand) = cube_str;
            }
        }
    }

    int return_val = 0;

    if(cubes_in_hand.find(colour) != string::npos)
    {
        stringstream cube_stream(cubes_in_hand);
        string cube_str;
        const char cube_num_seporator = ' ';

        while(getline(cube_stream, cube_str, cube_num_seporator))
        {
            try
            {
                return_val = stoi(cube_str);
            }
            catch (exception &error)
            {
                //assume it was the name of the colour. Just continue.
                continue;
            }

        }
    }
    return return_val;
}
