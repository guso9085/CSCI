#include <iostream>
#include "Queue.h"
#include <fstream>
#include <sstream>
using namespace std;

//Name: Gustav Solis
//Assignment 6
//TA : Ishita

//Constructor
Queue::Queue(int qs) {
  queueSize = qs;
  arrayQueue = new string[queueSize];
  queueHead = 0;
  queueTail = 0;
  queueCount = 0;
}

//Destructor
Queue::~Queue() {

}

//Enqueue
void Queue::enqueue(string toEnqueue) {
  if (queueIsFull()) {
    cout << "Queue is full." << endl;
    return;
  }

  arrayQueue[queueTail] = toEnqueue;
  queueCount++;

  if (queueTail == queueSize - 1) {
    queueTail = 0;
  } else {
    queueTail++;
  }

  cout << "E: " << toEnqueue << endl;
  cout << "H: " << queueHead << endl;
  cout << "T: " << queueTail << endl;
}

//Dequeue
string Queue::dequeue() {
  if (queueIsEmpty()) {
    cout << "Queue is empty." << endl;
    return "";
  }

  string Delete = arrayQueue[queueHead];
  arrayQueue[queueHead] = "";
  queueCount--;

  if (queueHead == queueSize - 1) {
    queueHead = 0;
  } else {
    queueHead++;
  }

  cout << "H: " << queueHead << endl;
  cout << "T: " << queueTail << endl;
  cout << "word: " << Delete << endl;
  return Delete;
}

//Enqueue Sentence Method
void Queue::enqueueMultiple(string toEnqueue) {
  stringstream pablo(toEnqueue);
  string Word;
  while (getline(pablo, Word, ' ')) {
    enqueue(Word);
  }
}

//Prints queue
void Queue::printQueue() {
  if (queueIsEmpty()) {
    cout << "Empty" << endl;
    return;
  }

  for (int x = queueHead; x < queueSize; x++) {
    if (arrayQueue[x] != "") {
      cout << x << ": " << arrayQueue[x] << endl;
    }
  }

  for (int index = 0; index < queueHead; index++) {
    if (arrayQueue[index] != "") {
      cout << index << ": " << arrayQueue[index] << endl;
    }
  }
}


//Check if queue is empty
bool Queue::queueIsEmpty() {
  return (queueCount == 0);
}

//Check if queue is full
bool Queue::queueIsFull() {
  return (queueCount == queueSize);
}
