#include"udp_client.h"
using namespace std;
client::client(string &ip,short &port)
	:_ip(ip)
	 ,_port(port)
	 ,_sock(-1)
{
}
client::~client()
{
	if(_sock>-1){
		close(_sock);
	}
}
void client::init_client()
{
	_sock=socket(AF_INET,SOCK_DGRAM,0);
	if(_sock<0){
		//perror("socket");
		exit(1);
	}
}
bool client::recv_data(string &buf)
{
	struct sockaddr_in remote;
	socklen_t len=sizeof(remote);
	char data_buf[1024];
	memset(data_buf,'\0',sizeof(data_buf));
	ssize_t _size=recvfrom(_sock,data_buf,sizeof(data_buf)-1,0,(struct sockaddr*)&remote,&len);
	if(_size>0){
		data_buf[_size]='\0';
		buf=data_buf;
	}else if(_size==0){
	}else{
	}
	return true;
}
bool client::send_data(const string &data)
{
	struct sockaddr_in remote;
	remote.sin_family=AF_INET;
	remote.sin_port=htons(_port);
	remote.sin_addr.s_addr=inet_addr(_ip.c_str());
	socklen_t len=sizeof(remote);
	ssize_t _size=sendto(_sock,data.c_str(),data.size(),0,(struct sockaddr*)&remote,len);
	if(_size<0){
		//perror("sendto");
		return false;
	}else{}
	return true;
}
void usage(string arg)
{
	cout<<arg<<"[ip] [port]"<<endl;
}
int main(int argc,char* argv[])
{
	if(argc!=3){
		usage(argv[0]);
		return 1;
	}
	string out;
	string ip=argv[1];
	short port=atoi(argv[2]);
	client _cli(ip,port);
	_cli.init_client();
	char msg[1024];
	while(1){
		memset(msg,'\0',sizeof(msg));
		cout<<"please enter: ";
		fflush(stdout);
		gets(msg);
		
		_cli.send_data(msg);
		_cli.recv_data(out);
		cout<<"server: "<<out<<endl;
	}
}

