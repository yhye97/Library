#include "App.h"

App::App()
{
	checkni = 0;
	curUser = new User();
	sa = NULL;
	fr = NULL;
	cout << endl << endl;
	cout << "\t���� �б� ��� : " << endl;
	cout << "\t--------------------------" << endl;
	cout << "\t1. Binary" << endl;
	cout << "\t2. Text" << endl;
	cout << "\t--------------------------" << endl;
	cout << "\t=>";
	int num;
	cin >> num;
	if (num == 1)
	{
		readFile(true);
	}
	else
	{
		readFile(false);
	}
}

App::~App()
{
	writeFile(true);
	writeFile(false);
}

void App::run()
{
	while (1)
	{
		string command;
		cout << endl << endl;
		cout << "\t ������" << endl;
		cout << "\t----------------- " << endl;
		cout << "\t   1 :�α���" << endl;
		cout << "\t   2 : �α׾ƿ�" << endl;
		cout << "\t   3 : ����" << endl;
		cout << "\t----------------- " << endl;
		cout << endl << "\t -> ";
		cin >> command;
		if (command == "1")
		{
			login();
		}
		else if (command == "2")
		{
			curUser = NULL;
			run();
		}
		else if (command == "3")
		{
			writeFile(true);
			writeFile(false);
			exit(100);
		}
		else
		{
			cout << "\t���� �׸��Դϴ�\n";
			run();
		}
	}
}

void App::userrun()
{

	while (1)
	{
		system("pause");
		system("cls");
		cout << endl << endl;
		cout << "\t" << curUser->getname() << "��" << endl;
		cout << "\t--------------------------" << endl;
		cout << "\t1. ���� �˻� �� �뿩" << endl;
		cout << "\t2. ���� �ݳ�" << endl;
		cout << "\t3. ���� �˻����" << endl;
		cout << "\t4. �ڷΰ���" << endl;
		cout << "\t--------------------------" << endl;
		int num;
		cout << "\t=>";
		cin >> num;

		if (num == 1)
		{
			searchBook();
		}
		else if (num == 2)
		{
			returnBook();
		}
		else if (num == 3)
		{
			buildIndex();
		}
		else if (num == 4)
		{
			run();
		}
		else
		{
			cout << "�ٽ� �Է��Ͻÿ�" << endl;
		}
	}

}

void App::login()
{
	system("pause");
	system("cls");
	cout << endl << endl;
	cout << "\t�α���" << endl;
	cout << "\t--------------------------" << endl;
	int id; string pw;
	cout << "\t ID : ";
	cin >> id;
	cout << "\t PW : ";
	cin >> pw;
	cout << "\t--------------------------" << endl;

	for (int i = 0; i < userList.size(); i++)
	{
		if (id == userList[i]->getid())
		{
			if (pw == userList[i]->getpw())
			{
				curUser = userList[i];
				
				userrun();
			}
			else
			{
				cout << "\t��й�ȣ�� �߸� �Է��ϼ̽��ϴ�" << endl;
				run();
			}
		}
	}


}

void App::readFile(bool isBinary)
{
	if (isBinary == true) {
		fr = new BinaryReader();
		fr->readUserFile(&userList);
		fr->readBookFile(&bookList);
	}
	else
	{
		fr = new TextReader();
		fr->readUserFile(&userList);
		fr->readBookFile(&bookList);
	}


}

void App::writeFile(bool isBinary)
{
	if (isBinary == true)
	{
		fstream o_users, o_books;
		o_users.open("userbinary.dat", ios::in | ios::out | ios::binary | ios::trunc);

		for (int i = 0; i < userList.size(); i++)
		{
			int id = userList[i]->getid();
			string pw = userList[i]->getpw();
			int psize = pw.size();
			string name = userList[i]->getname();
			int nsize = name.size();
			int bsize = userList[i]->getblist().size();

			o_users.write((char*)&id, sizeof(int));
			o_users.write((char*)&psize, sizeof(int));
			o_users.write(&pw[0], pw.size());
			o_users.write((char*)&nsize, sizeof(int));
			o_users.write(&name[0], name.size());
			o_users.write((char*)&bsize, sizeof(int));
		
			for (int j = 0; j < bsize; j++)
			{
				int b2 = userList[i]->getblist()[j];
				o_users.write((char*)&b2, sizeof(int));
			}
		}
		o_users.close();

		o_books.open("BookBinary.dat", ios::in | ios::out | ios::binary | ios::ate);
		o_books.seekp(0, ios::beg);
		
		if (checkni == 1)
		{
			BinarySearch*a;
			a = new BinarySearch();
			a->sortbyid(&bookList);
			
			for (int i = 0; i < bookList.size(); i++)
			{
				bool b = bookList[i]->getib();
				int b2 = bookList[i]->getbid();
				int nsize = bookList[i]->getbname().size();
				int asize = bookList[i]->getauthor().size();
				o_books.seekp(sizeof(int) * 2 + nsize + sizeof(int) + asize + sizeof(int), ios::cur);
				o_books.write((char*)&b, sizeof(bool));
				o_books.write((char*)&b2, sizeof(int));
			}

		}
		else
		{
			for (int i = 0; i < bookList.size(); i++)
			{
				bool b = bookList[i]->getib();
				int nsize = bookList[i]->getbname().size();
				int asize = bookList[i]->getauthor().size();
				int b2 = bookList[i]->getbid();
				o_books.seekp(sizeof(int) * 2 + nsize + sizeof(int) + asize + sizeof(int), ios::cur);
				o_books.write((char*)&b, sizeof(bool));
				o_books.write((char*)&b2, sizeof(int));
			}
		}
		o_books.close();

	}

	else
	{
		ofstream users, books;
		users.open("user.txt");
		books.open("book.txt");

		for (int i = 0; i < userList.size(); i++)
		{
			users << userList[i]->getid() << " " << userList[i]->getpw() << " " << userList[i]->getname() << " " << userList[i]->getblist().size();

			for (int j = 0; j < userList[i]->getblist().size(); j++)
			{
				users << " " << userList[i]->getblist()[j];
			}
			users << endl;
		}

		users.close();

		if (checkni == 1)
		{
			BinarySearch* temp;
			temp = new BinarySearch(&bookList);
			(temp->sortbyid(&bookList));

			for (int i = 0; i < bookList.size(); i++)
			{
				books << (bookList)[i]->getid() << " " << bookList[i]->getbname() << " " << bookList[i]->getauthor() << " " << bookList[i]->getpyear() << " " << bookList[i]->getib();
				if (bookList[i]->getib() == false)
				{
					books << endl;
				}
				else
				{
					books << " " << bookList[i]->getbid() << endl;
				}
			}
		}

		else
		{
			for (int i = 0; i < bookList.size(); i++)
			{
				books << bookList[i]->getid() << " " << bookList[i]->getbname() << " " << bookList[i]->getauthor() << " " << bookList[i]->getpyear() << " " << bookList[i]->getib();
				if (bookList[i]->getib() == false)
				{
					books << endl;
				}
				else
				{
					books << " " << bookList[i]->getbid() << endl;
				}
			}

		}

		books.close();
	}

}

void App::searchBook()
{
	cout << endl << endl;
	cout << "\t���� �˻�" << endl;
	cout << "\t--------------------------" << endl;
	cout << "\t ���� �̸� : ";
	string a;
	cin >> a;

	int c;
	c = (sa->search(a)).size(); // �˻� ��� å ����Ʈ ������

	if (c == 0)
	{
		cout << endl;
		cout << "\t���� �����Դϴ�" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < c; i++)
		{
			cout << i + 1 << ". ";
			sa->search(a)[i]->printbook();
		}

		vector <Book*> result1; //�̸����� ���� ����Ʈ
		cout << "\t--------------------------" << endl;
		cout << "\t���� �� : ";
		for (int i = 0; i < c; i++)
		{
			result1.push_back(sa->search(a)[i]);
		}
		string aname;
		cin >> aname;
		vector <Book*> result2; // ���ڸ���� ���� ����Ʈ
		for (int i = 0; i < result1.size(); i++)
		{
			if (result1[i]->getauthor() == aname)
			{
				result2.push_back(result1[i]);
			}
		}

		for (int i = 0; i < result2.size(); i++)
		{
			cout << i + 1 << ". ";
			result2[i]->printbook();
		}

		cout << "\t--------------------------" << endl;
		cout << "\t���ǿ��� : ";
		int year;
		cin >> year;

		fresult.clear();

		for (int i = 0; i < result2.size(); i++)
		{
			if (result2[i]->getpyear() == year)
			{
				fresult.push_back(result2[i]);
			}

		}

		borrowBook();

	}

}

void App::borrowBook()
{
	cout << endl << endl;
	cout << "\t--------------------------" << endl;
	for (int i = 0; i < fresult.size(); i++)
	{
		cout << i + 1 << ". ";
		fresult[i]->printbook();
	}
	cout << "\t--------------------------" << endl;
	cout << "\t=>";
	int n3;
	cin >> n3;
	cout << endl << endl;
	cout << "\t�뿩���� : " << endl;
	cout << "\t--------------------------" << endl;
	cout << "\t1. ��" << endl;
	cout << "\t2. �ƴϿ� " << endl;
	cout << "\t--------------------------" << endl;
	cout << "\t=>";
	int n2; int q;
	cin >> n2;
	if (n2 == 1)
	{
		for (int i = 0; i < bookList.size(); i++)
		{
			if (fresult[n3 - 1]->getid() == bookList[i]->getid())
			{
				q = i;
				break;
			}
		}

		if (fresult[n3 - 1]->getib() == false)
		{
			bookList[q]->setib(true);
			bookList[q]->setbid(curUser->getid());
			
			curUser->setbid(bookList[q]->getid());

			for (int i = 0; i < userList.size(); i++)
			{
				if (curUser == userList[i])
				{
					userList[i]->getblist().clear();
					for (int m = 0; m < curUser->getblist().size(); m++)
					{
						userList[i]->getblist().push_back(curUser->getblist()[m]);
					}
					
				}
					
			}

			cout << "\t���� ����!" << endl;
		}
		else
		{
			cout << "\t���� å�� �������̿��� �뿩 �Ұ��մϴ�" << endl;

		}
	}
	userrun();
}

void App::returnBook()
{
	cout << endl << endl;
	cout << "\t���� �ݳ�" << endl;
	cout << "\t--------------------------" << endl;
	

	if (curUser->getblist().size() == 0)
	{
		cout << "\t�����Ͻ� ������ �����ϴ�" << endl;
		userrun();
	}

	else
	{
		
		for (int j = 0; j < bookList.size(); j++)
		{
			for (int i = 0; i < curUser->getblist().size(); i++)
			{
				if (curUser->getblist()[i] == bookList[j]->getid())
				{
					cout << i + 1 << " . ";
					bookList[j]->printbook();
				}
			}
		}

		int num;
		cout << "\t=>";
		cin >> num;		

		for (int m = 0; m < bookList.size(); m++)
		{
			if (bookList[m]->getid() == curUser->getblist()[num - 1])
			{
				bookList[m]->setib(false);
				bookList[m]->setbid(-1);
			}

		}
		if (num - 1 == 0)
		{		
			curUser->empty();
		}
		else
		{
			for (int k = num - 1; k < curUser->getblist().size() - 1; k++)
			{
				curUser->getblist()[k] = curUser->getblist()[k + 1];
			}

			curUser->getblist().pop_back();
		}
		cout << "\t�ݳ� �Ǽ̽��ϴ�" << endl;
		
	}
	
}
void App::buildIndex()
{
	cout << endl << endl;
	cout << "\t�˻� ��� : " << endl;
	cout << "\t--------------------------" << endl;
	cout << "\t1. No Index" << endl;
	cout << "\t2. BST" << endl;
	cout << "\t3. Hash" << endl;
	cout << "\t--------------------------" << endl;
	cout << "\t=>";
	int command;
	cin >> command;

	if (command == 1)
	{
		sa = new BinarySearch(&bookList);
		BinarySearch * temp;
		temp = new BinarySearch();
		temp = (BinarySearch*)sa;
		checkni = 1;
	}
	else if (command == 2)
	{
		sa = new BST();
		BST* temp;
		temp = new BST();
		temp = (BST*)sa;
		temp->setbook(&bookList);
		temp->buildIndex();

	}
	else if (command == 3)
	{
		sa = new Hash();
		Hash* temp;
		temp = new Hash();
		temp = (Hash*)sa;
		temp->setbook(&bookList);
		temp->buildIndex();
		
	}

}
