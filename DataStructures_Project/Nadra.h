#pragma once
#include <iostream>   //Nadra using SLL and filing
#include <fstream>
#include <string>
#include<stdlib.h>
using namespace std;

#ifndef NADRA_H
#define NADRA_H

class nadra
{
public:
	int cnic=0;
	string name, fname, DOB;
	nadra* next{};
};

typedef nadra* NodePtr;

inline NodePtr& addHeadNode(NodePtr& head);
inline bool nadra_verify(NodePtr& head);
inline void printnad(NodePtr& head);

#endif