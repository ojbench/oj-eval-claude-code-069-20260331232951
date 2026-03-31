CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

# Find all .cpp files
SOURCES = $(wildcard *.cpp)

# If no cpp files, create a placeholder
ifeq ($(SOURCES),)
code:
	@echo "No source files to compile"
	@touch code
else
OBJECTS = $(SOURCES:.cpp=.o)

code: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o code $(OBJECTS)

%.o: %.cpp template.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o code

.PHONY: clean
endif
