#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>

struct word{   //Struct initialization
  int dex;
  string content;
};

bool CommonWords(string Segment, bool common){    //Check for common words in text
  string nulls[51] = {"the", "be", "to", "of", "and", "a", "in", "that", "have", "i", "it", "for", "not", "on", "with", "he",
                            "as", "you", "do", "at", "this", "but", "his", "by", "from", "they", "we", "say", "her", "she", "or", "an",
                            "will", "my", "one", "all", "would", "there", "their", "what", "so", "up", "out", "if", "about", "who",
                            "get", "which", "go", "me", ""};

  for(int i = 0; i < 51; i++){ //Takes the string and looks for a match in the array
    if(nulls[i]==Segment){
      common = true;
      break;
    }
  }
  return common;
}

bool RepeatWords(string Segment, bool repeat, word **Uniques, int *counter){  //Check for repeating words, to increment the counter
  for(int i = 0; i < *counter; i++){
    if((*Uniques)[i].content == Segment){ //If struct string = string, then increment
      repeat = true;
      (*Uniques)[i].dex = (*Uniques)[i].dex + 1;
    }
  }

  return repeat;
}

void insertionSort(word *Uniques, int counter) { //Sort algorithm for the finished array
    word Temporary;
    int g;
    for (int i = 0; i < counter; i++) {
        g = i;

        while (g > 0 && Uniques[g].dex > Uniques[g-1].dex) {
            Temporary = Uniques[g];
            Uniques[g] = Uniques[g-1];
            Uniques[g-1] = Temporary;
            g--;
        }
    }
}

void ArrayDouble(word **Uniques, int *Length, int *Double){ //Doubling Array
  int DoubleIndex = (*Length * 2);
  word *Temporary = new word[DoubleIndex];
  for(int k = 0; k < *Length; k++){
    Temporary[k] = (*Uniques)[k];
  }
  delete [] (*Uniques);  //Clears memory of old array
  *Uniques = Temporary;
  *Length = *Length * 2;
  *Double = *Double + 1;
}

int main(int argc, char *argv[]) { //Main
  int topCount = stoi(argv[2]);
  int processed = 0;
  int currentLength = 100;
  int *counter = new int;
  *counter = 0;
  int *Length = &currentLength;
  int doubleCounter = 0;
  int *Double = &doubleCounter;
  word *Uniques = new word[currentLength];

  stringstream pablo;
  string Segment;
  string inputFile;
  inputFile = argv[1];

  ifstream ifile;
  ifile.open(inputFile.c_str(), ios::in); //Open File
  string line;

  if (ifile.is_open() == true){
    while(getline(ifile, line, '\n')){
      pablo.str(line);

      while(getline(pablo, Segment, ' ')){  //Main array builder
        bool common = false;
        bool repeat = false;
        common = CommonWords(Segment, common);   //Checks for common words
        repeat = RepeatWords(Segment, repeat, &Uniques, counter); //Checks for repeated words
        if(*counter == currentLength){
          ArrayDouble(&Uniques, Length, Double);  //Doubles array if index is = to length of array
        }
        if(common == false && repeat == false){
          Uniques[*counter].content = Segment;
          Uniques[*counter].dex = 1;
          *counter = *counter + 1;
          processed++;
        }
        else if(common == false && repeat == true){
          processed++;
        }
      }
      pablo.clear();  //Clears stringstream
    }
    ifile.close();  //Close File
  }

  insertionSort(Uniques, *counter);  //Runs the sort

  for (int i = 0; i < topCount; i++) {  //Prints the top n words
        cout << Uniques[i].dex << " - " << Uniques[i].content << endl;
  }


  cout << "#" << endl;
  cout << "Array doubled: " << *Double << endl;
  cout << "#" << endl;
  cout << "Unique non-common words: " << *counter << endl;
  cout << "#" << endl;
  cout << "Total non-common words: " << processed << endl;

  delete [] Uniques;  //Clearing memory
  delete counter;

}
