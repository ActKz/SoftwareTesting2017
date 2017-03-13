CXX = g++
CXXFLAGS = -g -lgtest -lgtest_main -lpthread
OBJS = nextDate.o

test: $(OBJS)
	$(CXX) $(CXXFLAGS) main.cpp $(OBJS) -o test.out

.cpp.o:
	$(CXX) -c $< -o $@

clean:
	rm test.out $(OBJS)
