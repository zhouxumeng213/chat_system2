#include"udp_server.h"
using namespace std;

server::server(string &ip,short &port,int poll_cap)
	:_ip(ip)
	 ,_port(port)
	 ,_sock(-1)
	 ,_poll(poll_cap)
{}
server::~server()
{
	if(_sock>-1){
		close(_sock);
	}
}
void server::init_server()
{
	_sock=socket(AF_INET,SOCK_DGRAM,0);
	if(_sock<0){
		//perror("socket");
		exit(1);
	}
	struct sockaddr_in local;
	local.sin_family=AF_INET;
	local.sin_port=htons(_port);
	local.sin_addr.s_addr=htonl(INADDR_ANY);
	if(bind(_sock,(struct sockaddr*)&local,sizeof(local))<0){
		//perror("bind");
		exit(2);
	}
}
bool server::recv_data(string &out)
{
	struct sockaddr_in client;
	socklen_t len=sizeof(client);
	char buf[1024];
	memset(buf,'\0',sizeof(buf));
	ssize_t _size=recvfrom(_sock,buf,sizeof(buf)-1,0,(struct sockaddr*)&client,&len);
	if(_size<0){
		//perror("recvfrom");
		return false;
	}else if(_size==0){
		//cout<<"client is close.."<<endl;
	}else{
		out=buf;
		_poll.put_data(out);
		cout<<out<<endl;
		add_user(client);
	}
	return true;
}
bool server::send_data(string &data,struct sockaddr_in* client,socklen_t len)
{
	ssize_t _size=sendto(_sock,data.c_str(),data.size(),0,(struct sockaddr*)client,len);
	if(_size<=0){
		//perror("sendto");
		return false;
	}else{
	}
	return true;
}
void server::broadcast_data()
{
	string data;
	_poll.get_data(data);
	std::map<std::string,struct sockaddr_in>::iterator _iter;
	for(_iter=_online_user.begin();_iter!=_online_user.end();_iter++){
		send_data(data,&(_iter->second),sizeof(_iter->second));
	}

}
bool server::add_user(struct sockaddr_in &client)
{
	string ip=inet_ntoa(client.sin_addr);
	std::map<std::string,struct sockaddr_in>::iterator _iter=_online_user.find(ip);
	if(_iter!=_online_user.end()){
		return false;
	}else{
		_online_user.insert(std::pair<std::string,struct sockaddr_in>(ip,client));
	}
	return true;

}
bool server::del_user(string &ip)
{
	return true;
}
void usage(string arg)
{
	cout<<arg<<"[ip] [port]"<<endl;
}
void* recv(void* arg)
{
	string recv_buf;
	server* recv_ser=(server*)arg;
	bool done=true;
	while(done){
		recv_ser->recv_data(recv_buf);
	}
}
void* broadcast(void* arg)
{
	server* broadcast_ser=(server*)arg;
	bool done=true;
	while(done){
		broadcast_ser->broadcast_data();
	}
}
int main(int argc,char* argv[])
{
	if(argc!=3){
		usage(argv[0]);
		return 1;
	}
	//daemon(0,0);
	string ip=argv[1];
	short port=atoi(argv[2]);
	server _ser(ip,port,64);
	_ser.init_server();

	pthread_t recv_pthread;
	pthread_t broadcast_pthread;
	pthread_create(&recv_pthread,NULL,recv,(void*)&_ser);
	pthread_create(&broadcast_pthread,NULL,broadcast,(void*)&_ser);

	pthread_join(recv_pthread,NULL);
	pthread_join(broadcast_pthread,NULL);
	//string out;
	//bool done=true;
	//while(done){
	//	_ser.recv_data(out);
	//	cout<<out<<endl;
	//}
	return 0;
}
