ROOT_PATH=$(shell pwd)
INCLUDE=-I$(ROOT_PATH)/../lib/include
LIB=-L$(ROOT_PATH)/../lib/lib
LDFLAGS=-ljsoncpp

json_comm::json_comm.cpp
	g++ -o $@ $^ $(INCLUDE) $(LIB) $(LDFLAGS) _D_DEBUG_
.PHONY:clean
clean:
	rm -rf json_comm
