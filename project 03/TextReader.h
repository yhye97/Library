#pragma once
#include "FileReader.h"
class TextReader :
	public FileReader
{
public:
	TextReader() {}
	~TextReader() {}

	void readUserFile(vector<User*>* _userList)
	{
		ifstream ifs("user.txt");
		int userId, bid, bnum;
		string pw, username, record;

		while (getline(ifs, record))
		{
			User* user;
			user = new User();
			stringstream ifs(record);
			ifs >> userId >> pw >> username >> bnum;
			user->setid(userId);
			user->setpw(pw);
			user->setname(username);

			for (int i = 0; i<bnum; i++)
			{
				ifs >> bid;
				user->setbid(bid);
			}

			_userList->push_back(user);

		}
		ifs.close();
	}
	void readBookFile(vector<Book*>* _bookList)
	{
		ifstream ifs("book.txt");
		int id, borrowed, bid, pyear;
		string bname, author, record;

		while (getline(ifs, record))
		{
			Book *b;
			b = new Book();
			stringstream ifs(record);
			ifs >> id >> bname >> author >> pyear >> borrowed;
			b->setid(id);
			b->setbname(bname);
			b->seta(author);
			b->setpyear(pyear);
			b->setib(borrowed);

			for (int i = 0; i < borrowed; i++)
			{
				ifs >> bid;
				b->setbid(bid);
			}

			_bookList->push_back(b);
		}
		ifs.close();
	}
};

