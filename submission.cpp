#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "vector"
#include <fstream>
#include <sstream>

using namespace std;

void readInputFile(const string &inputFile, vector<int> &numbers)
{
	ifstream file(inputFile);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			int number;
			stringstream ss(line);
			while (ss >> number)
			{
				numbers.push_back(number);
			}
		}
		file.close();
	}
}
int main(int argc, char *argv[])
{
	if (argc < 3) {
		cout << "Missing array numbers" << endl;
		cout << "Usage: <program> <inputfile> <outputfile>" << endl;
		return 1;
	}



	// Function to read input file and store numbers in an array
	
	string inputFile = argv[1];
	string outputFile = argv[2];

	vector<int> numbers;
	readInputFile(inputFile, numbers);
	int numCount = numbers.size();

	ofstream file(outputFile, ios::app);
	// print out all the keys that add up from w other keys
	for (int i=0; i<numCount; i++) {
		vector<pair<int, int>> pairs;
		for (int j=0; j<numCount; j++) {
			if (i == j) continue;
			for (int k=j+1; k<numCount; k++) {
				if (k == i || k == j) continue;
				if (numbers[i] == numbers[j] + numbers[k]) {
					if (numbers[j] > numbers[k])
						file << numbers[i] << " " << numbers[k] << " " << numbers[j] << endl;
					else {						
						file << numbers[i] << " " << numbers[j] << " " << numbers[k] << endl;
					}
				}
			}
		}
	}
	return 0;
}
