ROOT_PATH=$(shell pwd)
SERVER=udp_serverd
CLIENT=udp_client
CC=g++

INCLUDE=-I$(ROOT_PATH)/data_poll
LDFLAGS=-lpthread
#LIB=-L$()/lib/lib


SERVER_PATH=$(ROOT_PATH)/server
CLIENT_PATH=$(ROOT_PATH)/client
DATA_POLL_PATH=$(ROOT_PATH)/data_poll

#COMM_PATH=$(ROOT_PATH)/comm

SERVER_SRC=$(shell ls $(SERVER_PATH) | egrep '*.cpp')
SERVER_SRC+=$(shell ls $(DATA_POLL_PATH) | egrep '*.cpp')
CLIENT_SRC=$(shell ls $(CLIENT_PATH) | egrep '*.cpp')
#CLIENT_SRC+=$()

SERVER_OBJ=$(SERVER_SRC:.cpp=.o)
CLIENT_OBJ=$(CLIENT_SRC:.cpp=.o)

.PHONY:all
all:$(SERVER) $(CLIENT)
$(SERVER):$(SERVER_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
#	@echo "Link [ $^ ] to [ $@ ]...done"
$(CLIENT):$(CLIENT_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
%.o:$(SERVER_PATH)/%.cpp
	$(CC) -c $< $(INCLUDE)
%.o:$(CLIENT_PATH)/%.cpp
	$(CC) -c $< $(INCLUDE)
%.o:$(DATA_POLL_PATH)/%.cpp
	$(CC) -c $< $(INCLUDE)
#%.o:$(COMM_PATH)/%.cpp
#	@echo "Compling [ $< ] to [ $@ ]...done"
#	@$(CC) -c $<
.PHONY:clean
clean:
	rm -rf *.o $(SERVER) $(CLIENT) 
.PHONY:debug
debug:
	@echo $(SERVER_SRC)
	@echo $(SERVER_OBJ)
	@echo $(CLIENT_SRC)
	@echo $(CLIENT_OBJ)











