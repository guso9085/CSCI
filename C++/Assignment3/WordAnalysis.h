#include <string>
using namespace std;

//Name: Gustav Solis
//Assignment 3
//TA : Ishita 

struct word {
	int count;
	string w;
};

class WordAnalysis{
	private:
		word *words;
		int timesDoubled;
		int wordCount;
		int index;
		void doubleArrayAndAdd(string);
		bool checkIfCommonWord(string);
		void sortData();
	public:
		bool readDataFile(char*); //returns an error if file not opened
		int getWordCount();
		int getUniqueWordCount();
		int getArrayDoubling();
		void printCommonWords(int);
		WordAnalysis(int);
		~WordAnalysis();
};
