#pragma once
#include<iostream>
#include<string>
#include"json/json.h"
#include"json_comm.h"

class udp_data{
	public:
		udp_data();
		~udp_data();

		void set_nick_name(const std::string &s){_nick_name=s;}
		void set_school(const std::string &s){_school=s};
		void set_msg(const std::string &s){_msg=s};
		void set_cmd(const std::string &s){_cmd=s};
		void serialize(std::string &out);//xuliehua

		void deserialize(std::string &in);//fanxuleihua
		void get_nick_name(std::string &out){out=_nick_name;}
		void get_school(std::string &out){out=_school};
		void get_msg(std::string &out){out=_msg};
		void get_cmd(std::string &out){out=_cmd};


	private:
		std::string _nick_name;
		std::string _school;
		std::string _msg;
		std::string _cmd;
};
