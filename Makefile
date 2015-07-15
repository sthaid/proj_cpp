TARGETS=cinout functions variables externc \
        class_overview class_abstract class_template

all: $(TARGETS)

cinout: cinout.cpp
	g++ -Wall -o cinout cinout.cpp

functions: functions.cpp
	g++ -Wall -o functions functions.cpp

variables: variables.cpp
	g++ -Wall -o variables variables.cpp

externc: externc.cpp
	g++ -std=gnu++11 -Wall -o externc externc.cpp

class_overview: class_overview.cpp
	g++ -std=gnu++11 -Wall -o class_overview class_overview.cpp

class_abstract: class_abstract.cpp
	g++ -std=gnu++11 -Wall -o class_abstract class_abstract.cpp

class_template: class_template.cpp
	g++ -std=gnu++11 -Wall -o class_template class_template.cpp




thread: thread.cpp
	g++ -Wall -std=gnu++11 -pthread -o thread thread.cpp

clean:
	rm -f $(TARGETS)
