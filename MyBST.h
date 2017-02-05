#ifndef MyBST_h
#define MyBST_h

#include <iostream>
#include "BST.h"

using namespace std;

class MyBST : public BST
{
public:
	MyBST();
	MyBST(vector<int>& nums);
	Node* traverse(int index);
	Node* find(int value);
	int getLevel(Node* node, Node* ptr, int height);
	Node* findParent(Node* root, int value);
	//vector<Rotation> MyBST::transform(MyBST target);
	vector<Rotation>transform(MyBST target);
	Node* rotateRight(Node* Q);
	Node* rotateLeft(Node* P);	

};


#endif