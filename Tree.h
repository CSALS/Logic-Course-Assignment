#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <string>
using namespace std;

class Tree
{
        public:
        string postfix;
        Tree(string input);     
        Node* rootptr;
        Node* getnewnode(char idata);
        void makeTree();
        string chn;
        void inorder(Node* root);
};

#endif




