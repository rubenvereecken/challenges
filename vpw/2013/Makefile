CXXFLAGS =	-O2 -static -g3 -Wall -fmessage-length=0 -std=gnu++0x -lm

OBJS =		lockers.o

LIBS =

TARGET =	vpw2013

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
