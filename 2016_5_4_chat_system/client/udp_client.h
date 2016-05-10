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
#include<stdio.h>
//#include"udp_data.h"
class client
{
	public:
		client(std::string &ip,short &port);
		~client();
		void init_client();
		bool recv_data(std::string &buf);
		bool send_data(const std::string &data);
	private:
		std::string _ip;
		short _port;
		int _sock;
};
