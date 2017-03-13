CXX = g++
CXXFLAGS = -g -lgtest -lgtest_main -lpthread
OBJS = nextDate.o

test: $(OBJS)
	$(CXX) $(CXXFLAGS) main.cpp $(OBJS) -o test

.cpp.o:
	$(CXX) -c $< -o $@

clean:
	rm test $(OBJS)
