//
// Created by Ruben Jardim on 12/12/2023.
//

#ifndef ADVENTOFCODE2023_DAYPUZZLEFILE_H
#define ADVENTOFCODE2023_DAYPUZZLEFILE_H

#include <string>

using namespace std;

class DayPuzzleFile
{
public:
    enum EInputType
    {
        ePart1TestData = 0,
        ePart2TestData = 1,
        eActualTestData = 2,
        eInvalid = -1
    };

    static void SetInputFileType(EInputType input_type);

    static string GetInputFile();

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ConstantFunctionResult"
    static EInputType GetInputType() { return InputType; }
#pragma clang diagnostic pop

private:
    inline static EInputType InputType {eInvalid};

    inline static const string constPart1TestData {"Test1.txt"};
    inline static const string constPart2TestData {"Test2.txt"};
    inline static const string constActualData {"InputData.txt"};
};


#endif //ADVENTOFCODE2023_DAYPUZZLEFILE_H
