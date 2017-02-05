#include <iostream>
using namespace std;

int main()
{
	
}

Node* MyBST::getLevel(Node* root, int value)
{
    //given a particular tree, find the level that a certain value is on
    queue<Node*> q;
    q.push(this->root);

    int index = 0;

    while(!q.empty())
    {
        Node* temp_node = q.front();
        q.pop();
        index++;

        if (temp_node->key == value)
        {
            return index;
        }

        if (temp_node->right)
        {
            q.push(temp_node->right);
        }

        if (temp_node->left)
        {
            q.push(temp_node->left);
        }
    }
}