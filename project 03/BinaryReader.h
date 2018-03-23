#pragma once
#include "FileReader.h"
#include <fstream>
#include <string>
using namespace std;

class BinaryReader :
	public FileReader
{
public:
	BinaryReader() {}
	~BinaryReader() {}

	void readUserFile(vector<User*>* _userList)
	{
		ifstream fsIn("userbinary.dat", ios::binary | ios::in);
		int userId, usize, psize, nsize, bid;
		string pw, username, record;
		int bnum;
		int check;
		check = 0;
		while (!fsIn.eof())
		{
			
			fsIn.read((char*)&userId, sizeof(int));
			if ((*_userList).size() != 0)
			{
				int usize = (*_userList).size();
					if (userId == (*_userList)[usize-1]->getid())
					{
					check++;
						break;
					}
				
				if (check != 0)
				{
					break;
				}
			}

			User* user;
			user = new User();
			user->setid(userId);

			fsIn.read((char*)&psize, sizeof(int));
			pw.resize(psize);
			fsIn.read(&pw[0], psize);
			user->setpw(pw);

			fsIn.read((char*)&nsize, sizeof(int));
			username.resize(nsize);
			fsIn.read(&username[0], nsize);
			user->setname(username);

			fsIn.read((char*)&bnum, sizeof(int));
			
			for (int i = 0; i < bnum; i++)
			{
				fsIn.read((char*)&bid, sizeof(int));
				user->setbid(bid);
			}

			_userList->push_back(user);
		}


	}
	void readBookFile(vector<Book*>* _bookList)
	{

		ifstream fsIn("BookBinary.dat", ios::binary | ios::in);
		int id, bsize, asize, pyear, bid;
		string pw, bname, aname;
		bool borrowed;
	
		while (!fsIn.eof())
		{
			Book* b;
			b = new Book();

			fsIn.read((char*)&id, sizeof(int));
			if ((*_bookList).size() != 0)
			{
				int booklistsize = (*_bookList).size();
				
				if (id == (*_bookList)[booklistsize-1]->getid())
				{
					
					break;
				}
				
			}


			b->setid(id);

			fsIn.read((char*)&bsize, sizeof(int));
			bname.resize(bsize);
			fsIn.read(&bname[0], bsize);
			b->setbname(bname);

			fsIn.read((char*)&asize, sizeof(int));
			aname.resize(asize);
			fsIn.read(&aname[0], asize);
			b->seta(aname);

			fsIn.read((char*)&pyear, sizeof(int));
			b->setpyear(pyear);

			fsIn.read((char*)&borrowed, sizeof(bool));
			b->setib(borrowed);

			
			fsIn.read((char*)&bid, sizeof(int));
			b->setbid(bid);

			_bookList->push_back(b);
			

		}
	}
};

