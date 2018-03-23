#pragma once
#include <vector>
#include "Book.h"
#include "User.h"
#include <fstream>
#include <sstream>
using namespace std;

class FileReader
{
public:
	FileReader() {}
	~FileReader() {}

	virtual void readUserFile(vector<User*>* _userList) = 0;
	virtual void readBookFile(vector<Book*>* _bookList) = 0;
};

