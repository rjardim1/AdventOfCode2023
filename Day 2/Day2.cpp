//
// Created by Ruben Jardim on 09/12/2023.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

#include "Day2.h"

using namespace std;

void Day2::SolveDay2()
{
    cout << "Day 2" << endl;
    fstream input_file("/Users/rubenj/AdventOfCode2023/Day 2/input2.txt");
    string game_line;

    const regex reg("Game.*?(\\d+)");
    const char separator = ':';
    map<int, cube_sets_in_game_type> GamesMap;

    while (getline(input_file, game_line))
    {
        stringstream game_line_stream(game_line);
        string game;

        while (getline(game_line_stream, game, separator))
        {
            int game_id = 0;
            cube_sets_in_game_type cube_sets;

            stringstream game_ss(game);
            string game_data;

            while(getline(game_ss, game_data, separator))
            {
                const string game_keyword = "Game ";
                if(game_data.find(game_keyword) != string::npos)
                {
                    cout << game_data.at(game_data.find(game_keyword) + game_keyword.size()) << " ";
                    cout << game_data.at(game_data.find(game_keyword) + game_keyword.size()  + 1) << endl;

                    if(game_data.at(game_data.find(game_keyword) + game_keyword.size()) == ':')
                    {
                        game_id = stoi(&game_data.at(game_data.find(game_keyword) + 1));
                    }
                    else if(game_data.at(game_data.find(game_keyword) + game_keyword.size()) == ':')
                    {
                        //int num_1 = stoi(&game_data.at(game_data.find(game_keyword) + 1));
                        //int num_2 = stoi(&game_data.at(game_data.find(game_keyword) + 2));

                        //game_id = stoi(to_string(num_1) + to_string(num_2));
                    }
                }
            }


            if (!static_cast<bool>(game_id))
            {
                cube_sets = GetHandsInGame(game);
            }

            GamesMap.insert(make_pair(game_id, cube_sets));
        }
    }

    int combined_valid_game_id = 0;

    for (const auto&[game_id, game_sets]: GamesMap)
    {
        bool valid_game = true;
        for (const auto &hand: game_sets)
        {
            if(!hand.Valid)
            {
                valid_game = false;
            }
        }

        if(valid_game)
        {
            combined_valid_game_id += game_id;
        }
    }

    cout << "Part 1: " << combined_valid_game_id << endl;
}

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

        cube_sets.emplace_back(SCubes(red_cubes, green_cubes, blue_cubes));
    }

    return cube_sets;
}
