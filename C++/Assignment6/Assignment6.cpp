#include <iostream>
#include "Queue.h"
#include <fstream>
#include <sstream>
using namespace std;

//Name: Gustav Solis
//Assignment 6
//TA : Ishita

//Main
int main(){
  Queue Q = Queue(10);
  bool Exit = false;
  while (Exit == false){
    string question;

    //MAIN INTERFACE
    cout << "======Main Menu=====" << endl;
    cout << "1. Enqueue word" << endl;
    cout << "2. Dequeue word" << endl;
    cout << "3. Print queue" << endl;
    cout << "4. Enqueue sentence" << endl;
    cout << "5. Quit" << endl;
    getline(cin, question);

    if (stoi(question) == 1){
      string word;
      cout << "word: ";
      getline(cin, word);
      Q.enqueue(word);
    }
    else if (stoi(question) == 2){
      Q.dequeue();
    }
    else if (stoi(question) == 3){
      Q.printQueue();
    }
    else if (stoi(question) == 4){
      string NQSentence;
      cout << "sentence: ";
      getline(cin, NQSentence);
      Q.enqueueMultiple(NQSentence);
    }
    else if (stoi(question) == 5){
      cout << "Goodbye!" << endl;
      Exit = true;
      break;
    }
  }
  return 0;
}
