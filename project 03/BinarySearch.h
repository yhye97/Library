#pragma once
#include "NoIndex.h"
#include <algorithm>
#include <functional>
using namespace std;

struct less_than_key
{
	bool operator() (Book* b1, Book* b2)
	{
		return(b1->getbname() < b2->getbname());
	}

};

struct less_than_id
{
	bool operator() (Book*b1, Book*b2)
	{
		return (b1->getid() < b2->getid());
	}
};


class BinarySearch :public NoIndex
{
public:
	BinarySearch() {}
	~BinarySearch() {}


	BinarySearch(vector<Book*>* bookList)
	{

		_bookList = bookList;
		sort((*_bookList).begin(), (*_bookList).end(), less_than_key());

	}

void sortbyid(vector<Book*>*bookList)
	{
		_bookList = bookList;
		sort((*_bookList).begin(), (*_bookList).end(), less_than_id());

	}
	vector <Book*>* sortbyname(vector<Book*>*bookList)
	{
		_bookList = bookList;
		sort((*_bookList).begin(), (*_bookList).end(), less_than_key());
		return _bookList;
	}

	vector<Book*> search(string key)
	{
		int left = 0;
		int right = _bookList->size() - 1;
		int mid;
		
		vector<Book*> findbooks;
		
		findbooks.clear();

		while (left <= right)
		{
			mid = left + (right - left) / 2;
			
			if ((*_bookList)[mid]->getbname() == key)
			{
				findbooks.push_back((*_bookList)[mid]);
				for (int i = mid - 1; i >= 0; i--)
				{
					if ((*_bookList)[i]->getbname() == key)
					{
						findbooks.push_back((*_bookList)[i]);
					}
					else
					{
						break;
					}
				}
			
				for (int i = mid + 1; i < _bookList->size(); i++)
				{
					if ((*_bookList)[i]->getbname() == key)
					{
						findbooks.push_back((*_bookList)[i]);
					}
					else
					{
						break;
					}
				}
				return findbooks;
			}

			else if ((*_bookList)[mid]->getbname() < key) { left = mid + 1; }
			else if ((*_bookList)[mid]->getbname() > key) { right = mid - 1; }

		}

		return findbooks;
	}
};

