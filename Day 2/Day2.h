/**
 * @file Day2.h
 * @brief Header for Day2 class and auxiliary structures for the AdventOfCode2023 project.
 */

#ifndef ADVENTOFCODE2023_DAY2_H
#define ADVENTOFCODE2023_DAY2_H

#include "../DayPuzzleFile.h"

using namespace std;

/**
 * @struct SCubes
 * @brief This structure represents a simple cube configuration for the game.
 */
struct SCubes
{
    int Red; ///< Number of red cubes.
    int Green; ///< Number of green cubes.
    int Blue; ///< Number of blue cubes.

    bool Valid; ///< Defines if the cube set is valid according to the game rules.

    /**
     * @brief Construct a new SCubes object with given cube count.
     * @param red The number of red cubes.
     * @param green The number of green cubes.
     * @param blue The number of blue cubes.
     */
    SCubes(const int &red, const int &green, const int &blue);

    /**
     * @brief Prints the cube configuration to standard output.
     */
    void Display() const;
};

/// A shorthand for the collection of cube sets in the game.
using cube_sets_in_game_type = vector<SCubes>;

/**
 * @class Day2
 * @brief The class encapsulates the solution logic for Day 2 of AdventOfCode2023 project.
 */
class Day2 : public DayPuzzleFile
{
public:
    /**
     * @brief Calculates and prints the solution for Day 2 of the AdventOfCode2023 project.
     */
    static void SolveDay2();

private:
    /**
     * @brief Process raw string of hands and returns a collection of cube sets.
     * @param hands The string containing the raw hands data.
     * @return A collection of SCubes representing each hand in the game.
     */
    static cube_sets_in_game_type GetHandsInGame(const string& hands);
};


#endif //ADVENTOFCODE2023_DAY2_H