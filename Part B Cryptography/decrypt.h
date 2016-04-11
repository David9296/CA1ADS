
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <array>

using namespace std;

typedef array<pair<char, double>, 26>FreqArray;

class VigenereAnalyser
{

private:
	array<double, 26>targets;
	array<double, 26>sortedTargets;
	FreqArray freq;

	FreqArray& frequency(const string& input);
	double correlation(const string& input);

public:

	VigenereAnalyser(const array<double, 26>& targetFreqs);
	string analyze(string);


};