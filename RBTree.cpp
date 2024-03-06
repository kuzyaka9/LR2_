/*!
    \file 
    \brief Файл реализации красно черного дерева
*/

#include "RBTree.h"

RBNode::RBNode(flatsData data, int color, RBNode *left, RBNode *right, RBNode *parent){
    this->data = vector<flatsData> ();
    this->data.push_back(data);
    this->color = 0;
    this->left = left;
    this->right = right;
    this->parent = parent;
    this->key = data.getName();
}

RBTree::RBTree(){
    flatsData data;
    this->nil = new RBNode(data, 1, nil, nil, nil);
    this->root = nil;
}

void RBTree::leftRotate(RBNode *node){
    RBNode *y = node->right;
    node->right = y->left;
    if (y->left != nil) {
        y->left->parent = node;
    }

    if (y != nil) {
        y->parent = node->parent;
    }
    if (node->parent) {
        if (node == node->parent->left)
            node->parent->left = y;
        else
            node->parent->right = y;
    } else {
        root = y;
    }

    /* link node and y */
    y->left = node;
    if (node != nil) {
        node->parent = y;  
    }  
}

void RBTree::rightRotate(RBNode *node){
    RBNode *y = node->left;

    /* establish node->left link */
    node->left = y->right;
    if (y->right != nil) {
        y->right->parent = node;
    }

    /* establish y->parent link */
    if (y != nil) {
        y->parent = node->parent;
    }
    if (node->parent) {
        if (node == node->parent->right){
            node->parent->right = y;
        }
        else{
            node->parent->left = y;
        }
    }
    else {
        root = y;
    }

    /* link node and y */
    y->right = node;
    if (node != nil) {
        node->parent = y;
    }
}

RBNode *RBTree::binaryInsert(RBNode *nodeParent, RBNode *node, flatsData data){
    string key = data.getName();
    if (node == nil){
        node = new RBNode(data, 0, nil, nil, nodeParent);
        if(nodeParent == nil){
            root = node;
        }
        else{
            if (key > nodeParent->key){
                nodeParent->right = node;
            } 
            else{
                nodeParent->left = node;
            }
        }
    }
    else{
        if (key < node->key){
            return binaryInsert(node, node->left, data);
        }
        else if (key > node->key){
            return binaryInsert(node, node->right, data);
        }
        else{
            node->data.push_back(data);
            return node;
        }
    }
    return node;
}

void RBTree::insertData(flatsData data){
    RBNode *z = binaryInsert(nil, root, data);

    while (z != root && z->parent->color == 0){
        if(z->parent->parent->left == z->parent){
            if(z->parent->parent->right->color == 0){
                z->parent->color = 1;
                z->parent->parent->right->color = 1;
                z->parent->parent->color = 0;
                z = z->parent->parent;
            }
            else{
                if(z->parent->right == z){
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = 1;
                z->parent->parent->color = 0;
                rightRotate(z->parent->parent);
            }
        }
        else{
            if(z->parent->parent->left->color == 0){ 
                z->parent->color = 1;
                z->parent->parent->left->color = 1;
                z->parent->parent->color = 0;
                z = z->parent->parent;
            }
            else{
                if(z->parent->left == z){ 
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = 1;
                z->parent->parent->color = 0;
                leftRotate(z->parent->parent);
                
            }
        }
    }
	root->color = 1; 
}

bool RBTree::findData(string key){
	RBNode *curNode = root;
	while (curNode != nil && curNode->key != key){
	    if (curNode->key > key){
	        curNode = curNode->left;
        }
	    else{
	        curNode = curNode->right;
        }
	}
	return curNode != nil;
}

void RBTree::print(){
    printTree(root);
    cout << endl;
}

void RBTree::printTree(RBNode *node){
    if (node != nil){
        printTree(node->left);
        cout << node->key << " " << node->color << endl;
        printTree(node->right);
    }
}