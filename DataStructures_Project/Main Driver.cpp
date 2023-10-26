#include "Bankdata.h"
#include "Bankdata.cpp"
#include"Nadra.h"
#include"Nadra.cpp"
#include"login.h" 
#include"login.cpp"
#include <iostream>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
class fbr
{
public:
	string occupation;
	float income{};
	int car_s{}, car_reg{}, house_s{}, house_reg{};
	int cnic=0, c1=0, c2=0, c3=0, c4=0, flag=0;
	fbr* next{};
};

typedef fbr* NodePtrF;
void mainmenu(NodePtrF& headF, NodePtrB& headB, NodePtr& head);
void gotoxy(short x, short y);

NodePtrF& addHeadFNode(NodePtrF& headF)
{
	string occupation;
	ifstream fin;
	fin.open("fbrdat.txt");

	headF = new fbr();
	NodePtrF NewPtrF = headF;

	fin >> NewPtrF->occupation;
	fin >> NewPtrF->income;
	fin >> NewPtrF->car_s;
	fin >> NewPtrF->car_reg;
	fin >> NewPtrF->house_s;
	fin >> NewPtrF->house_reg;
	fin >> NewPtrF->cnic;
	fin >> NewPtrF->c1;
	fin >> NewPtrF->c2;
	fin >> NewPtrF->c3;
	fin >> NewPtrF->c4;
	fin >> NewPtrF->flag;
	while (1)
	{
		getline(fin, occupation);
		getline(fin, occupation);
		if (occupation == "")
		{
			NewPtrF = NULL;
			break;
		}
		else
		{
			NewPtrF->next = new fbr;
			NewPtrF = NewPtrF->next;
			NewPtrF->occupation = occupation;
			fin >> NewPtrF->income;
			fin >> NewPtrF->car_s;
			fin >> NewPtrF->car_reg;
			fin >> NewPtrF->house_s;
			fin >> NewPtrF->house_reg;
			fin >> NewPtrF->cnic;
			fin >> NewPtrF->c1;
			fin >> NewPtrF->c2;
			fin >> NewPtrF->c3;
			fin >> NewPtrF->c4;
			fin >> NewPtrF->flag;
		}
	}
	NodePtrF p = headF;
	if (p == NULL)
	{
		headF = NewPtrF;
	}
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = NewPtrF;
	}
	fin.close();
	return headF;
}
void printList(NodePtrF& headF) {
	NodePtrF p = headF;
	while (p != NULL)
	{
		cout << p->occupation << endl;
		cout << p->income << endl;
		cout << p->car_s << endl;
		cout << p->car_reg << endl;
		cout << p->house_s << endl;
		cout << p->house_reg << endl;
		cout << p->cnic << endl;
		cout << p->c1 << endl;
		cout << p->c2 << endl;
		cout << p->c3 << endl;
		cout << p->c4 << endl;
		cout << p->flag << endl;
		p = p->next;
	}
}

void cal_tax(NodePtrF& headF, NodePtrB& headB,NodePtr& head)
{
	int cnic;
	NodePtrF temp = headF;
	NodePtrB temp2 = headB;
	NodePtr temp3=head;
	gotoxy(39,11);
	cout << "Please enter your CNIC again for calculating income tax" << endl;
	gotoxy(57, 12);
	cin >> cnic;
	if(cnic==temp3->cnic)
	{
	while (temp != NULL && temp2 != NULL)
	{
		if (temp->cnic == cnic && temp2->cnic == cnic)
		{
			break;
		}
		temp = temp->next;
		temp2 = temp2->next;
	}
	float income_tax = 0, per = 0, taxable_income = 0;
	if (temp->occupation == "Employee")
	{
		if (temp->income == temp2->sal_inc)
		{
			if (temp->income <= 60000)
			{
				income_tax = 0;
				gotoxy(39, 13);
				cout << "The Income Tax is:" << income_tax << endl;
			}
			else if (temp->income >= 80000 && temp->income <= 110000)
			{
				taxable_income = temp->income - 80000;
				per = (temp->income / 100) * 5;
				income_tax = per + 15000;
				gotoxy(39, 13);
				cout << "The Income Tax is:" << income_tax << endl;
			}
			else if (temp->income > 110000 && temp->income <= 150000)
			{
				taxable_income = temp->income - 110000;
				per = (taxable_income / 100) * 10;
				income_tax = per + 35000;
				gotoxy(39, 13);
				cout << "The Income Tax is:" << income_tax << endl;
			}
			else if (temp->income > 150000 && temp->income <= 250000)
			{
				taxable_income = temp->income - 150000;
				per = (taxable_income / 100) * 17;
				income_tax = per + 50000;
				gotoxy(39, 13);
				cout << "The Income Tax is:" << income_tax << endl;
			}
		}
		else
		{
			gotoxy(39, 13);
			cout << "The provided information is incorrect. Income Tax can't be calculated." << endl;
		}
	}
	else if (temp->occupation == "Businessman")
	{
		if (temp->income == temp2->sal_inc)
		{
			if (temp->income <= 100000)
			{
				income_tax = 0;
				gotoxy(39, 13);
				cout << "The Income Tax is:" << income_tax << endl;
			}
			else if (temp->income > 100000 && temp->income <= 200000)
			{
				taxable_income = temp->income - 100000;
				per = (taxable_income / 100) * 5;
				income_tax = per + 10000;
				gotoxy(39, 13);
				cout << "The Income Tax is:" << income_tax << endl;
			}
			else if (temp->income > 200000 && temp->income <= 300000)
			{
				taxable_income = temp->income - 200000;
				per = (taxable_income / 100) * 10;
				income_tax = per + 25000;
				gotoxy(39, 13);
				cout << "The Income Tax is:" << income_tax << endl;
			}
			else if (temp->income > 300000 && temp->income <= 400000)
			{
				taxable_income = temp->income - 300000;
				per = (taxable_income / 100) * 17;
				income_tax = per + 50000;
				gotoxy(39, 13);
				cout << "The Income Tax is:" << income_tax << endl;
			}
		}
		else
		{
			gotoxy(39, 13);
			cout << "The provided information is incorrect. Income Tax can't be calculated." << endl;
		}
	}
}
	else
		{
			gotoxy(39,11);
			cout<<"there is a contradiction in the entered and verified CNIC"<<endl;
		}
}
void whdtax(NodePtrF& headF)
{
	NodePtrF temp = headF;
	int regn;
	gotoxy(39, 11);
	cout << "Please Enter your Vehicle Registration number:" << endl;
	gotoxy(57, 12);
	cin >> regn;
	while (temp != NULL)
	{
		if (temp->car_reg == regn)
		{
			break;
		}
		temp = temp->next;
	}
	float vehicle_tax = 0;
	if (temp->car_reg <= 1000)
	{
		vehicle_tax = 800;
		gotoxy(39, 13);
		cout << "The Withholding Vehicle Tax is:" << vehicle_tax << endl;
	}
	else if (temp->car_reg >= 1001 && temp->car_reg <= 1199)
	{
		vehicle_tax = 1500;
		gotoxy(39, 13);
		cout << "The Withholding Vehicle Tax is:" << vehicle_tax << endl;
	}
	else if (temp->car_reg >= 1200 && temp->car_reg <= 1299)
	{
		vehicle_tax = 1750;
		gotoxy(39, 13);
		cout << "The Withholding Vehicle Tax is:" << vehicle_tax << endl;
	}
	else if (temp->car_reg >= 1300 && temp->car_reg <= 1499)
	{
		vehicle_tax = 2500;
		gotoxy(39, 13);
		cout << "The Withholding Vehicle Tax is:" << vehicle_tax << endl;
	}
	else if (temp->car_reg >= 1500 && temp->car_reg <= 1599)
	{
		vehicle_tax = 3750;
		gotoxy(39, 13);
		cout << "The Withholding Vehicle Tax is:" << vehicle_tax << endl;
	}
	else if (temp->car_reg >= 1600 && temp->car_reg <= 1999)
	{
		vehicle_tax = 4500;
		gotoxy(39, 13);
		cout << "The Withholding Vehicle Tax is:" << vehicle_tax << endl;
	}
	else if (temp->car_reg >= 1600 && temp->car_reg <= 1999)
	{
		vehicle_tax = 10000;
		gotoxy(39, 13);
		cout << "The Withholding Vehicle Tax is:" << vehicle_tax << endl;
	}
	else if (temp->car_reg >= 2000)
	{
		vehicle_tax = 3750;
		gotoxy(39, 13);
		cout << "The Withholding Vehicle Tax is:" << vehicle_tax << endl;
	}
}
void p_tax(NodePtrF& headF)
{
	NodePtrF temp = headF;
	int hr;
	gotoxy(39, 11);
	cout << "Please enter your house registration number" << endl;
	gotoxy(57, 12);
	cin >> hr;
	while (temp != NULL)
	{
		if (temp->house_reg == hr)
		{
			break;
		}
		temp = temp->next;
	}
	float property_tax = 0;
	if (temp->house_s < 120)
	{
		property_tax = 0;
		gotoxy(39, 13);
		cout << "There is no property tax " << property_tax << endl;
	}
	else if (temp->house_s >= 120 && temp->house_s <= 200)
	{
		property_tax = 5000;
		gotoxy(39, 13);
		cout << "The Property Tax is:" << property_tax << endl;
	}
	else if (temp->house_s > 200 && temp->house_s <= 240)
	{
		property_tax = 10000;
		gotoxy(39, 13);
		cout << "The Property Tax is:" << property_tax << endl;
	}
	else if (temp->house_s > 240 && temp->house_s <= 400)
	{
		property_tax = 15000;
		gotoxy(39, 13);
		cout << "The Property Tax is:" << property_tax << endl;
	}
	else if (temp->house_s > 400 && temp->house_s <= 600)
	{
		property_tax = 25000;
		gotoxy(39, 13);
		cout << "The Property Tax is:" << property_tax << endl;
	}
	else if (temp->house_s > 600 && temp->house_s <= 1000)
	{
		property_tax = 40000;
		gotoxy(39, 13);
		cout << "The Property Tax is:" << property_tax << endl;
	}
}
void educfees(NodePtrF& headF)
{
	NodePtrF p = headF;
	int cni;
	double edutax, edu1 = 0, edu2 = 0, edu3 = 0, edu4 = 0;
	gotoxy(39, 11);
	cout << "Enter you CNIC: ";
	gotoxy(57, 12);
	cin >> cni;
	while (p != NULL)
	{
		if (p->cnic == cni)
		{
			if (p->flag == 1)
			{
				if (p->c1 >= 200000)
				{
					edu1 = 0.08 * (p->c1);
				}
				if (p->c2 >= 200000)
				{
					edu2 = 0.08 * (p->c2);
				}
				if (p->c2 >= 200000)
				{
					edu3 = 0.08 * (p->c3);
				}
				if (p->c4 >= 200000)
				{
					edu4 = 0.08 * (p->c4);
				}
				edutax = edu1 + edu2 + edu3 + edu4;
				gotoxy(39, 13);
				cout<<"Education Tax: " << edutax << endl;
			}
			else if (p->flag == 0)
			{
				if (p->c1 >= 200000)
				{
					edu1 = 0.1 * (p->c1);
				}
				if (p->c2 >= 200000)
				{
					edu2 = 0.1 * (p->c2);
				}
				if (p->c2 >= 200000)
				{
					edu3 = 0.1 * (p->c3);
				}
				if (p->c4 >= 200000)
				{
					edu4 = 0.1 * (p->c4);
				}
				edutax = edu1 + edu2 + edu3 + edu4;
				gotoxy(39, 13);
				cout<<"Education Tax: " << edutax << endl;
			}
		}
		p = p->next;
	}
}
void sleep(float seconds) {
	clock_t startClock = clock();
	double secondsAhead = seconds * CLOCKS_PER_SEC;
	while (clock() < startClock + secondsAhead);
	return;
}
void gotoxy(short x,short y) {
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x,y };
	SetConsoleCursorPosition(h, c);
}
void printfil() {
	fstream file;
	string word, filename;
	filename = "file.txt";
	file.open(filename.c_str());
	while (file >> word) {
		sleep(0.4);
		cout << word << "    ";
	}
}
void menu(NodePtrF& headF, NodePtrB& headB, NodePtr& head, int c) {
	int d;
	if (c == 1) {
		if (nadra_verify (head) == true) {
			system("cls");
			gotoxy(37, 1);
			printfil();
			gotoxy(39, 3);
			cout << "Your CNIC is NADRA verified. You may proceed now.";
			gotoxy(39, 4);
			sleep(0.07);
			cout << "Press 1 to calculate Income Tax ";
			gotoxy(39, 5);
			sleep(0.07);
			cout << "Press 2 to calculate Property Tax ";
			gotoxy(39, 6);
			sleep(0.07);
			cout << "Press 3 to calculate Vehicle Tax ";
			gotoxy(39, 7);
			sleep(0.07);
			cout << "Press 4 to calculate Education fee Tax ";
			gotoxy(39, 8);
			sleep(0.07);
			cout << "Press 0 to Exit ";
			gotoxy(57, 10);
			cin >> d;
			if (d == 1) {
				cal_tax(headF, headB,head);
				getch();
				menu(headF, headB, head, c);
			}
			else if (d == 2) {
				p_tax(headF);
				getch();
				menu(headF, headB, head, c);
			}
			else if (d == 3) {
				whdtax(headF);
				getch();
			 	menu(headF, headB, head, c);
			}
			else if (d == 4) {
				educfees(headF);
				getch();
				menu(headF, headB, head, c);
			}
			else if(d==0)
			{
			system("cls");
			gotoxy(47, 4);
			cout << "Bye :-) ";
			exit(0);
			}
			else 
			{
				gotoxy(50,11);
				cout<<"Invalid Input"<<endl;
				menu(headF, headB, head, c);
			}
		}
		else {
			gotoxy(40, 15);
			cout << "CNIC not found in NADRA database" << endl;
			gotoxy(40, 16);
			cout << "Taxes cannot be calculated on wrong CNIC" << endl;
			getch();
			system("cls");
			gotoxy(37, 1);
			printfil();
			cout<<endl<<endl;
			menu(headF,headB,head,c);
		}
	}
	else if (c == 2) 
	{
		if(login()==true)
		{
		int a;
		system("cls");
		gotoxy(37,1);
		printfil();
		gotoxy(45,3);
		cout<<"Successful Login ";
		gotoxy(37,5);
		cout << "Please enter your choice for viewing data record" << endl;
		gotoxy(37,6);
		cout << "1. Press 1 for viewing FBR data" << endl;
		gotoxy(37,7);
		cout << "2. Press 2 for viewing Bank's data" << endl;
		gotoxy(37,8);
		cout << "3. Press 3 for viewing Nadra's data" << endl;
		gotoxy(37,9);
		cout << "4. Press 4 to go back to Main Menu ";
		gotoxy(37,10);
		cout << "5. Press 5 to exit ";
		gotoxy(55,11);
		cin >> a;
		if (a == 1)
		{
			system("cls");
			printList(headF);
			menu(headF, headB, head, c);
		}
		else if (a == 2)
		{
			system("cls");
			printbank(headB);
			menu(headF, headB, head, c);
		}
		else if (a == 3)
		{
			system("cls");
			printnad(head);
			menu(headF, headB, head, c);
		}
		else if (a == 4)
		{
			system("cls");
			gotoxy(37, 1);
			printfil();
			mainmenu(headF, headB, head);
		}
		else if(a==5)
			{
				system("cls");
				gotoxy(47, 4);
				cout << "Bye :-) ";
				exit(0);
			}
		}
		else
		{
			cout<<"Sorry Password is wrong:"<<endl;
			system("cls");
			gotoxy(37, 5);
			printfil();
			mainmenu(headF, headB, head);
		}
	}
	else {
		system("cls");
		gotoxy(47, 4);
		cout << "Bye :-) ";
	}
}
void mainmenu(NodePtrF& headF, NodePtrB& headB, NodePtr& head) {
	int c;
	gotoxy(40, 7);
	cout << "Enter 1 to Proceed as Citizen :-) " << endl;
	gotoxy(40, 8);
	cout << "Enter 2 to Proceed as Admin :-) " << endl;
	gotoxy(40, 9);
	cout << "Enter any other number to Exit :-( ";
	gotoxy(57,10);
	cin >> c;
	
	menu(headF, headB, head, c);
	system("cls");
}
int main() 
{
	NodePtrF headF = NULL;
	NodePtrB headB = NULL;
	NodePtr head = NULL;
	addHeadFNode(headF);
	addHeadNode(head);
	addHeadBNode(headB);
	gotoxy(55, 1);
	system("Color E0");
	cout << "Hey!! " << endl;
	sleep(0.2);
	gotoxy(52, 3);
	cout << "Welcome to " << endl;
	gotoxy(37, 5);
	printfil();
	mainmenu(headF, headB, head);
}
