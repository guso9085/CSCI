#include <iostream>
#include "CommunicationNetwork.h"
#include <fstream>
#include <sstream>
using namespace std;

//Name: Gustav Solis
//Assignment 4
//TA : Ishita

//Main
int main(int argc, char* argv[]){
  char* filename = argv[1];
  CommunicationNetwork comm = CommunicationNetwork();
  bool Exit = false;
  while (Exit == false){
    string question;

    //MAIN INTERFACE
    cout << "======Main Menu======" << endl;
    cout << "1. Build Network" << endl;
    cout << "2. Print Network Path" << endl;
    cout << "3. Transmit Message Coast-To-Coast-To-Coast" << endl;
    cout << "4. Add City" << endl;
    cout << "5. Delete City" << endl;
    cout << "6. Clear Network" << endl;
    cout << "7. Quit" << endl;
    getline(cin, question);

    if (stoi(question) == 1){
      comm.buildNetwork();
    }
    else if (stoi(question) == 2){
      comm.printNetwork();
    }
    else if (stoi(question) == 3){
      comm.transmitMsg(filename);
    }
    else if (stoi(question) == 4){
      string PreviousCity, CurrentCity;
      cout << "Enter a city name: " << endl;
      getline(cin, CurrentCity);
      cout << "Enter a previous city name: " << endl;
      getline(cin, PreviousCity);
      comm.addCity(CurrentCity, PreviousCity);
    }
    else if (stoi(question) == 5){
      string City2Delete;
      cout << "Enter a city name: " << endl;
      getline(cin, City2Delete);
      comm.deleteCity(City2Delete);
    }
    else if (stoi(question) == 6){
      comm.deleteNetwork();
    }
    else if (stoi(question) == 7){
      cout << "Goodbye!" << endl;
      Exit = true;
    }
  }
  return 0;
}
