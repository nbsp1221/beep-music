#include "BeepMusic.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void playNote(const BeepMusic& beepMusic, stringstream& stringStream)
{
	unsigned int octave;
	string syllable;
	double durationRatio;

	stringStream >> octave >> syllable >> durationRatio;
	beepMusic.note(octave, syllable, durationRatio);
}

void playRest(const BeepMusic& beepMusic, stringstream& stringStream)
{
	double durationRatio;

	stringStream >> durationRatio;
	beepMusic.rest(durationRatio);
}

int main(int argc, char* argv[])
{
	BeepMusic beepMusic;
	beepMusic.isDebug = true;

	if (argc == 1) {
		cout << "Usage: BeepMusic [beep file path]" << "\n";
		cout << "Running the example ..." << "\n\n";

		beepMusic.note(4, "C", 1);
		beepMusic.note(4, "D", 1);
		beepMusic.note(4, "E", 1);
		beepMusic.note(4, "F", 1);
		beepMusic.note(4, "G", 1);
		beepMusic.note(4, "A", 1);
		beepMusic.note(4, "B", 1);
		beepMusic.note(5, "C", 1);

		return 0;
	}

	ifstream inFile(argv[1]);
	string inputString;

	if (inFile.is_open()) {
		while (getline(inFile, inputString)) {
			string type;
			stringstream stringStream(inputString);
			stringStream >> type;

			if (type == "Duration") stringStream >> beepMusic.defaultDuration;
			else if (type == "Note") playNote(beepMusic, stringStream);
			else if (type == "Rest") playRest(beepMusic, stringStream);
		}
	}
	else {
		cout << "Failed to open!" << "\n";
	}

	inFile.close();
	return 0;
}