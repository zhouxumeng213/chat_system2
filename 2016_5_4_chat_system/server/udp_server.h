#pragma once

#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<string>
#include<errno.h>
#include<stdio.h>
#include<map>
#include"data_poll.h"
using namespace std;
class server
{
	public:
		server(string &ip,short &port,int poll_cap);
		~server();
		void init_server();
		bool recv_data(string &out);
		void broadcast_data();
	private:
		bool send_data(string &data,struct sockaddr_in* client,socklen_t len);
	public:
		bool add_user(struct sockaddr_in &client);
		bool del_user(std::string &ip);
	private:
		string _ip;
		short _port;
		int _sock;
		data_poll _poll;
		std::map<std::string,struct sockaddr_in> _online_user;
};
