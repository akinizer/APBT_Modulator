
/**
* Description : Array Based Binary Search Tree content
*/

#include "AbBST.h"
#include <cmath>

 AbBST::AbBST(){
    size = 0;
 }

void insertItem(AbBinaryNode*&treeNode, int val, int loc, int size);

void AbBST::insert(int val){
    insertItem(treeBST, val, 0, size);
}

void insertItem(AbBinaryNode*&treeNode, int val, int loc, int size){

    if(size<=0) return;

    if(loc > size) cout<<"no space left"<<endl;
    else{
        if(treeNode[loc].item==-1)
            treeNode[loc].item=val;
        else{
            if(val<treeNode[loc].item)
                insertItem(treeNode, val, loc*2, size+1);
            else
                insertItem(treeNode, val, loc*2+1, size+1);
        }
    }
}