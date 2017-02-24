#include <iostream>
#include "CommunicationNetwork.h"
#include <fstream>
#include <sstream>

using namespace std;

//Name: Gustav Solis
//Assignment 4
//TA : Ishita

//Constructor
CommunicationNetwork::CommunicationNetwork() {
  head = NULL;
}

//Destructor
CommunicationNetwork::~CommunicationNetwork() {

}

//ADD CITY FUNCTION
void CommunicationNetwork::addCity(string cityName, string PreviousCity){
  if (PreviousCity == "1") {
    City *oldHead = head;
    City *nCity = new City(cityName, oldHead, "");
    head = nCity;
  }else{
    City *temp = head;
    City *nCity = new City(cityName, NULL, "");
    while (temp -> next != NULL) {
      if (temp -> cityName == PreviousCity) {
        nCity -> next = temp -> next;
        temp -> next = nCity;
        return;
      }
      temp = temp -> next;
    }
    if (temp->next == NULL) {
      temp->next = nCity;
    }

  }
}

//BUILD THE NETWORK USING ADDCITY
void CommunicationNetwork::buildNetwork(){
  addCity("Los Angeles", "1");
  addCity("Phoenix", "Los Angeles");
  addCity("Denver", "Phoenix");
  addCity("Dallas", "Denver");
  addCity("St. Louis", "Dallas");
  addCity("Chicago", "St. Louis");
  addCity("Atlanta", "Chicago");
  addCity("Washington, D.C.", "Atlanta");
  addCity("New York", "Washington, D.C.");
  addCity("Boston", "New York");
  printNetwork();
}

//BREAKS UP MESSAGE.TXT AND ADDS TO CITY
void CommunicationNetwork::transmitMsg(char *message){
  ifstream pablo;
  pablo.open(message, ifstream::in);
  string Line;
  while(getline(pablo, Line)) {
    stringstream sentence(Line);
    string currentWord;
    while(getline(sentence, currentWord, ' ')) {
      City *temp = head;
      while(temp != NULL){
        temp -> message = currentWord;
        cout <<  temp -> cityName <<" received "<< currentWord << endl;
        temp = temp -> next;
      }
    }
  }
}

//PRINTS
void CommunicationNetwork::printNetwork() {
  cout << "===CURRENT PATH===" << endl;
  City *temp = head;
  while (temp != NULL) {
    cout << (temp -> cityName) << " -> ";
    temp = temp -> next;
  }
  cout << "NULL" << endl;
  cout << "==================" << endl;
}
