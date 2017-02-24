#include <iostream>
#include "WordAnalysis.h"
#include <fstream>
#include <sstream>

using namespace std;

//Name: Gustav Solis
//Assignment 3
//TA : Ishita

//Constructor
WordAnalysis::WordAnalysis(int startingSize) {
  timesDoubled = 0;
  words = new word[startingSize];
  wordCount = startingSize;
  index = 0;
}

//Destructor
WordAnalysis::~WordAnalysis() {

}

// doubles length of a given array
void doubleWordArraySize(word **arrWords, int *size, int *timesDoubled) {
  int SizeNeeded = *size * 2;
  word *dubArray = new word[SizeNeeded];
  for (int i = 0; i < *size; i++) {
    dubArray[i] = (*arrWords)[i];
  }
  delete [] (*arrWords);
  *size = SizeNeeded;
  *arrWords = dubArray;
  *timesDoubled = *timesDoubled + 1;
}


//finds word index
int findWordIndex(word *arrWords, int lengthOfArray, string searchWord) {
  int index = -1;
  for (int k = 0; k < lengthOfArray; k++) {
    if (arrWords[k].w == searchWord) {
      index = k;
      break;
    }
  }
  return index;
}

// prints words
void printWords(word *arrWords, int Print) {
  for(int i = 0; i < Print; i++) {
    cout << arrWords[i].count << " - " << arrWords[i].w << endl;
  }
}


//checks for common words from an array
bool WordAnalysis::checkIfCommonWord(std::string word) {
  bool status = true;
  string badWordList[51] = {"the", "be", "to", "of", "and", "a", "in", "that",
    "have", "i", "it", "for", "not", "on", "with", "he",
    "as", "you", "do", "at", "this", "but", "his", "by",
    "from", "they", "we", "say", "her", "she", "or", "an",
    "will", "my", "one", "all", "would", "there", "their",
    "what", "so", "up", "out", "if", "about", "who",
    "get", "which", "go", "me", ""};

  for (int i = 0; i < 51; i++) {
    if (badWordList[i] == word) {
      status = false;
      break;
    }
  }
  return status;
}

//doubles and adds
void WordAnalysis::doubleArrayAndAdd(string currentWord) {
    int wordIndex = findWordIndex(words, wordCount, currentWord);
    if (wordCount == index) {
      doubleWordArraySize(&words, &wordCount, &timesDoubled);
    }
    if (wordIndex == -1) {
      word newWord;
      newWord.w = currentWord;
      newWord.count = 1;
      words[index] = newWord;
      index++;
    } else {
      words[wordIndex].count = words[wordIndex].count + 1;
    }
}

//sorting algorithm
void WordAnalysis::sortData() {
  int j;
  int currentIndex = index;
  word tempWord;
  for (int i = 0; i < currentIndex; i++) {
    j = i;
    while (j > 0 && words[j].count > words[j-1].count) {
      tempWord = words[j];
      words[j] = words[j-1];
      words[j-1] = tempWord;
      j--;
    }
  }
}

//reading
bool WordAnalysis::readDataFile(char*filename) {
  int totalCount = 0;
  ifstream pablo;
  pablo.open(filename, ifstream::in);
  string Line;
  while(getline(pablo, Line)) {
    stringstream sentence(Line);
    string currentWord;
    while(getline(sentence, currentWord, ' ')) {
      if (checkIfCommonWord(currentWord)) {
        doubleArrayAndAdd(currentWord);
        totalCount++;
      }
    }
  }
  wordCount = totalCount;
  sortData();
  return true;
}


//Getter
int WordAnalysis::getWordCount() {
  return wordCount;
}

//Getter
int WordAnalysis::getUniqueWordCount() {
  return index;
}

//Getter
int WordAnalysis::getArrayDoubling() {
  return timesDoubled;
}

void WordAnalysis::printCommonWords(int Print) {
  printWords(words, Print);
}
