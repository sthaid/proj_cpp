TARGETS=cinout functions variables externc classes1

all: $(TARGETS)

cinout: cinout.cpp
	g++ -Wall -o cinout cinout.cpp

functions: functions.cpp
	g++ -Wall -o functions functions.cpp

variables: variables.cpp
	g++ -Wall -o variables variables.cpp

externc: externc.cpp
	g++ -std=gnu++11 -Wall -o externc externc.cpp

classes1: classes1.cpp
	g++ -std=gnu++11 -Wall -o classes1 classes1.cpp




thread: thread.cpp
	g++ -Wall -std=gnu++11 -pthread -o thread thread.cpp

clean:
	rm $(TARGETS)
