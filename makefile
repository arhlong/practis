CC      = gcc
CXX     = g++
CFLAGS  = -Wall -g
TARGET  = adapter 
SRCDIR  = .
SOURCES = $(wildcard $(SRCDIR)/*.c $(SRCDIR)/*.cpp $(SRCDIR)/*.s)
OBJS    = $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCES)))
LDFLAG  = -lthrift -lpthread -ljson -lcrypto 
INCLUDE = -I. -I../include
EXTLIBS = -L../lib 

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

%.o:%.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAG) $(EXTLIBS) $(INCLUDE)

clean:
	rm -f *.o $(TARGET)
