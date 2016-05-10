#include"data_poll.h"
data_poll::data_poll(int size)
	:_cap(size)
	 ,_poll(size)
{
	_consumer_step=0;
	_product_step=0;
	sem_init(&_consumer_sem,0,0);
	sem_init(&_product_sem,0,size);
}
data_poll::~data_poll()
{
	sem_destroy(&_consumer_sem);
	sem_destroy(&_product_sem);
}
bool data_poll::put_data(std::string &in)
{
	sem_wait(&_product_sem);
	_poll[_product_step]=in;
	_product_step++;
	_product_step%=_cap;
	sem_post(&_consumer_sem);
}
bool data_poll::get_data(std::string &out)
{
	sem_wait(&_consumer_sem);
	out=_poll[_consumer_step];
	_consumer_step++;
	_consumer_step%=_cap;
	sem_post(&_product_sem);
}
