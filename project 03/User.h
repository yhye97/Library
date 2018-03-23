#pragma once
#include <string>
#include <vector>
using namespace std;

class User
{
public:
	User() {}
	~User() {}

	void setid(int ID) { id = ID; }
	void setpw(string pw) { password = pw; }
	void setname(string n) { name = n; }
	void setbid(int b) { borrowingList.push_back(b); }
	void empty() { borrowingList.clear(); }

	int getid() { return id; }
	string getpw() { return password; }
	string getname() { return name; }
	vector <int> getblist() { return borrowingList; }


private:
	int id;
	string password;
	string name;
	vector<int> borrowingList;
};

