TARGETS=cinout functions variables externc

all: $(TARGETS)

cinout: cinout.cpp
	g++ -Wall -o cinout cinout.cpp

functions: functions.cpp
	g++ -Wall -o functions functions.cpp

variables: variables.cpp
	g++ -Wall -o variables variables.cpp

externc: externc.cpp
	g++ -std=gnu++11 -Wall -o externc externc.cpp




thread: thread.cpp
	g++ -Wall -std=gnu++11 -pthread -o thread thread.cpp

clean:
	rm $(TARGETS)
