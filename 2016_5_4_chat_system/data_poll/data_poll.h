#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<semaphore.h>
class data_poll
{
	public:
		data_poll(int size);
		~data_poll();
		bool put_data(std::string &in);
		bool get_data(std::string &out);
	private:
		std::vector<std::string> _poll;
		int _cap;
		int _consumer_step;
		int _product_step;
		sem_t _consumer_sem;
		sem_t _product_sem;
};
