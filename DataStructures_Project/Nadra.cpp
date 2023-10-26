#include <iostream>   //Nadra using SLL and filing
#include <fstream>
#include <string>
#include "Nadra.h"

using namespace std;

NodePtr& addHeadNode(NodePtr& head)
{
	string name;
	ifstream fin;
	fin.open("nadra.txt");
	head = new nadra();
	NodePtr NewPtr = head;
	getline(fin, NewPtr->name);
	fin >> NewPtr->cnic;
	fin.ignore();
	getline(fin, NewPtr->fname);
	getline(fin, NewPtr->DOB);
	while (1)
	{
		getline(fin, name);
		getline(fin, name);
		if (name == "")
		{
			NewPtr = NULL;
			break;
		}
		else
		{
			NewPtr->next = new nadra;
			NewPtr = NewPtr->next;
			NewPtr->name = name;
			fin >> NewPtr->cnic;
			fin.ignore();
			getline(fin, NewPtr->fname);
			getline(fin, NewPtr->DOB);
		}
	}
	NodePtr p = head;
	if (p == NULL)
	{
		head = NewPtr;
	}
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = NewPtr;
	}
	fin.close();
	return head;
}

bool nadra_verify(NodePtr& head)
{
	NodePtr temp3 = head;
	int cnic;
	system("cls");
	cout << "\t\t\t\t Please enter your CNIC number for verification: ";
	cout << " \t \t \t \t \t \t \t                                                           \t \t \t  \t \t \t \t \t \t \t ";
	cin >> cnic;
	while (temp3 != NULL)
	{
		if (temp3->cnic == cnic)
		{
			cout << "verification completed" << endl;
			return true;
			break;
		}
		temp3 = temp3->next;

	}
}
void printnad(NodePtr& head)
{
	NodePtr p = head;
	while (p != NULL)
	{
		cout << p->name << endl;
		cout << p->cnic << endl;
		cout << p->fname << endl;
		cout << p->DOB << endl;
		cout << "\n";
		p = p->next;
	}
}
