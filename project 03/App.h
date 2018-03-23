#pragma once
#include "BST.h"
#include "Hash.h"
#include "BinarySearch.h"
#include "BinaryReader.h"
#include "TextReader.h"
#include <fstream>
#include <algorithm>
//#include <functional>
#include <vector>
#include <iostream>
using namespace std;

class App
{
public:
	App();
	~App();
	void run();
	void userrun();

private:
	void login();
	void readFile(bool isBinary);
	void writeFile(bool isBinary);
	void searchBook();
	void borrowBook();
	void returnBook();
	void buildIndex();

	FileReader* fr;
	SearchAlgorithm* sa;
	User*curUser;
	int checkni;//no index �������
 
	vector<User*> userList;
	vector<Book*> bookList;
	vector <Book*>fresult; // �˻� �� å ����, ���ڸ�, ���ǿ��� ��ġ�ϴ� ����Ʈ
};

