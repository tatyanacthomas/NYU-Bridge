/*
INSTRUCTIONS
In this assignment, it is required that you fill out areas under comments labeled as "TODO" appropriately based on the accompanying directions.
You are also required to follow any directions accompanying comments such as "NOTE".
You can add/modify code anywhere, with the exception of the provided "main" (which we will use for testing).
You can use the constants RED and BLACK, instead of the ints 0 and 1, when appropriate.
*/

#include <iostream>
#include <math.h> // for asserting height
#include <queue>
#include <cassert>

using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c) {
    return (c==0)?1:0;
}

template <class T>
class RBTNode {
    RBTNode<T> *parent, *left, *right;
    T data;
    int color;

public:
    RBTNode(T data)
        : data(data),
          color(RED),
          parent(nullptr),
          left(nullptr),
          right(nullptr) {}
    friend class RBT<T>;
    void prettyPrint(int indent) const;

    template <class T1>
    friend void swapColor(RBTNode<T1> *);
    template <class T1>
    friend int getColor(RBTNode<T1> *);

    int height() const;
};

template <class T>
int RBTNode<T>::height() const {
    int left_h = 0;
    if (left != nullptr) {
        left_h = left->height();
    }
    int right_h = 0;
    if (right != nullptr) {
        right_h = right->height();
    }
    return 1 + max(left_h, right_h);
}

template <class T>
void RBTNode<T>::prettyPrint(int indent) const {
    if (right != nullptr) {
        right->prettyPrint(indent + 1);
    }
    int margin = indent * 2;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
    if (left != nullptr) {
        left->prettyPrint(indent + 1);
    }
}

template <class T>
void swapColor(RBTNode<T> *node) {
    if (node != nullptr) {
        node->color = swapColor(node->color);
    }
}

// getColor handles null nodes
template <class T>
int getColor(RBTNode<T> *node) {
    if (node != nullptr) {
        return node->color;
    }
    return BLACK;
}

template <class T>
class RBT {
    RBTNode<T> *root;
    void singleCCR(RBTNode<T> *&point);
    void doubleCR(RBTNode<T> *&point);
    void singleCR(RBTNode<T> *&point);
    void doubleCCR(RBTNode<T> *&point);

public:
    RBT() : root(nullptr) {}

    void insert(const T &);
    void insert(const T &, RBTNode<T> *&point, RBTNode<T> *parent);
    void prettyPrint() const { root->prettyPrint(0); }
    RBTNode<T>* getUnc(RBTNode<T>* node);
    void insertHelp(RBTNode<T>* node);
    int height() const { return root->height(); }
};

template <class T>
void RBT<T>::doubleCCR(RBTNode<T> *&point) {
    singleCR(point->right);
    singleCCR(point);
}

template <class T>
void RBT<T>::doubleCR(RBTNode<T> *&point) {
    singleCCR(point->left);
    singleCR(point);
}


template <class T>
void RBT<T>::singleCCR(RBTNode<T> *&point) {

    RBTNode<T> *grandpa = point;
    RBTNode<T> *parent = point->right;
    RBTNode<T> *child = parent->left;

    // Perform the rotation
    parent->left = grandpa;
    grandpa->right = child;

    //all the parent stuff
    if (child != nullptr) {   //swap child to og gparent
        child->parent = grandpa;
    }
    parent->parent = grandpa->parent;

   //update root if this is a root rotation
    if (grandpa->parent == nullptr) {
        root = parent;
    } else if (grandpa == grandpa->parent->left) {
        grandpa->parent->left = parent;
    } else {
        grandpa->parent->right = parent;
    }

    grandpa->parent = parent;
}

template <class T>
void RBT<T>::singleCR(RBTNode<T> *&point) {


    RBTNode<T> *grandpa = point;
    RBTNode<T> *parent = point->left;
    RBTNode<T> *child = parent->right;

    // Perform the rotation
    parent->right = grandpa;
    grandpa->left = child;

    //all the parent stuff
    if (child != nullptr) {
        child->parent = grandpa;
    }

    parent->parent = grandpa->parent;

    // if root, update accordingly
    if (grandpa->parent == nullptr) {
        root = parent;
    } else if (grandpa == grandpa->parent->left) {
        grandpa->parent->left = parent;
    } else {
        grandpa->parent->right = parent;
    }

    grandpa->parent = parent;
}


template <class T>
void RBT<T>::insert(const T &toInsert, RBTNode<T> *&point, RBTNode<T> *parent) {
    if (point == nullptr) {               // leaf location is found so insert node
        point = new RBTNode<T>(toInsert); // modifies the pointer itself since *point
                                          // is passed by reference
        point->parent = parent;

        // tree rule violation helper function for insertions and recoloring;
        insertHelp(point);
    } else if (toInsert < point->data) { // recurse down the tree to the left to find the correct leaf location
        insert(toInsert, point->left, point);
    } else { // recurse down the tree to the right to find the correct leaf location
        insert(toInsert, point->right, point);
    }
}

template <class T>
void RBT<T>::insertHelp(RBTNode<T>* node)
{
   //while the tree still needs recoloring
    while (node != root && node->parent->color == RED) {
        RBTNode<T>* uncle = getUnc(node);  // Get the uncle
        if (uncle != nullptr && uncle->color == RED) {
            // If uncle is red, flip the colors
            node->parent->color = BLACK;
            uncle->color = BLACK;
            node->parent->parent->color = RED;
            node = node->parent->parent;  // Move up tree and keep fixing
        } else {
            // rotation is necessary
            if (node == node->parent->right && node->parent == node->parent->parent->left) {
                // LR case
                node = node->parent;
                singleCCR(node);
            } else if (node == node->parent->left && node->parent == node->parent->parent->right) {
                // RL case
                node = node->parent;
                singleCR(node);
            }

            // Now we do the rotation to fix it
            node->parent->color = BLACK;
            node->parent->parent->color = RED;
            if (node == node->parent->left) {
                singleCR(node->parent->parent);
            } else {
                singleCCR(node->parent->parent);
            }
        }
    }

    root->color = BLACK;  // root is always black, no matter what
}

template <class T>
RBTNode<T>* RBT<T>::getUnc(RBTNode<T>* node) {
    if (node == nullptr) {
        return nullptr;  // No node means no uncle
    }

    if (node->parent == nullptr || node->parent->parent == nullptr) {
        return nullptr;  // If no grandparent, no uncle either
    }

    RBTNode<T>* grandparent = node->parent->parent;

    if (node->parent == grandparent->left) {
        if (grandparent->right != nullptr) {
            return grandparent->right;  // Uncle is on the right
        } else {
            return nullptr;  // No uncle on the right side
        }
    } else {
        if (grandparent->left != nullptr) {
            return grandparent->left;  // Uncle is on the left
        } else {
            return nullptr;  // No uncle on the left side
        }
    }
}


template <class T>
void RBT<T>::insert(const T &toInsert) {
    insert(toInsert, root, nullptr);
}

// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 10;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }
    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */
    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    assert(height <= 2 * log2(count));
    cout<<endl;
    cout<<"---------------------"<<endl;
    cout<<endl;
    RBT<int> c;
    count = 5;
    for (int i = count; i > 0; i--) {
        c.insert(i);
    }
    c.prettyPrint();
    /* EXPECTED OUTPUT:
                    Data: 5
                    COLOR: BLACK
    Data: 4
    COLOR: BLACK
                                    Data: 3
                                    COLOR: RED
                    Data: 2
                    COLOR: BLACK
                                    Data: 1
                                    COLOR: RED
    */
    height = c.height();
    assert(height <= 2 * log2(count));
}
