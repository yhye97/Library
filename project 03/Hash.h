#pragma once
#include "WithIndex.h"
#include "Bucket.h"
class Hash :
	public WithIndex
{
public:
	Hash() {}
	~Hash() {}

	void buildIndex()
	{
		for (int i = 0; i < _bookList->size(); i++)
		{
			Bucket* b;
			b = new Bucket();
			hashTable.push_back(b);
		}

		
		for (int i = 0; i < _bookList->size(); i++)
		{
			int a;
			a = hashFunction((*_bookList)[i]->getbname());	
			hashTable[a]->setbooks((*_bookList)[i]);
	
		}
	}

	vector<Book*> search(string key)
	{
		int a;
		a = hashFunction(key);

		int size;
		size = hashTable[a]->getbooks().size();

		if (size == 0)
		{
			cout << "\t없는 책입니다" << endl;
		}
		
		vector <Book*> samename;
		for (int i = 0; i < size; i++)
		{
			if (hashTable[a]->getbooks()[i]->getbname() == key)
			{
				samename.push_back(hashTable[a]->getbooks()[i]);
			}
		}

		return samename;

	}
	void setbook(vector<Book*>* blist)
	{
		_bookList = blist;
	}

private:
	vector<Bucket*> hashTable;

	int hashFunction(string key)
	{
		int a = key.size();
		vector <int> arr;
		for (int i = 0; i < a; i++)
		{
			arr.push_back(key.at(i));
		}
		int total = 0;
		for (int i = 0; i < a; i++)
		{
			total += arr[i];
		}
		total = total%_bookList->size();
		return total;
	}

};

