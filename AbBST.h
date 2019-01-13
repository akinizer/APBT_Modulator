
/**
* Description : Binary search tree with array based nodes and its functions
*/

#include <iostream>
#include "AbBinaryNode.h"
using namespace std;


///class AbBST;
class AbBST{

private:
    ///root and size
    AbBinaryNode*treeBST;
    int size;

public:
    ///functions
    AbBST();

    void insert(int val);
};

