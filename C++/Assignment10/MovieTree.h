#ifndef MOVIETREE_H
#define MOVIETREE_H

using namespace std;
#include <iostream>
#include <string>

//Gustav Solis
//Assignment10
//Ishita

struct MovieNode{
    int ranking;
    string title;
    int year;
    int quantity;
    bool isRed;
    MovieNode *parent;
    MovieNode *leftChild;
    MovieNode *rightChild;

    MovieNode(){};

    MovieNode(int in_ranking, std::string in_title, int in_year, int in_quantity)
    {
        ranking = in_ranking;
        title = in_title;
        year = in_year;
        quantity = in_quantity;
    	  leftChild = NULL;
    	  rightChild = NULL;
        parent = NULL;
        isRed = true;
    }

};

class MovieTree
{

    public:
        MovieTree();
        virtual ~MovieTree();
        void printMovieInventory();
        int countMovieNodes();
        void deleteMovieNode(std::string title);
        void addMovieNode(int ranking, std::string title, int releaseYear, int quantity);
        void findMovie(string title);
        void rentMovie(string title);
        void buildTree(string title);
        int countLongestPath();

    protected:

    private:
        void DeleteAll(MovieNode * node); //use this for the post-order traversal deletion of the tree
        void printMovieInventory(MovieNode * node);
        void leftRotate(MovieNode * x); //rotate the tree left with x as the root of the rotation
        void rightRotate(MovieNode * x); //rotate the tree right with x as the root of the rotation
        int countMovieNodes(MovieNode *node); //number of unique titles in the tree
        int countLongestPath(MovieNode *node); //longest path from node to a leaf node in the tree
        MovieNode* searchRecursive(MovieNode *node, std::string value);
        MovieNode *root;
        MovieNode *nil;


};

#endif // MOVIETREE_H
