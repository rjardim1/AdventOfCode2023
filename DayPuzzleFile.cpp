//
// Created by Ruben Jardim on 12/12/2023.
//

#include <string>

#include "DayPuzzleFile.h"

using namespace std;

void DayPuzzleFile::SetInputFileType(DayPuzzleFile::EInputType input_type)
{
    InputType = input_type;
}

string DayPuzzleFile::GetInputFile()
{
    switch (InputType)
    {
        case ePart1TestData:
            return constPart1TestData;
        case ePart2TestData:
            return constPart2TestData;
        case eActualTestData:
            return constActualData;
        default:
            return "";
    }
}
