
/**
* Description : Binary search tree with pointer nodes with its functions
*/
#include "PbBinaryNode.h"
#include <iostream>
using namespace std;

class PbBST{
private:
    ///supportive
    PbBinaryNode *findTree(int item);
    PbBinaryNode *treeBST;

public:
    ///constructor, insertion, deletion
    PbBST();
    void annihilate(PbBinaryNode *tree);
    void insert(int item);

    ///validation function

    bool isValidBST();

    ///median and height functions

    int medianOfBST();

    int getHeight();

};

