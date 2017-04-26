#include <iostream>
#include "Graph.h"
#include <fstream>
#include <sstream>
using namespace std;

//Gustav Solis
//Assignment12
//Ishita

int main(int argc, char* argv[]){
  string startingCity, endingCity;
  char* filename = argv[1];
  //MovieTree tree = MovieTree();
  bool Exit = false;
  //tree.buildTree(filename);
  while (Exit == false){
    string question;

    //MAIN INTERFACE
    cout << "======Main Menu======" << endl;
    cout << "1. Print Vertices" << endl;
    cout << "2. Find districts" << endl;
    cout << "3. Find shortest path" << endl;
    cout << "4. Quit" << endl;
    getline(cin, question);

    if (stoi(question) == 1){
      string movieName;
      cout << "Enter title:" << endl;
      getline(cin, movieName);
      //tree.findMovie(movieName);
    }
    else if (stoi(question) == 2){
      string movieName;
      cout << "Enter title:" << endl;
      getline(cin, movieName);
      //tree.rentMovie(movieName);
    }
    else if (stoi(question) == 3){
      cout << "Enter a starting city:" << endl;
      getline(cin, startingCity);
      cout << "Enter an ending city:" << endl;
      getline(cin, endingCity);
    }
    else if (stoi(question) == 4){
      cout << "Goodbye!" << endl;
      Exit = true;
      break;
    }
  }

  return 0;
}
