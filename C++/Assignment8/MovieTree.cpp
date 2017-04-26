#include <iostream>
#include "MovieTree.h"
#include <fstream>
#include <sstream>
using namespace std;

//Gustav Solis
//Assignment8
//Ishita

MovieTree::MovieTree() {
  root = NULL;
}

//Destructor
MovieTree::~MovieTree() {
  DeleteAll(root);
}


//PUBLIC FUNCTIONS

//POPULATES THE TREE BY PARSING THROUGH THE TEXT FILE AND PUSHING TO ADD NODE
void MovieTree::buildTree(string file){
  int tRanking = 0;
  string tTitle = "";
  int tYear = 0;
  int tQuantity = 0;
  ifstream movies;
  movies.open(file, ifstream::in);
  string currentLine;
  while(getline(movies, currentLine)) {
    stringstream sentence(currentLine);
    string currentWord;
    int count = 0;

    //ASSIGNS INFO TO VARIABLES, SENDS TO NODE FUNCTION
    while(getline(sentence, currentWord, ',')) {
      if(count == 0){
        tRanking = stoi(currentWord);
      }
      else if(count == 1){
        tTitle = currentWord;
      }
      else if(count == 2){
        tYear = stoi(currentWord);
      }
      else if(count == 3){
        tQuantity = stoi(currentWord);
      }
      count++;
    }

    addMovieNode(tRanking, tTitle, tYear, tQuantity);
  }

}

//COUNTS AMOUNT OF NODES IN BST
int MovieTree::countMovieNodes(){
  int *c = 0;
  return countMovieNodes(root);
}


//DELETE NODES WITH 0, 1, OR 2 CHILDREN
void MovieTree::deleteMovieNode(string title){
  MovieNode * current = root;

  while (current != NULL){
    if (current -> title == title){
      if (current -> leftChild == NULL and current -> rightChild == NULL){
        if (current -> parent -> leftChild == current){
          current -> parent -> leftChild = NULL;
        } else{
          current -> parent -> rightChild = NULL;
        }
        delete current;
        break;
      }
      if (current -> leftChild != NULL and current -> rightChild != NULL){
        MovieNode * minimum = current -> rightChild;
        while (minimum -> leftChild != NULL){
          minimum = minimum -> leftChild;
        }
        if (minimum -> parent == current){
          if (current -> parent -> leftChild == current){
            current -> parent -> leftChild = minimum;
            minimum -> parent = current -> parent;
            current -> leftChild -> parent = minimum;
            minimum -> leftChild = current -> leftChild;
          } else{
            current -> parent -> rightChild = minimum;
            minimum -> parent = current -> parent;
            current -> leftChild -> parent = minimum;
            minimum -> leftChild = current -> leftChild;
          }
        } else{
          if (current -> parent -> leftChild == current){
            if (minimum -> rightChild != NULL){
              minimum -> parent -> leftChild = minimum -> rightChild;
              minimum -> rightChild -> parent = minimum -> parent;
            }
            minimum -> parent = current -> parent;
            current -> parent -> leftChild = minimum;
            minimum -> leftChild = current -> leftChild;
            minimum -> rightChild = current -> rightChild;
            current -> rightChild -> parent = minimum;
            current -> leftChild -> parent = minimum;
          } else{
            if (minimum -> rightChild != NULL){
              minimum -> parent -> leftChild = minimum -> rightChild;
              minimum -> rightChild -> parent = minimum -> parent;
            }
            minimum -> parent = current -> parent;
            current -> parent -> rightChild = minimum;
            minimum -> leftChild = current -> leftChild;
            minimum -> rightChild = current -> rightChild;
            current -> rightChild -> parent = minimum;
            current -> leftChild -> parent = minimum;
          }
        }
        delete current;
        break;
      }
      else{
        if (current -> leftChild){
          MovieNode *temp = current -> leftChild;
          if (current -> parent -> leftChild == current){
            current -> parent -> leftChild = current -> leftChild;
          }
          else {
            current -> parent -> rightChild = current -> leftChild;
          }
          current->leftChild->parent = current->parent;
        } else{
          MovieNode *temp =current->rightChild;
          if (current -> parent -> rightChild == current){
              current -> parent -> rightChild = temp;
          }
          else {
              current -> parent -> leftChild = temp;
          }
          temp -> parent = current -> parent;
          delete current;
          break;
        }
      }
    }

    else if (current -> title.compare(title) > 0){
      current = current -> leftChild;
    }
    else{
      current = current -> rightChild;
    }
  }

  if (current == NULL){
    cout << "Movie not found." << endl;
  }
}

//ADDS INDIVIDUAL NODES TO TREE
void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity){
  MovieNode *current = root;
  MovieNode *parent = NULL;
  MovieNode *New = new MovieNode(ranking, title, releaseYear, quantity);

  while(current != NULL){
    parent = current;
    if(New -> title < current -> title){
      current = current -> leftChild;
    }
    else if(New -> title >= current -> title){
      current = current -> rightChild;
    }
  }

  if(parent == NULL){
    root = New;
  }
  else if(New -> title >= parent -> title){
    parent -> rightChild = New;
    New -> parent = parent;
  }
  else if(New -> title < parent -> title){
    parent -> leftChild = New;
    New -> parent = parent;
  }
}


//FINDS MOVIE BY RECURSIVELY SEARCHING
void MovieTree::findMovie(string title){
  MovieNode *temp = searchRecursive(root, title);
  if(temp == NULL){
    cout << "Movie not found." << endl;
    return;
  }
  else {
    cout << "Movie Info:" << endl;
    cout << "===========" << endl;
    cout << "Ranking:" << temp->ranking << endl;
    cout << "Title:" << temp->title << endl;
    cout << "Year:" << temp->year << endl;
    cout << "Quantity:" << temp->quantity << endl;
  }
}

//FINDS MOVIE, IF FOUND, DEDUCTS 1 FROM QUANITY TILL 0
void MovieTree::rentMovie(string title) {
  bool found = false;
  MovieNode * current = root;
  while (current != NULL) {
    if (current -> title.compare(title) > 0) {
      current = current -> leftChild;
    } else if (current -> title.compare(title) < 0) {
      current = current -> rightChild;
    } else {
      found = true;
      if (current -> quantity > 0) {
        current -> quantity = current -> quantity - 1;
        cout << "Movie has been rented." << endl;
        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:" << current -> ranking << endl;
        cout << "Title:" << current -> title << endl;
        cout << "Year:" << current -> year << endl;
        cout << "Quantity:" << current -> quantity << endl;
        if (current -> quantity == 0) {
          deleteMovieNode(current -> title);
        }
      } else {
        cout << "Movie out of stock." << endl;
      }

      break;
    }
  }

  if (!found) {
    cout << "Movie not found." << endl;
  }
}


//PRIVATE FUNCTIONS

//DELETES ALL NODES
void MovieTree::DeleteAll(MovieNode * node){
  if (node -> leftChild != NULL) {
      DeleteAll(node -> leftChild);
  }

  if (node -> rightChild != NULL) {
      DeleteAll(node -> rightChild);
  }

  cout << "Deleting: " << node -> title << endl;
  delete node;
}

//PRINTS
void MovieTree::printMovieInventory(){
    printMovieInventory(root);
}


//PRINTS TREE
void MovieTree::printMovieInventory(MovieNode * node){
    if (node -> leftChild != NULL){
        printMovieInventory(node -> leftChild);
    }
    cout<<"Movie: "<<node->title<<" "<<node->quantity<<endl;
    if (node -> rightChild != NULL){
        printMovieInventory(node -> rightChild);
    }
}

//COUNTS NODES
int MovieTree::countMovieNodes(MovieNode *node){
    if (!node) {
      return 0;
    }
    return countMovieNodes(node -> leftChild) + countMovieNodes(node -> rightChild) + 1;
}



//MovieNode* MovieTree::search(string title){
//}

//IN USE WITH FINDMOVIE
MovieNode* MovieTree::searchRecursive(MovieNode *node, string value){
    if (node->title == value) {
      return node;
    }
    if (value < node->title && node->leftChild != NULL) {
      return searchRecursive(node->leftChild, value);
    } else if (value >= node->title && node->rightChild != NULL) {
      return searchRecursive(node->rightChild, value);
    } else {
      return NULL;
    }
}

//MovieNode* MovieTree::treeMinimum(MovieNode *node){

//}
