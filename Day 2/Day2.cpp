/**
 * @file Day2.cpp
 * @brief Implementation of Day2 class for AdventOfCode2023.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <regex>

#include "Day2.h"

using namespace std;

/**
 * @brief Solves the Day 2 puzzle.
 * @details Computes and displays the solutions to both parts of the Day 2 puzzle.
 */
void Day2::SolveDay2()
{
    cout << "Day 2" << endl;
    fstream input_file("/Users/rubenj/AdventOfCode2023/Day 2/" + GetInputFile());
    string game_line;

    const regex reg("Game.*?(\\d+)");
    const char separator = ':';
    map<int, cube_sets_in_game_type> GamesMap;

    while (getline(input_file, game_line))
    {
        stringstream game_line_stream(game_line);
        string game;
        int game_id = 0;

        while (getline(game_line_stream, game, separator))
        {

            stringstream game_ss(game);
            string game_data;

            while(getline(game_ss, game_data, separator))
            {
                const string game_keyword = "Game ";
                if(game_data.find(game_keyword) != string::npos)
                {
                    string game_id_str;
                    int num_idx = 0;
                    while(game_data.size() > game_keyword.size() + num_idx)
                    {
                        game_id_str.push_back(game_data.at(game_data.find(game_keyword) +
                            game_keyword.size() + num_idx));

                        num_idx++;
                    }

                    game_id = stoi(game_id_str);
                }
            }

            if(game_data.find("red") != string::npos ||
            game_data.find("green") != string::npos ||
            game_data.find("blue") != string::npos)
            {
                GamesMap.insert(make_pair(game_id, GetHandsInGame(game)));
            }
        }
    }

    int combined_valid_game_id = 0;
    int summed_power_cubes = 0;

    for (const auto&[game_id, game_sets]: GamesMap)
    {
        bool valid_game = true;
        int max_red_cubes = 0;
        int max_green_cubes = 0;
        int max_blue_cubes = 0;

        for (const auto &hand : game_sets)
        {
            if(!hand.Valid)
            {
                valid_game = false;
            }

            max_red_cubes = max_red_cubes < hand.Red ? hand.Red : max_red_cubes;
            max_green_cubes = max_green_cubes < hand.Green ? hand.Green : max_green_cubes;
            max_blue_cubes = max_blue_cubes < hand.Blue ? hand.Blue : max_blue_cubes;
        }

        summed_power_cubes += (max_red_cubes * max_green_cubes * max_blue_cubes);

        if(valid_game)
        {
            combined_valid_game_id += game_id;
        }
    }

    if(GetInputType() == ePart1TestData ||
       GetInputType() == eActualTestData)
    {
        cout << "Part 1: " << combined_valid_game_id << endl;
    }

    if(GetInputType() == ePart2TestData ||
       GetInputType() == eActualTestData)
    {
        cout << "Part 2: " << summed_power_cubes << endl;
    }
}

/**
 * @brief Returns a vector of hands for a given game.
 * @param hands String representing the collection of hands.
 * @return Vector of SCubes structures for the given game.
 * @details This function processes a line of input representing a collection
 *          of hands, extracts the number of cubes of each color for each hand,
 *          and stores them in SCubes structures. Each SCubes structure is then
 *          added to a vector, which is returned.
 */
cube_sets_in_game_type Day2::GetHandsInGame(const string& hands)
{
    cube_sets_in_game_type cube_sets;
    const char hand_separator = ';';
    stringstream hands_in_game_ss(hands);
    string hand;

    while(getline(hands_in_game_ss, hand, hand_separator))
    {
        const char cube_separator = ',';
        stringstream hand_ss(hand);
        string cube;

        int red_cubes = 0;
        int green_cubes = 0;
        int blue_cubes = 0;

        while(getline(hand_ss, cube, cube_separator))
        {
            const char value_separator = ' ';
            stringstream cube_ss(cube);
            string cube_value;
            vector<string> cube_values;

            while(getline(cube_ss, cube_value, value_separator))
            {
                cube_values.emplace_back(cube_value);
            }

            reverse(cube_values.begin(), cube_values.end());

            for(int i = 0; i < cube_values.size(); i++)
            {
                if(cube_values.at(i).find("red") != string::npos)
                {
                    red_cubes = stoi(cube_values.at(i + 1));
                    i++;
                }
                else if(cube_values.at(i).find("green") != string::npos)
                {
                    green_cubes = stoi(cube_values.at(i + 1));
                    i++;
                }
                else if(cube_values.at(i).find("blue") != string::npos)
                {
                    blue_cubes = stoi(cube_values.at(i + 1));
                    i++;
                }
            }
        }
        cube_sets.emplace_back(red_cubes, green_cubes, blue_cubes);
    }

    return cube_sets;
}

/**
 * @brief Constructs a new SCubes object.
 *
 * @param red The count of red cubes.
 * @param green The count of green cubes.
 * @param blue The count of blue cubes.
 *
 * @details Constructs a new SCubes object setting the count of red, green
 * and blue cubes. Checks whether the count of each color of cubes
 * exceeds the maximum allowable limit according to the game rules. If exceeds,
 * the Valid member variable is set to false else true.
 */
SCubes::SCubes(const int &red, const int &green, const int &blue)
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

/**
 * @brief Prints the cube configuration to the standard output.
 *
 * @details Displays the number of each colored cube and the 'valid'
 * status of the SCubes object. If 'valid' is true, "True" is printed,
 * and if 'valid' is false, "False" is printed.
 */
void SCubes::Display() const
{
    cout << "Red: " << Red << " Green: " << Green << " Blue: " << Blue << " Valid: " <<
         (Valid ? "True" : "False") << endl;
}
