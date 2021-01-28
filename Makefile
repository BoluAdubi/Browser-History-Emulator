prog: main.o executive.o browser.o 
	g++ -std=c++11 -g -Wall main.o executive.o browser.o -o prog

main.o: main.cpp executive.h LinkedList.h LinkedList.cpp ListInterface.h
	g++ -std=c++11 -g -Wall -c main.cpp
	
executive.o: executive.h executive.cpp BrowserHistoryInterface.h
	g++ -std=c++11 -g -Wall -c executive.cpp
	
browser.o: browser.h browser.cpp 
	g++ -std=c++11 -g -Wall -c browser.cpp
	
clean:
	rm *.o prog