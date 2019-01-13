
/**
* Description : Contents of functions
*/

#include "PbBST.h"
#include <cmath>
///main constructor which tree initializes tree NULL as empty
PbBST::PbBST(){
  treeBST=NULL;
}

///functions to check whether tree is binary search tree in its rules
bool checkValidity(PbBinaryNode*);
bool PbBST::isValidBST(){
    return checkValidity(treeBST); ///starts from root
}

///takes a tree or subtree root and checks whether it is valid
bool checkValidity(PbBinaryNode*tree){
    bool validationFlag; ///flag for validation

    ///if tree is not empty
    if (tree != NULL){

        ///check if value of left child is bigger than parent
        if (tree->left != NULL && tree->left->value > tree->value)
            validationFlag = false;

        ///check if value of right child is less than parent
        else if (tree->right != NULL && tree->right->value < tree->value)
            validationFlag = false;

        ///check if anyone of child is invalid tagged
        else if (!checkValidity(tree->left) || !checkValidity(tree->right))
            validationFlag = false;

        else validationFlag = true; ///if  all consequences are suitable

        ///return the flag
        return validationFlag;
    }
    ///empty tree is valid
    else
        validationFlag = true;

    ///if everything is fine; tree is valid
    return validationFlag;
}

///functions to calculate amount of tree nodes
int amountCalc(PbBinaryNode*);
PbBinaryNode*medianCalc(PbBinaryNode*);

///function to find median of tree
int sum;
int PbBST::medianOfBST(){
    sum = amountCalc(treeBST);

    return medianCalc(treeBST)->value; ///
}

int amountCalc(PbBinaryNode*tree){
   if(tree == NULL) ///empty if there is nothing inserted
       return 0;
   return amountCalc(tree->left) + amountCalc(tree->right) + 1; ///return amount calculated both in left and right subtrees
}

///find node of median, initially NULL and its index location is zero
PbBinaryNode*curMed=NULL;
int location = 0;
PbBinaryNode*medianCalc(PbBinaryNode*tree){

   if (tree == NULL) ///if empty
       return NULL;

   curMed =  medianCalc(tree->left); ///current median node

   if (curMed != NULL)  ///if current median node is empty
        return curMed;

   if (location == sum/2)   ///if index is in middle
       return tree;

   location++;              ///update location

   return medianCalc(tree->right);  ///check right tree
}

///node destroyer
void PbBST::annihilate(PbBinaryNode*tree){
    ///if not empty
    if(tree!=NULL)  {
        annihilate(tree->left);     ///delete left nodes!
        annihilate(tree->right);    ///delete right nodes!
        delete tree;                ///leave no node alive!
    }
}

///insert requested item to tree
void insertItem(int item, PbBinaryNode *tree);
void PbBST::insert(int item){
    ///check whether tree is empty
    if(treeBST!=NULL)
        insertItem(item, treeBST);

    ///if empty, create a new node then insert
    else{
        treeBST=new PbBinaryNode;
        treeBST->value=item;
        treeBST->left=NULL;
        treeBST->right=NULL;
    }
}

void insertItem(int item, PbBinaryNode *tree){
    ///if item is less than item of current node
    if(item < tree->value){
        ///if left child is not empty
        if(tree->left!=NULL)
            insertItem(item, tree->left); ///advance to left child

        ///if left child is empty, left child becomes a new node available to insert child, new grandchildren becomes empty
        else{
            tree->left = new PbBinaryNode;
            (tree->left)->value = item;
            (tree->left)->left = NULL;    //Sets the left child of the child node to null
            (tree->left)->right=NULL;   //Sets the right child of the child node to null
        }
    }
    ///if item is greater than item of current node
    else if(item>=tree->value){
        ///if not empty advance to right child
        if(tree->right!=NULL)
            insertItem(item, tree->right);

        ///if left child is empty, make it available, insert item, make grandchildren empty
        else{
            tree->right = new PbBinaryNode;
            (tree->right)->value = item;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
        }
    }
}

///find node of an item
PbBinaryNode*find(int item, PbBinaryNode *tree);

PbBinaryNode*PbBST::findTree(int item){
    ///check whether tree is empty
    if(treeBST==NULL) return NULL;

    ///start from root
    return find(item, treeBST);

}

PbBinaryNode*find(int item, PbBinaryNode *tree){
    ///check whether subtree is empty
    if(tree!=NULL){
        ///item found, return tree
        if(item==tree->value)
            return tree;

    ///if item is less than item of current node
    if(item<tree->value)
        return find(item, tree->left); ///check left child
    else
        return find(item, tree->right); ///check right child
    }
    ///not available
    else return NULL;
}

///functions to calculate max height of the tree
int curCalcHeight(PbBinaryNode*tree){
    ///whether empty
    if (tree!=NULL){
        int leftChildHeight = curCalcHeight(tree->left); ///calculated height of left child
        int rightChildHeight = curCalcHeight(tree->right);  ///calculated height of right child

        if (leftChildHeight > rightChildHeight)         ///compare children then return deeper one
           return leftChildHeight+1;
        else
            return rightChildHeight+1;
    }
    return 0; ///empty
}

///start from root
int PbBST::getHeight(){
    return curCalcHeight(treeBST);
}
