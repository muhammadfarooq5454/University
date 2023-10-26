#pragma once
#ifndef BANKDATA_H
#define BANKDATA_H
#include<iostream>
#include <fstream>
#include <string>
using namespace std;

class bank
{
public:
	string nameofbank;
	float sal_inc{};
	int cnic{}, accountnumber{}, branchnumber{};
	bank* next{};
};
typedef bank* NodePtrB;
inline NodePtrB& addHeadBNode(NodePtrB& headB);
inline void printbank(NodePtrB& headB);
#endif  