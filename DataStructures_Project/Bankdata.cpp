#include"Bankdata.h"
NodePtrB& addHeadBNode(NodePtrB& headB)
{

	string nameofbank;
	ifstream fin;
	fin.open("bankdat.txt");
	headB = new bank();
	NodePtrB NewPtrB = headB;
	fin >> NewPtrB->nameofbank;
	fin >> NewPtrB->sal_inc;
	fin >> NewPtrB->accountnumber;
	fin >> NewPtrB->branchnumber;
	fin >> NewPtrB->cnic;
	while (1)
	{
		getline(fin, nameofbank);
		getline(fin, nameofbank);
		if (nameofbank == "")
		{
			NewPtrB = NULL;
			break;
		}
		else
		{
			NewPtrB->next = new bank;
			NewPtrB = NewPtrB->next;
			NewPtrB->nameofbank = nameofbank;
			fin >> NewPtrB->sal_inc;
			fin >> NewPtrB->accountnumber;
			fin >> NewPtrB->branchnumber;
			fin >> NewPtrB->cnic;
		}
	}
	NodePtrB p = headB;
	if (p == NULL)
	{
		headB = NewPtrB;
	}
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = NewPtrB;
	}
	fin.close();
	return headB;
}
void printbank(NodePtrB& headB)
{
	NodePtrB p = headB;
	while (p != NULL)
	{
		cout << p->nameofbank << endl;
		cout << p->sal_inc << endl;
		cout << p->accountnumber << endl;
		cout << p->branchnumber << endl;
		cout << p->cnic << endl << endl;
		p = p->next;
	}
}