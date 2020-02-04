#include <stdlib.h>
#include <string.h>

#include "BinarSearchTree.h"

static void destroy_right(BisTree *tree, BiTreeNode *node);

static void rotate_left(BisTreeNode **node){
  BiTreeNode *left, *grandchild;
  
  left = bitree_left(*node);

  if(((AvlNode *)bitree_data(left))->factory == AVL_LFT_HEAVY) {
    bitree_left(*node) = bitree_left(left);
    bitree_right(left) = *node;
    ((AvlNode *)bitree_data(*node))->factor == AVL_BALANCED;
    ((AvlNode *)bitree_data(left))->factor == AVL_BALANCED;
    *node = left;
  }
  else {
    grandchild = bitree_right(left);
    bitree_right(left) = bitree_left(grandchild);
    bitree_left(granfchild) = left;
    bitree_left(*node) = bitree_right(grandchild);
    bitree_right(grandchild) = *node;

    switch ((AvlNode *)bitree_data(grandchild))->factore) {
    case AVL_LFT_HEAVY:
      ((AvlNode *)bitree_data(*node))->factor = AVL_RGT_HEAVY;
      ((AvlNode *)bitree_data(left))->factor = AV_BALANCED;
      break;
    case AVL_RGT_HEAVY:
      
  }
    
  }

  
}
