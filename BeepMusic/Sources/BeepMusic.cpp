#include "BeepMusic.h"

#include <iostream>
#include <cassert>
#include <Windows.h>

void BeepMusic::beep(unsigned int frequency, unsigned int duration) const
{
	if (isDebug) {
		std::cout << "Beep: " << frequency << "Hz, " << duration << "ms" << "\n";
	}

	Beep(frequency, duration);
}

void BeepMusic::sleep(unsigned int duration) const
{
	if (isDebug) {
		std::cout << "Sleep: " << duration << "ms" << "\n";
	}

	Sleep(duration);
}

unsigned int BeepMusic::convertToFrequency(unsigned int octave, const std::string& syllable) const
{
	int syllableIndex = 0;

	if (syllable == "C") syllableIndex = 0;
	else if (syllable == "C#") syllableIndex = 1;
	else if (syllable == "D") syllableIndex = 2;
	else if (syllable == "D#") syllableIndex = 3;
	else if (syllable == "E") syllableIndex = 4;
	else if (syllable == "F") syllableIndex = 5;
	else if (syllable == "F#") syllableIndex = 6;
	else if (syllable == "G") syllableIndex = 7;
	else if (syllable == "G#") syllableIndex = 8;
	else if (syllable == "A") syllableIndex = 9;
	else if (syllable == "A#") syllableIndex = 10;
	else if (syllable == "B") syllableIndex = 11;
	else assert(false);

	return frequencyTable[octave - 1][syllableIndex];
}

void BeepMusic::note(unsigned int octave, const std::string& syllable, double durationRatio) const
{
	beep(convertToFrequency(octave, syllable), (unsigned int)(defaultDuration * durationRatio));
}

void BeepMusic::rest(double durationRatio) const
{
	sleep((unsigned int)(defaultDuration * durationRatio));
}