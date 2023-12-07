#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<mutex>
#include<filesystem>
#include<shared_mutex>


class Logger
{
		public:
			Logger(const std::string& text, const std::string& from, const std::string& to);
			~Logger();
			//int& count;

			void show();
			void addMessage();

			std::string getaddMessage() const { return _text; }
			std::string getaddMessage() const { return _to; }
			std::string getaddMessage() const { return _from; }
		private:
			std::shared_mutex shared_mutex;
			std::string _from;
			std::string _to;
			std::string _text ;
};

