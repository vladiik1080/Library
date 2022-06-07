#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Human
{
public:
	Human()
	{

	}
	Human(int number_h, string name_h)
		:m_number_h(number_h),m_name_h(name_h)
	{

	}
	void setHuman(int number_h, string name_h)
	{
		m_number_h = number_h;
		m_name_h = name_h;
	}
	void getHuman() const
	{
		cout << "Number reader is: " << m_number_h << " , name reader is: " << m_name_h << endl;
	}
private:
	int m_number_h;
	string m_name_h;
};

class Book//:public Human
{
public:
	Book()
	{

	}
	Book(int number_b, string name_b)
		:m_number_b(number_b),m_name_b(name_b)
	{

	}
	void setBook(int number_b, string name_b)
	{
		m_number_b = number_b;
		m_name_b = name_b;
	}
	void getBook() const
	{
		cout << "Number book is : " << m_number_b << ", name book is : " << m_name_b << endl;
	}
private:
	int m_number_b;
	string m_name_b;
};

class Librery //:public Book
{
public:
	Librery()
	{

	}
	void setL_B(Book& book)
	{
		m_book.push_back(book);
	}
	void getL_B() const
	{
		for (int i = 0; i < m_book.size(); i++)
		{
			m_book[i].getBook();
		}
	}
	void setL_H(Human& human)
	{
		m_human.push_back(human);
	}
	void getL_H() const
	{
		for (int i = 0; i < m_human.size(); i++)
		{
			m_human[i].getHuman();
		}
	}
	vector <Book> m_book;
	vector <Human> m_human;
	vector <Librery> m_lib;
};

void Go(Librery&librery)
{
	char index = 'y';
	while (index != 'n')
	{
		Book book;
		int number_b;
		string name_b;
		cin >> number_b >> name_b;
		book.setBook(number_b, name_b);
		librery.setL_B(book);
		cout << "Entry 'n' if wont to stop: ";
		cin >> index;
	}
	librery.getL_B();
}

int main()
{
	Librery librery;
	Go(librery);
	return 0;
}
