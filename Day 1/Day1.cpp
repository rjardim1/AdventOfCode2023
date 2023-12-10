//
// Created by Ruben Jardim on 08/12/2023.
//
#include <iostream>
#include <fstream>
#include <utility>
#include "Day1.h"

using namespace std;

struct SNumbers
{
	string NumName;
	int Number;

	SNumbers(string num_name, const int &num)
		: NumName(std::move(num_name)), Number(num)
	{
	}
};

static SNumbers num_strings[9] =
	{
		SNumbers("one", 1),
		SNumbers("two", 2),
		SNumbers("three", 3),
		SNumbers("four", 4),
		SNumbers("five", 5),
		SNumbers("six", 6),
		SNumbers("seven", 7),
		SNumbers("eight", 8),
		SNumbers("nine", 9)
	};

void Day1::SolveDay1()
{
	cout << "Day 1" << endl;
	fstream input_file("/Users/rubenj/AdventOfCode2023/Day 1/input1.txt");
	string line;
	int total_1 = 0;
	int total_2 = 0;

	while (getline(input_file, line))
	{
		int first = -1;
		int last = -1;
		int digit_last_pos = -1;
		int digit_first_pos = -1;
		vector<pair<int, int>> str_num;

		for (int i = 0; i <= line.size() - 1; i++)
		{
			if (isdigit(line.at(i)))
			{
				std::string val(1, line.at(i));

				if (first < 0)
				{
					first = stoi(val);
					digit_first_pos = i;
				}
				last = stoi(val);
				digit_last_pos = i;
			}
		}

		total_1 += stoi(to_string(first) + to_string(last));

		for (const auto &number: num_strings)
		{
			int pos = static_cast<int>(line.find(number.NumName));
			if (pos != string::npos)
			{
				str_num.emplace_back(pos, number.Number);
			}
		}

		if (!str_num.empty())
		{
			std::sort(str_num.begin(), str_num.end());

			if (first < 0 || digit_first_pos > str_num.front().first)
			{
				first = str_num.front().second;
			}

			if (last < 0 || digit_last_pos < str_num.back().first)
			{
				last = str_num.back().second;
			}
		}

		total_2 += stoi(to_string(first) + to_string(last));
	}

	cout << total_1 << endl;
	cout << total_2 << endl;
}
