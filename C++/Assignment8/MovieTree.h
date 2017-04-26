#ifndef MOVIETREE_H
#define MOVIETREE_H
#include <iostream>
using namespace std;
#include <string>

//Gustav Solis
//Assignment8
//Ishita

struct MovieNode{
    int ranking;
    string title;
    int year;
    int quantity;
    MovieNode *parent;
    MovieNode *leftChild;
    MovieNode *rightChild;

    MovieNode(){};

    MovieNode(int in_ranking, string in_title, int in_year, int in_quantity)
    {
        ranking = in_ranking;
        title = in_title;
        year = in_year;
        quantity = in_quantity;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

};

class MovieTree
{

    public:
        MovieTree();
        ~MovieTree();
        void buildTree(string file);
        void printMovieInventory();
        int countMovieNodes();
        void deleteMovieNode(string title);
        void addMovieNode(int ranking, string title, int releaseYear, int quantity);
        void findMovie(string title);
        void rentMovie(string title);

    protected:

    private:
        void DeleteAll(MovieNode * node); //use this for the post-order traversal deletion of the tree
        void printMovieInventory(MovieNode * node);
        int countMovieNodes(MovieNode *node);
        MovieNode* search(string title);
        MovieNode* searchRecursive(MovieNode *node, std::string value);
        MovieNode* treeMinimum(MovieNode *node);
        MovieNode *root;
};

#endif // MOVIETREE_H
