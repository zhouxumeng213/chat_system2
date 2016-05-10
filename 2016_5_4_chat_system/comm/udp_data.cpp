#include"udp_data.h"
udp_data::udp_data(){}
udp_data::~udp_data(){}
void udp_data::serialize(std::string &out)()//xuliehua
{
	Json::Value["nick_name"]=_nick_name;
	Json::Value["school"]=_school;
	Json::Value["msg"]=_msg;
	Json::Value["cmd"]=_cmd;
	json_comm _json;
	_json.set_val(_val);
	_json.val_to_str();
	_json.get_str(out);
}
void udp_data::deserialize(std::string &in)()//fanxuleihua
{
	Json::Value _val;
	json_comm _json;
	_json.set_str(in);
	_json.str_to_val();
	_json.get_val(_val);
	_nick_name=_val["nick_name"].asString();
	_school=_val["school"].asString();
	_msg=_val["msg"].asString();
	_cmd=_val["cmd"].asString();
}
#ifdef _DEBUG_
int main()
{
	std::string _out;
	udp_data _data;
	_data.set_nick_name("fly pig");
	_data.set_school("xatu");
	_data.set_msg("hello");
	_data.set_cmd("none");
	_data.serialize(_out);
	cout<<_out<<endl;

	_data.set_nick_name("A");
	_data.set_school("A");
	_data.set_msg("A");
	_data.set_cmd("A");
	_data.deserialize(_out);

	std::string tmp;
	_data.get_nick_name(tmp);
	_data.get_school(tmp);
	_data.ge_msg(tmp);
	_data.get_cmd(tmp);
}
#endif
