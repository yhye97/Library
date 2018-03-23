#pragma once
#include "Book.h"
#include <vector>
using namespace std;
class Bucket
{
public:
	Bucket() {}
	~Bucket() {}

	void setbooks(Book*b)
	{
		books.push_back(b);
	}

	vector<Book*> getbooks() { return books; }

private:
	vector<Book*> books;
};

