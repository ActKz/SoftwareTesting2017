CXX = g++
CXXFLAGS = -g -lgtest -lgtest_main -lpthread
OBJS = triangle.o

test: $(OBJS)
	$(CXX) $(CXXFLAGS) main.cpp $(OBJS) -o test.out

.cpp.o:
	$(CXX) -c $< -o $@

clean:
	rm test.out $(OBJS)
