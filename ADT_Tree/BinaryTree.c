#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "BinaryTree.h"

void Bitree_init(BiTree *tree, void (*destroy)(void *data)) {
  bitree_size(tree) = 0;
  bitree_root(tree) = NULL;
  tree->destroy = destroy;

  return;

}

void bitree_destroy(BiTree *tree) {

  bitree_rem_left(tree, NULL);
  memset(tree, 0, sizeof(BiTree));
  return;
  
}

int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data) {
  BiTreeNode *newNode,
    **position;

  if (node == NULL) {
    if (bitree_size(tree) > 0)
      return -1;
    position = &bitree_root(tree);
    
  }
  else {
    if (bitree_left(node) != NULL)
      return -1;
    position = &node->left;
  }

  if ((newNode = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == NULL)
    return -1;

  bitree_data(newNode) =(void *) data;
  bitree_left(newNode) = NULL;
  bitree_right(newNode) = NULL;
  bitree_size(tree)++;
  *position = newNode;
  
  return 0;
  
}

int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data) {

  BiTreeNode *newNode,
    **position;

  if (node == NULL) {

    if (bitree_size(tree) > 0)
      return -1;

    position = &bitree_root(tree);
    
  }
  else {

    if (bitree_right(node) != NULL)
      return -1;

    position = &bitree_right(node);
  }

  if ((newNode = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == NULL)
    return -1;

  bitree_data(newNode) = (void *)data;
  bitree_left(newNode) = NULL;
  bitree_right(newNode) = NULL;
  *position = newNode;
  bitree_size(tree)++;
  
  return 0;
}

void bitree_rem_left(BiTree *tree, BiTreeNode *node) {
  BiTreeNode **position;

  if (bitree_size(tree) == 0)
    return;

  if (node == NULL)
    position = &bitree_root(tree);
  else
    position = &bitree_left(node);

  if (*position != NULL) {
    bitree_rem_left(tree, *position);
    bitree_rem_right(tree, *position);

    if (tree->destroy != NULL) {
      tree->destroy(bitree_data(*position));
    }

    free(*position);
    *position = NULL;

    tree->size--;
  }

  return;
}

void bitree_rem_right(BiTree *tree, BiTreeNode *node) {
  BiTreeNode **position;

  if (bitree_size(tree) == 0)
    return;

  if (node == NULL)
    position = &bitree_root(tree);
  else
    position = &bitree_right(node);

  if (*position != NULL) {
    bitree_rem_left(tree, *position);
    bitree_rem_right(tree, *position);

    if (tree->destroy != NULL) {
      tree->destroy(bitree_data(*position));
    }
    free(*position);
    *position = NULL;
    bitree_size(tree)--;
  }
  return;
}

int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data) {
  Bitree_init(merge, left->destroy);

  if (bitree_ins_left(merge, NULL, data) != 0) {
    bitree_destroy(merge);
    return -1;
  }

  bitree_root(merge)->left = bitree_root(left);
  bitree_root(merge)->right = bitree_root(right);
  bitree_size(merge) += bitree_size(left) + bitree_size(right);

  left->root = NULL;
  left->size = 0;
  right->root = NULL;
  right->size = 0;

  return 0;
}
