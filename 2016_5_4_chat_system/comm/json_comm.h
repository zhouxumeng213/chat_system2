#pragma once
#include<iostream>
#include"json/json.h"
#include<string>
class json_comm
{
	public:
		json_comm();
		~json_comm();
		bool set_val();//xuliehua
		bool val_to_str();//xuliehua
		bool get_str();

		bool set_str();
		bool str_to_val();
		bool get_val();
	private:
		Json::Value _val;
		std::string _str;
};
