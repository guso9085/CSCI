#include <iostream>
#include "CommunicationNetwork.h"
#include <fstream>
#include <sstream>

using namespace std;

//Name: Gustav Solis
//Assignment 5
//TA : Ishita

//Constructor
CommunicationNetwork::CommunicationNetwork() {
  head = NULL;
}

//Destructor
CommunicationNetwork::~CommunicationNetwork() {
  deleteNetwork();
}

//ADD CITY FUNCTION
void CommunicationNetwork::addCity(string cityName, string PreviousCity){
  if (PreviousCity == "First") {
    City *oldHead = head;
    City *nCity = new City(cityName, oldHead, NULL, "");
    head = nCity;
  }else{
    City *temp = head;
    City *nCity = new City(cityName, NULL, NULL, "");
    while (temp -> next != NULL) {
      if (temp -> cityName == PreviousCity) {
        nCity -> next = temp -> next;
        nCity -> previous = temp;
        temp -> next = nCity;
        return;
      }
      temp = temp -> next;
    }
    if (temp -> next == NULL) {
      temp -> next = nCity;
      nCity -> previous = temp;
    }

  }
}

//BUILD THE NETWORK USING ADDCITY
void CommunicationNetwork::buildNetwork(){
  addCity("Los Angeles", "First");
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

      while(temp -> next != NULL){
        temp -> message = currentWord;
        cout <<  temp -> cityName <<" received "<< currentWord << endl;
        temp = temp -> next;
      }

      if (temp -> next == NULL){
        cout <<  temp -> cityName <<" received "<< currentWord << endl;
      }

      while(temp -> previous != NULL){
        temp -> message = currentWord;
        cout <<  temp -> previous -> cityName <<" received "<< currentWord << endl;
        temp = temp -> previous;
      }

    }
  }
}

//PRINTS
void CommunicationNetwork::printNetwork() {
  if (head == NULL) {
    cout << "===CURRENT PATH===" << endl;
    cout << "NULL" << endl;
    cout << "==================" << endl;
    return;
  }
  cout << "===CURRENT PATH===" << endl;
  cout << "NULL <- ";
  City *temp = head;
  while (temp -> next != NULL) {
    cout << (temp -> cityName) << " <-> ";
    temp = temp -> next;
  }
  if (temp -> next == NULL){
    cout << (temp -> cityName) << " -> ";
    temp = temp -> next;
  }
  cout << "NULL" << endl;
  cout << "==================" << endl;
}


//DELETE CITY FUNCTION
void CommunicationNetwork::deleteCity(string Delete){
  City *temp = head;
  while(temp != NULL){
        if (temp -> cityName == Delete && temp -> previous != NULL && temp -> next != NULL){
            //City *tempdelete = temp;
            //City *temp1 = temp -> next;
            //City *temp2 = temp -> previous;
            //temp -> next -> previous = temp2;
            //temp -> previous -> next = temp1;
            temp -> next -> previous = temp -> previous;
            temp -> previous -> next = temp -> next;
            delete temp;
            //delete tempdelete;
            break;
        }
        else if (temp -> cityName == Delete && temp -> previous == NULL && temp -> next != NULL){
            City *tempdelete = temp;
            temp -> next -> previous = NULL;
            head = temp -> next;
            delete tempdelete;
            break;
        }
        else if (temp -> cityName == Delete && temp -> next == NULL){
            City *tempdelete = temp;
            temp -> previous -> next = NULL;
            //temp -> previous = NULL;
            tail = tail -> previous;
            delete tempdelete;
            break;
        }
        else {
            temp = temp -> next;
        }
    }
}

//DELETE NETWORK FUNCTION
void CommunicationNetwork::deleteNetwork(){
  City *temp = head;
  while(temp != NULL){
    cout << "deleting " << temp -> cityName << endl;
    City *tempdel = temp;
    temp = temp -> next;
    delete tempdel;
  }
  head = NULL;
  tail = NULL;
}
