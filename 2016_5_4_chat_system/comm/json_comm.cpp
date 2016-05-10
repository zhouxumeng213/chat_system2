#include"json_comm.h"

json_comm::json_comm(){}
json_comm::~json_comm(){}

bool json_comm::val_to_str()//xuliehua
{
#ifdef _FAST_JSON_
	Json::FastWriter writer;//one line
#else
	Json::StyledWriter writer;//many lines
#endif
	_str=writer.write(_val);
	return true;
}
bool json_comm::str_to_val()//fanxuliehua
{
	Json::Reader read;
	if(read.parse(_str,_val,false)){
		return true;
	}else{
		return false;
	}
}
bool json_comm::set_val(const Json::Value &val)
{
	_val=val;
}
bool json_comm::get_str(std::string &out_str)
{
	out_str=_str;
}
bool json_comm::get_val(const Json::Value &val)
{
	_val=val;
}
bool json_comm::set_str(std::string &out_str)
{
	out_str=_str;
}
#ifdef _DEBUG_
int main()
{
	json_comm _json;
	std::string out_str;

	Json::Value root;
	root["nick_name"]="fly pig";
	root["school"]="xatu";
	root["msg"]="hello pig";
	root["cmd"]="none";//biao shi yong hu exit

	_json.set_val(root);
	_json.val_to_str();
	_json.get_str(out_str);
	cout<<out_str<<endl;
}
#endif
