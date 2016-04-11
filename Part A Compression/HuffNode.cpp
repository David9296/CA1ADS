#include "HuffNode.h"
using namespace std;

HuffNode::HuffNode() //Default
	:data(' '), freq(0), left(nullptr), right(nullptr)
{}

HuffNode::HuffNode(char d, int f)  // Constructor to assign data and freq 
	:data(d), freq(f), left(nullptr), right(nullptr)
{}

HuffNode::HuffNode(HuffNode * n)  //Assign letter and freq to pointer and variables
{
	data = n->data;
	freq = n->freq;

	if (n->left != nullptr) {
		left = n->left;
	}
	if (n->right != nullptr) {
		right = n->right;
	}
}

HuffNode::HuffNode(HuffNode * l, HuffNode * r) // Assign pointers and frequencies 
{
	data = ' ';
	left = l;
	right = r;
	freq = l->freq + r->freq;
}

char HuffNode::getData()   // Just getters that will be used
{
	return data;
}

int HuffNode::getFreq() 
{
	return freq;
}

HuffNode * HuffNode::getLeft()
{
	return left;
}

HuffNode * HuffNode::getRight()
{
	return right;
}

bool HuffCompare::operator()(HuffNode * n1, HuffNode * n2)
{
	return (n1->getFreq() > n2->getFreq());
}
