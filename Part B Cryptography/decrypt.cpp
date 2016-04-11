#include "decrypt.h"




FreqArray& VigenereAnalyser::frequency(const string& input)
{

	//Pairs Letters and counts frequency
	for (char c = 'A';c <= 'Z';++c)
		freq[c - 'A'] = make_pair(c, 0);

	for (size_t i = 0;i < input.size();++i)
		freq[input[i] - 'A'].second++;

	return freq;
}




//Compares data groups to find best size and frequency 
double VigenereAnalyser::correlation(const string & input)
{
	double result = 0.0;
	frequency(input);

	
	sort(freq.begin(), freq.end(), [](pair<char, double>u, pair<char, double>v)->bool {
		return u.second < v.second;
	});

	
	for (size_t i = 0;i < 26;++i)
		result += freq[i].second*sortedTargets[i];
	return result;
}


//Takes in the frequencies of the letters E.g English
VigenereAnalyser::VigenereAnalyser(const array<double, 26>& targetFreqs)
{
	targets = targetFreqs;
	sortedTargets = targets;
	sort(sortedTargets.begin(), sortedTargets.end());

}



/***************************************************************************************
*    Title: Cryptanalysis
*    Author: RosettaCode
*    Date: 21 March 2016
*    Availability: http://rosettacode.org/wiki/Vigen%C3%A8re_cipher/Cryptanalysis
*
***************************************************************************************/



string VigenereAnalyser::analyze(string input)
{

	string cleaned;
	for (size_t i = 0; i < input.size();++i)
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
			cleaned += input[i];
		else if (input[i] >= 'a' && input[i] <= 'z')

			cleaned += input[i] + 'A' - 'a';

		//Takes Input and cleans it for Upper and lower case letters
	}

	
	size_t bestLength = 0;
	double bestCorr = -100.0; 

	for (size_t i = 2;i < cleaned.size() / 20;++i) {

		vector<string> pieces(i);
		for (size_t j = 0; j < cleaned.size(); ++j)
			pieces[j % i] += cleaned[j];

		double corr = -0.5*i;
		for (size_t j = 0;j < i; ++j)
			corr += correlation(pieces[j]);

		if (corr > bestCorr) {
			bestLength = i;
			bestCorr = corr;

		}
	}

	//

	if (bestLength == 0)
		return "Text too short ";

	vector<string> pieces(bestLength);
	for (size_t i = 0;i < cleaned.size();++i)
		pieces[i % bestLength] += cleaned[i];

	vector<FreqArray> freqs;
	for (size_t i = 0;i < bestLength;++i)
		freqs.push_back(frequency(pieces[i]));

	string key = "";
	for (size_t i = 0;i < bestLength;++i)
	{
		sort(freqs[i].begin(), freqs[i].end(), [](pair<char, double> u, pair<char, double> v)->bool
		{
			return u.second > v.second;
		}
		);


		size_t m = 0;
		double mCorr = 0.0;

		for (size_t j = 0;j < 26; ++j)
		{
			double corr = 0.0;
			char c = 'A' + j;
			for (size_t k = 0;k < 26;++k)
			{
				int d = (freqs[i][k].first - c + 26) % 26;
				corr += freqs[i][k].second * targets[d];

			}

			if (corr > mCorr) {
				m = j;
				mCorr = corr;
			}
		}

		key += m + 'A';
	}


	return key;
};
