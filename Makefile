CXX = g++
CXXFLAGS = -g -lgtest -lgtest_main
OBJS = triangle.o test.o

test: $(OBJS)
	$(CXX) $(CXXFLAGS) main.cpp $(OBJS) -o test

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm test $(OBJS)
