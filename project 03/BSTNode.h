#pragma once
#include <string>
#include <vector>
#include "Book.h"
using namespace std;
class BSTNode
{

public:
	BSTNode() {}
	~BSTNode() {}

	BSTNode(Book* a)
	{
		key = a->getbname();
		left = NULL;
		right = NULL;
	}

	void insertbooks(Book* a)
	{
		key = a->getbname();
		books.push_back(a);
	}

	vector<Book*>getbooks() { return books; }

	BSTNode* getleft() { return left; }
	BSTNode* getright() { return right; }
	string getk() {
		return key;
	}

	void setl(BSTNode* l) { left = l; }
	void setr(BSTNode* r) { right = r; }
	void setkey(string k) { key = k; }
private:
	string key;
	BSTNode* left;
	BSTNode* right;
	vector<Book*> books;
};

