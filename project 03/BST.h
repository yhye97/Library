#pragma once
#include "WithIndex.h"
#include "BSTNode.h"
#include <iostream>
using namespace std;
class BST :
	public WithIndex
{
public:
	BST() {
		root = new BSTNode();
		root = NULL;
	}
	~BST() {}

	void buildIndex()
	{
		for (int i = 0; i < _bookList->size(); i++)
		{
			insert((*_bookList)[i], root);
		}

		
	}

	vector<Book*> search(string key)
	{
		if (root == NULL)
		{
			return root->getbooks();
		}
		// Key is greater than root's key
		if (root->getk() < key)
		{
			root = root->getright();
		}
		else if (root->getk() == key)
		{
			return root->getbooks();
		}
		// Key is smaller than root's key
		else
		{
			root = root->getleft();
		}

		return search(key);
	}

	void insert(Book* item, BSTNode* r)
	{
		if (r == NULL)
		{
			r = new BSTNode(item);
			r->insertbooks(item);
		}
		else
		{
			if (item->getbname() < r->getk())
			{
				if (r->getleft() == NULL)
				{
					BSTNode* temp = new BSTNode(item);
					r->setl(temp);
					(r->getleft())->insertbooks(item);
				}
				else
				{		
					insert(item, r->getleft());
				}
			}
			else if (item->getbname() > r->getk())
			{
				if (r->getright() == NULL)
				{
					BSTNode*temp = new BSTNode(item);
					r->setr(temp);
					(r->getright())->insertbooks(item);
				}
				else
				{
					insert(item, r->getright());
				}
				
			}
			else
			{
				r->insertbooks(item);
			}
		}
		root = r;
	}


	void setbook(vector<Book*>* blist)
	{
		_bookList = blist;
	}

private:
	BSTNode* root;
};