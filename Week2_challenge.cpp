/********************************************************
Your job is to implement the function "int count(Node *n)"
that computes and returns the number of nodes in the binary
tree that has n as its root.

When you write your code below, assume that a class type
called "node" has already been defined for you; you cannot
change the class definition. This class type has two child
pointers ("left", "right").
there is also a constructor node() that initializes the children
to nullptrs and a destructor that deallocates the subtree's
memory recursively.

You may assume that the following Node class has already
been defined for you previously:

class Node {
public:
  Node *left, *right;
  Node() { left = right = nullptr; }
  ~Node() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
  }
};

You may also assume that iostream has already been included.

Implement the function "int count(Node *n)" below to return
an integer representing the number of nodes in the subtree
of Node n (including Node n itself).

*********************************************************/
#include <iostream>
using namespace std;

class Node {
public:
  Node *left, *right;
  Node() { left = right = nullptr; }
  ~Node() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
  }
};

int count(Node *n) {

  // Implement count() here.
  // This implementation is from brian chiang's code, 
  
  // Your job is to implement the function "int count(Node *n)"
  // that computes and returns the number of nodes in the binary
  // tree that has n as its root.
  if (nullptr == n)
  {
    //if visit empty subtree, return 0;
    return 0;
  }
  else
  {
    //node count of node n;
    // = node count of left sub tree + node count of right sub tree + 1 (self)
    //this is a recursive function that returns the number of nodes in the left branch
    //and the number of nodes in the right branch, plus the actual node itself (+1)
    return count (n->left) + count(n->right)+1;
  }
}
//end of function count (node *n)

//expected output of main
/*
  6
*/
int main() {

  // implement the node tree
  // total of 6 nodes implemented here
  Node *n = new Node(); //root node
  n->left = new Node(); //left branch
  n->right = new Node();//right branch
  n->right->left = new Node(); //left branch under right branch
  n->right->right = new Node();//right branch under right branch
  n->right->right->right = new Node(); //right branch under right branch of right branch

  // This should print a count of six nodes
  std::cout << count(n) << std::endl;

  // Deleting n is sufficient to delete the entire tree
  // because this will trigger the recursively-defined
  // destructor of the Node class.
  // good practice to save memory.
  delete n;
  n = nullptr;

  return 0;
}
