#include <iostream>

#include "DayPuzzleFile.h"
#include "Day 1/Day1.h"
#include "Day 2/Day2.h"
#include "Day 3/Day3.h"

int main()
{
    Day1::SetInputFileType(Day1::eActualTestData);
    Day1::SolveDay1();

    Day2::SetInputFileType(Day2::eActualTestData);
    Day2::SolveDay2();

    Day3::SetInputFileType(Day3::eActualTestData);
    Day3::SolveDay3();

    return 0;
}
