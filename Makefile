TARGETS=cinout

all: $(TARGETS)

cinout: cinout.cpp
	g++ -Wall -o cinout cinout.cpp





thread: thread.cpp
	g++ -Wall -std=gnu++11 -pthread -o thread thread.cpp

clean:
	rm $(TARGETS)
