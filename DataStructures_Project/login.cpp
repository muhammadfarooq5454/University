#include<iostream>
#include<fstream>
#include<conio.h>
#include "login.h"
using namespace std;
bool login(){
	int a;
	getch();
	cout<<"\t\t\t\t\t\tEnter your pin:"<<endl;
	cout<<"\t\t\t\t\t\t\t";
	cin>>a;
	ifstream fin("Password.txt",ios::in);
	if(fin){
		int v;
		while(!fin.eof()){
			fin >> v;
		}
		if( v == a ){
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout << "File not open" << endl;
	}
	
	fin.close();
}

