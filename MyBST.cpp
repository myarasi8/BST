//
//  MyBST.cpp
//  bst_transform
//

#include "MyBST.h"
#include <queue>



/**
 * Computes how to transform this MyBST into the target MyBST using rotations.
 * Returns a vector of rotations indicating which rotations around which nodes
 *  must be performed to transform this into the target.
 *
 * IMPORTANT: We want to transform T1 into T2 so the call should look like
 * rotations = t1.transform(t2)
 */
MyBST::MyBST() : BST()
{

}

MyBST::MyBST(vector<int>& nums) : BST(nums)
{
    
}


Node* MyBST::traverse(int index) //level order traversal
{
    queue<Node*> q;
    q.push(this->root);
    int count = 0;

    while(!q.empty())
    {
        Node* temp_node = q.front();
        q.pop();
        count++;
        //Check if we found the node the index is referring to
        if (count == index)
            return temp_node;
        //check the left of the temp_node
        if (temp_node->left)
        {
            q.push(temp_node->left);
        }
        //check the right of the temp_node
        if (temp_node->right)
        {
            q.push(temp_node->right);
        }
    }
    //if you get here, the index is too large for the tree
    return nullptr;
}

Node* MyBST::find(int value)
{
    //finds the node is V1 with the same value as the Node in V2 
    //returns the node
    queue<Node*> q;
    q.push(this->root);

    while(!q.empty())
    {
        Node* temp_node = q.front();
        q.pop();

        if (temp_node->key == value)
        {
            return temp_node;
        }

        if (temp_node->left)
        {
            //temp_node = temp_node->right;
            q.push(temp_node->left);
        }

       if (temp_node->right)
        {
            //temp_node = temp_node->left;
            q.push(temp_node->right);
        }
    }

    return nullptr;
}

int MyBST::getLevel(Node* node, Node* ptr, int height)
{
    if (node == nullptr)
    {
        return 0;
    }

    if (node->key == ptr->key)
    {
        return height;
    }

    int level = getLevel(node->left, ptr, height+1);

    if (level != 0)
    {
        return level;
    }

    return getLevel(node->right, ptr, height+1);
}


Node* MyBST::findParent(Node* root, int value)
{
    if ((root->left == nullptr) && (root->right == nullptr))
    {
        return nullptr;
    }

    if ((root->left != nullptr && root->left->key == value) || (root->right != nullptr && root->right->key == value))
    {
        return root;
    }

    else if (root->key > value)
    {
        return findParent(root->left, value);
    }

    else
    {
        return findParent(root->right, value);
    }
}


vector<Rotation> MyBST::transform(MyBST target) {
    //T1.transform(T2);
    /*** This is what you have to do ***/
    Node* V2 = target.root;
    int index2 = 1;
    vector<Rotation> instructions;
    cout << "at beginning" << endl;
    
    while(V2)
    {
        cout << "at beginning of while" << endl;
        //go through and increment index and everything 
        Node* V1 = this->find(V2->key);
        cout << "findd" << endl;
        bool set = false; //only change set to true when the levels are the same
        int L2 = target.getLevel(target.root, V2, 1); // L2 is level of V2 in T2
        cout << "get level" << endl;

        while(!set)
        {
            int L1 = this->getLevel(this->root, V1, 1); //L1 is level of V2 in T1
            cout << "before the set" << endl;
            if (L1 == L2) //if level of v1 and level of v2 are equal
            {
                cout << "at the set" << endl;
                set = true;
            }
            else
            {
                cout << "about to find parent" << endl;
                Node* parent_V1 = this->findParent(this->root, V1->key); //parent_V1 is the parent Node of V1
                cout << "found parent" << endl;
                if (parent_V1 == nullptr)
                {
                    cout << "uh oh " << endl;
                }
                cout << "Checking node " << V1->key << " at level " << L1 << " in T1, parent " << parent_V1->key << endl;
                if (V1->key < parent_V1->key)
                {
                    //Zig on parent_V1
                    cout << "if v1<pV1" << endl;
                    Rotation rot(parent_V1->key, ZIG);
                    instructions.push_back(rot);
                    if (parent_V1->key == this->root->key) // if the parent of V1 is the root node fo the BST
                    {
                        this->root = rotateRight(parent_V1);
                        cout << "here at ZIG on parent" << endl;
                    }
                    else
                    {
                        Node* grandParent_V1 = this->findParent(this->root, parent_V1->key); //grandparent of V1
                        if (parent_V1->key < grandParent_V1->key) //if parent of V1 is on the left of grandparent of V1
                        {
                            grandParent_V1->left = this->rotateRight(parent_V1);
                            cout << "here at grandparent if ZIG" << endl;
                        }
                        else
                        {
                            grandParent_V1->right = this->rotateRight(parent_V1);
                            cout << "here at grandparent else ZIG" << endl;
                        }
                    }
                }
                else if (V1->key > parent_V1->key) // V1 is on the right of its parent
                {
                    //ZAG on parent_V1
                    cout << "v1>pv1" << endl;
                    Rotation rot(parent_V1->key, ZAG);
                    instructions.push_back(rot);
                    cout << "after instructions" << endl;
                    if (parent_V1->key == this->root->key)
                    {
                        this->root = rotateLeft(parent_V1);
                        cout << "here at ZAG on parent" << endl;
                    }
                    else
                    {
                        cout << "about to find grandparent" << endl;
                        Node* grandParent_V1 = this->findParent(this->root, parent_V1->key);
                        cout << "found grandparent" << endl;
                        if (parent_V1->key < grandParent_V1->key) //if parent of V1 is on the left of grandparent of V1
                        {
                            grandParent_V1->left = this->rotateLeft(parent_V1);
                            cout << "here at grandparent if ZAG" << endl;
                        }
                        else
                        {
                            grandParent_V1->right = this->rotateLeft(parent_V1);
                            cout << "here at grandparent else ZAG" << endl;
                        }                    
                    }
                }
            }
        }
        index2++;
        cout << "at traver" << endl;
        V2 = target.traverse(index2);
        cout << "after traverse" << endl;
    }
    return instructions;
}


Node* MyBST::rotateRight(Node* Q)
{
    Node* P = Q->left;
    Q->left = P->right;
    P->right = Q;
    return P;
}

Node* MyBST::rotateLeft(Node* P)
{
    Node* Q = P->right;
    P->right = Q->left;
    Q->left = P;
    return Q;
}











