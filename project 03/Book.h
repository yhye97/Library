#pragma once
#include <string>
#include <iostream>
using namespace std;

class Book
{
public:
	Book()
	{
		id = 0;
		bookName = {};
		author = {};
		publishedYear = 0;
		isBorrowed = false;
		borrowerID = -1;
	}
	~Book() {}

	void printbook() {
		cout << "\t제목 : " << bookName << endl;
		cout << "\t작가 : " << author << endl;
		cout << "\t출판연도 : " << publishedYear << endl;
		cout << "\t 대출여부 : ";
		if (isBorrowed == 0)
		{
			cout << "X" << endl;
		}
		else
		{
			cout << "아이디 : " <<borrowerID << "님께서 대출중 " << endl;
		}
	}

	void setid(int ID) { id = ID; }
	void setbname(string bn) { bookName = bn; }
	void seta(string a) { author = a; }
	void setpyear(int pyear) { publishedYear = pyear; }
	void setib(bool ib) { isBorrowed = ib; }
	void setbid(int bid) { borrowerID = bid; }

	int getid() { return id; }
	string getbname() { return bookName; }
	string getauthor() { return author; }
	int getpyear() { return publishedYear; }
	bool getib() { return isBorrowed; }
	int getbid() { return borrowerID; }

private:
	int id;
	string bookName;
	string author;
	int publishedYear;
	bool isBorrowed;
	int borrowerID;
};

