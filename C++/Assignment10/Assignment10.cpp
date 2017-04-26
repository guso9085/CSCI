#include <iostream>
#include "MovieTree.h"
#include <fstream>
#include <sstream>
using namespace std;

//Gustav Solis
//Assignment10
//Ishita

int main(int argc, char* argv[]){
  char* filename = argv[1];
  MovieTree tree = MovieTree();
  bool Exit = false;
  tree.buildTree(filename);
  while (Exit == false){
    string question;

    //MAIN INTERFACE
    cout << "======Main Menu======" << endl;
    cout << "1. Find a movie" << endl;
    cout << "2. Rent a movie" << endl;
    cout << "3. Print the inventory" << endl;
    cout << "4. Delete a movie" << endl;
    cout << "5. Count the movies" << endl;
    cout << "6. Count the longest path" << endl;
    cout << "7. Quit" << endl;
    getline(cin, question);

    if (stoi(question) == 1){
      string movieName;
      cout << "Enter title:" << endl;
      getline(cin, movieName);
      tree.findMovie(movieName);
    }
    else if (stoi(question) == 2){
      string movieName;
      cout << "Enter title:" << endl;
      getline(cin, movieName);
      tree.rentMovie(movieName);
    }
    else if (stoi(question) == 3){
      tree.printMovieInventory();
    }
    else if (stoi(question) == 4){
      string movieName;
      cout << "Enter title:" << endl;
      getline(cin, movieName);
      tree.deleteMovieNode(movieName);
    }
    else if (stoi(question) == 5){
      cout<<"Tree contains: "<<tree.countMovieNodes()<<" movies."<< endl;
    }
    else if (stoi(question) == 6){
      cout << "Longest Path: " << tree.countLongestPath() << endl;
    }
    else if (stoi(question) == 7){
      cout << "Goodbye!" << endl;
      Exit = true;
      break;
    }
  }

  return 0;
}
