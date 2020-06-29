#pragma once

#include <string>

class BeepMusic
{
private:
	unsigned int frequencyTable[8][12] =
	{
		{   33,   35,   37,   39,   41,   44,   46,   49,   52,   55,   58,   62 },
		{   65,   69,   73,   78,   82,   87,   92,   98,  104,  110,  117,  123 },
		{  131,  139,  147,  156,  165,  175,  185,  196,  208,  220,  233,  247 },
		{  262,  277,  294,  311,  330,  349,  370,  392,  415,  440,  466,  494 },
		{  524,  554,  587,  622,  659,  698,  740,  784,  831,  880,  932,  988 },
		{ 1047, 1109, 1175, 1245, 1319, 1397, 1480, 1568, 1661, 1760, 1865, 1976 },
		{ 2093, 2217, 2349, 2489, 2637, 2794, 2960, 3136, 3322, 3520, 3729, 3951 },
		{ 4186, 4435, 4699, 4978, 5274, 5588, 5920, 6272, 6645, 7040, 7459, 7902 }
	};
	
public:
	unsigned int defaultDuration;
	bool isDebug;

public:
	BeepMusic() : defaultDuration(500), isDebug(false) {}
	BeepMusic(unsigned int defaultDuration) : defaultDuration(defaultDuration), isDebug(false) {}
	BeepMusic(unsigned int defaultDuration, bool isDebug) : defaultDuration(defaultDuration), isDebug(isDebug) {}

private:
	void beep(unsigned int frequency, unsigned int duration) const;
	void sleep(unsigned int duration) const;
	unsigned int convertToFrequency(unsigned int octave, const std::string& syllable) const;

public:
	void note(unsigned int octave, const std::string& syllable, double durationRatio) const;
	void rest(double durationRatio) const;
};