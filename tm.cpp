// tm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
//#include "Tape.h"

using namespace std; 

class Head
{

};

class Tape
{
public:
	Tape(void);
	Tape(string);
	char Read();
	void Write(char);
	void UpdateHeadPosition(int);
	~Tape(void);

private:
	int headPosition;
	Head head;
	vector<char> tape;
};

int _tmain(int argc, _TCHAR* argv[])
{ 
	string line;
	ifstream inputFile("input.txt");

	Tape tape;
	
	if (inputFile.is_open())
	{
		// Get the each line from the input file and determine what to do with it
		while (getline(inputFile,line))
		{
			// Handle the input string from the input file
			if (line[0] == 'i')
			{
				line.erase(0,2);
				cout << "Input string: " << line << endl;

				tape = Tape(line);
			}
			// Handle transitions from input
			else if (line[0] == 't')
			{
				line.erase(0,2);
				cout << "Transition input: " << line << endl;
			}
			// Handle final states from input
			else if (line[0] == 'f')
			{
				line.erase(0,2);
				cout << "Final state input: " << line << endl;
			}
		}

		inputFile.close();
	}

	else cout << "Unable to open file"; 

	return 0;
}

