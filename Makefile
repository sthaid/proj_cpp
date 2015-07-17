TARGETS=cinout functions variables externc thread \
        class_overview class_abstract class_template \
        namespace_test

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

class_overview: class_overview.cpp
	g++ -std=gnu++11 -Wall -o class_overview class_overview.cpp

class_abstract: class_abstract.cpp
	g++ -std=gnu++11 -Wall -o class_abstract class_abstract.cpp

class_template: class_template.cpp
	g++ -std=gnu++11 -Wall -o class_template class_template.cpp

namespace_test: namespace_test.cpp namespace.cpp namespace.h
	g++ -std=gnu++11 -Wall -o namespace_test namespace_test.cpp namespace.cpp

clean:
	rm -f $(TARGETS)
