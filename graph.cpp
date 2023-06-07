#include "graph.h"
//
BinaryTree::Node::Node(int d, Node* p):
    data(d), parent(p) {
   leftChild = nullptr; 
   rightChild = nullptr;
}
//
BinaryTree::Node::~Node() {
    // чистим за собой память
    if(rightChild != nullptr)
        delete rightChild;
    if(leftChild != nullptr)
        delete leftChild;
}
//
BinaryTree::BinaryTree() {
    root = nullptr;
}
//
BinaryTree::~BinaryTree() {
    if(root != nullptr)
    {
        delete root;
    }
}   
void BinaryTree::addInt(int newdata) {
    if(root == nullptr) {
        // если дерево пустое, то новый элемент станет корнем
        root = new Node(newdata);
    }
    else {
        Node* current = root; // начинаем с корня
        Node* newNode = nullptr;
        while(newNode == nullptr) {
            if (current->data >= newdata) {
                // если элемент меньше текущего, идем влево
                if(current->leftChild != nullptr) {
                    current = current->leftChild;
                    continue;
                }
                // если левого узла нет, то нашли место для нового элемента
                newNode = new Node(newdata, current);
                current->leftChild = newNode;
            }
            else {
                // если элемент меньше текущего, идем вправо
                if (current->rightChild != nullptr) {
                    current = current->rightChild;
                    continue;
                }
                // если правого узла нет, то нашли место для нового элемента
                newNode = new Node(newdata, current);
                current->rightChild = newNode;
            }
        }
    }
}
// проверка является ли узел листом        
bool BinaryTree::isLeaf(Node* check) {
    return check->leftChild == nullptr 
           && check->rightChild == nullptr;
}

// проверка, являтся ли узел корневым
bool BinaryTree::isRoot(Node* check) {
    return check == root;         
}

BinaryTree::Node* BinaryTree::findNodeByData(int finddata) {
    // Ваш код
    if(root == nullptr)
    {return nullptr;}
    else{
    if(root->data == finddata)
    {
        return root;
    }
    
    Node* current = root;
    while(current-> data != finddata)
    {
        if(current->data == finddata)
        {
            return current;
        }
        if(current->data < finddata )
        {
            if(current->leftChild != nullptr)
            {   
                current = current->leftChild;
                continue;
            }
        }
        if(current->data > finddata)
        {
            current = current->rightChild;
            continue;
        }
        else
        {
            return nullptr;
        }
    }
}
    return nullptr;
}
// удаление элемента
void BinaryTree::delInt(int deldata) {
    // Ваш код
    Node* current = findNodeByData(deldata);
    if(current->leftChild == nullptr && current->rightChild == nullptr)
    {   
        delete current;
    }
    if(current->leftChild == nullptr && current->rightChild != nullptr)
    {
        current->rightChild->parent = current->parent;
        delete current;
    }
    if(current->leftChild != nullptr && current->rightChild == nullptr)
    {
        current->leftChild->parent = current->parent;
        delete current;
    }
    else
    {   
        Node* current1 = current;
        while(current->rightChild != nullptr)
        {
            current1 = current->rightChild;
            continue;
        }
        current1->parent->rightChild = nullptr;
        current1->parent = current->parent;
        current1->rightChild = current->rightChild;
        current1->leftChild = current->leftChild;
        
        delete current;
        
    }
}

int main()
{
    BinaryTree* tree = new BinaryTree();
    tree->addInt(12);
    tree->addInt(5);
    tree->addInt(10);
    tree->addInt(4);
    tree->addInt(6);
    tree->addInt(15);

    tree->findNodeByData(6);

}
