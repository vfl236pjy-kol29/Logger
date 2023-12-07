#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<mutex>
#include<filesystem>
#include"logging.h"
using namespace std;


 
 Logger::Logger(const std::string& text, const std::string& from, const std::string& to): _text(text), _from(from), _to(to)
{
	 shared_mutex.lock();
	 Logger A(text, from, to);
	 int count = 0;//счЄтчик записей
	fstream record = fstream("logg_file.txt", ios::in | ios::out);
	if (!record)
		record = fstream("logg_file.txt", ios::in | ios::out | ios::trunc);
	if (record)
	{
		record.write((char*)&A, sizeof(Logger));
		count++;
	}
	record.close();
	shared_mutex.unlock();
}

 void Logger::show()
 {
	 shared_mutex.lock_shared();
	 string s;
	 ifstream read = ifstream("logg_file.txt");
	 if (read) {
			while (read)
				{
				getline(read, s);
					cout << s;
				}
			cout << endl;
			cout << s;
				}
	 read.close();
	 shared_mutex.unlock_shared();
 }

Logger::~ Logger()
	{
	delete  this;
	}

		

void Logger:: addMessage()
{
	string to, text, from;
	cout << "¬ведите им€ посылающего сообщениие" << from << endl;
	std::cin >> from;
	cout<<"¬ведите им€ получател€ сообщени€" <<to<< endl;
	std::cin >> to;
	cout << "¬ведите текст сообщени€" << endl;
	std::cin.ignore();
	std::getline(std::cin >> to, text);
}





