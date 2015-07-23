TARGETS=cinout functions variables externc thread string \
        class_overview class_abstract class_template \
        list namespace_test exception dynamic_cast

all: $(TARGETS)

cinout: cinout.cpp
	g++ -std=gnu++11 -Wall -o cinout cinout.cpp

functions: functions.cpp
	g++ -std=gnu++11 -Wall -o functions functions.cpp

variables: variables.cpp
	g++ -std=gnu++11 -Wall -o variables variables.cpp

externc: externc.cpp
	g++ -std=gnu++11 -Wall -o externc externc.cpp

thread: thread.cpp
	g++ -std=gnu++11 -Wall -pthread -o thread thread.cpp

string: string.cpp
	g++ -std=gnu++11 -Wall -o string string.cpp

class_overview: class_overview.cpp
	g++ -std=gnu++11 -Wall -o class_overview class_overview.cpp

class_abstract: class_abstract.cpp
	g++ -std=gnu++11 -Wall -o class_abstract class_abstract.cpp

class_template: class_template.cpp
	g++ -std=gnu++11 -Wall -o class_template class_template.cpp

list: list.cpp
	g++ -std=gnu++11 -Wall -o list list.cpp

namespace_test: namespace_test.cpp namespace.cpp namespace.h
	g++ -std=gnu++11 -Wall -o namespace_test namespace_test.cpp namespace.cpp

exception: exception.cpp
	g++ -std=gnu++11 -Wall -o exception exception.cpp

dynamic_cast: dynamic_cast.cpp
	g++ -std=gnu++11 -Wall -o dynamic_cast dynamic_cast.cpp

clean:
	rm -f $(TARGETS)
