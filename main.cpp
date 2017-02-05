//Partner: Veronica Herzog
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MyBST.h"
using namespace std;

int main()
{
	string currentLine = "";
	string currentLine2 = "";

	string file = "T1.txt";
	ifstream myfile;
	myfile.open(file.c_str());

	string file2 = "T2.txt";
	ifstream myfile2;
	myfile2.open(file2.c_str());

	vector<int>BST1;
	vector<int>BST2;

	if (!myfile.is_open())
	{
		cout << "File did not open" << endl;
	}

	else
	{
		while(getline(myfile, currentLine))
		{
			int num = stoi(currentLine);
			BST1.push_back(num);
		}

		while(getline(myfile2, currentLine2))
		{
			int num = stoi(currentLine2);
			BST2.push_back(num);
		}

	}

	MyBST T_1 = MyBST(BST1);
	MyBST T_2 = MyBST(BST2);


	vector<Rotation> rotations = T_1.transform(T_2);

	for (vector<Rotation>::iterator it = rotations.begin(); it< rotations.end(); it++)
	{
		cout << (*it).print();
		cout << '\n';
	}

	cout << T_1.print() << endl;
	cout << T_2.print() << endl;

	//after transform
	/*
	string x, y;
	x = T_1.print();
	cout << x << endl;
	y = T_2.print();
	cout << y << endl;
	*/


		//need to cout the print
}


