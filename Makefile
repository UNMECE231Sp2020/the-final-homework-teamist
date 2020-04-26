FNS = GeneralList.hpp GeneralStack.hpp GeneralQueue.hpp
MAIN = main.cpp $(FNS)

 all:
 	g++ $(MAIN) -o run_tests
clean:
	rm run_tests
