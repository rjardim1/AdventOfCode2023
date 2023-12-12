//
// Created by Ruben Jardim on 09/12/2023.
//

#ifndef ADVENTOFCODE2023_DAY2_H
#define ADVENTOFCODE2023_DAY2_H

#include "../DayPuzzleFile.h"

using namespace std;

struct SCubes
{
    int Red;
    int Green;
    int Blue;

    bool Valid;

    SCubes(const int &red, const int &green, const int &blue)
        : Red(red), Green(green), Blue(blue)
    {
        int const const_max_red_cubes = 12;
        int const const_max_green_cubes = 13;
        int const const_max_blue_cubes = 14;

        bool red_valid = true;
        bool green_valid = true;
        bool blue_valid = true;

        if(red > const_max_red_cubes)
        {
            red_valid = false;
        }

        if(green > const_max_green_cubes)
        {
            green_valid = false;
        }

        if(blue > const_max_blue_cubes)
        {
            blue_valid = false;
        }

        Valid = red_valid && green_valid && blue_valid;
    }

    void Display() const
    {
        cout << "Red: " << Red << " Green: " << Green << " Blue: " << Blue << " Valid: " <<
            (Valid ? "True" : "False") << endl;
    }
};

using cube_sets_in_game_type = vector<SCubes>;


class Day2 : public DayPuzzleFile
{
public:
    static void SolveDay2();

private:
    static cube_sets_in_game_type GetHandsInGame(const string& hands);
};


#endif //ADVENTOFCODE2023_DAY2_H
