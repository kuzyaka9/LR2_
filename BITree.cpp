/*!
    \brief Файл с реализацией класса бинарного дерева

*/

#include "BITree.h"

BINode::BINode(flatsData data){
    this->left = NULL;
    this->right = NULL;
    this->data = vector<flatsData> ();
    this->data.push_back(data);
    this->key = data.getName();
}

BITree::BITree(){
    this->root = NULL;
}

bool BITree::findData(const string &key){
    BINode *curNode = root;

    while (curNode && curNode->key != key){
        if (curNode->key > key){
            curNode = curNode->left;
        }
        else{
            curNode = curNode->right;
        }
    }
    return curNode != NULL;
}

void BITree::insertData(flatsData &data){
    if (root == NULL){
        root = new BINode(data);
        return;
    }

    string key = data.getName();
    BINode *curNode = root;
    while (true){
        if (curNode->key > key){
            if (curNode->left == NULL){
                curNode->left = new BINode(data);
                break;
            }
            curNode = curNode->left;
        }
        else if (curNode->key < key){
            if (curNode->right == NULL){
                curNode->right = new BINode(data);
                break;
            }
            curNode = curNode->right;
        }
        else {
            curNode->data.push_back(data);
            break;
        }
    }
}

void BITree::print(){
    printTree(root);
    cout << endl;
}

void BITree::printTree(BINode *node){
    if (node){
        printTree(node->left);
        cout << node->key << endl;
        printTree(node->right);
    }
}

void BITree::del(BINode *node){
    if (node){
        del(node->left);
        del(node->right);
        delete node;
    }
}

BITree::~BITree(){
    del(root);

}