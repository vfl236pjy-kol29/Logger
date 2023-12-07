#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<mutex>
#include<filesystem>
#include"logging.h"
#include<thread>
using namespace std;

int main()
{
	Logger B(" "," "," ");
	std::thread t1(B.addMessage()," "," "," ");
	std::thread t2(B.show());
	t1.join();
	t2.join();
	//или
	//B.addMessage();
	//B.show();
	return 0;
}