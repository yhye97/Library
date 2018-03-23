#pragma once
#include "User.h"
#include "Book.h"

class SearchAlgorithm
{
public:
	SearchAlgorithm() {}
	~SearchAlgorithm() {}

	virtual vector<Book*> search(string key) = 0;

protected:
	vector<Book*>* _bookList;
};

