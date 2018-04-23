# Makefile

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g -w

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o solution.o
	$(CXX) $(CXXFLAGS) -o main main.o solution.o

# The main.o target can be written more simply

main.o: main.cpp main.h
	$(CXX) $(CXXFLAGS) -c main.cpp

solution.o: solution.cpp solution.h

clean: 
	rm -rf *o make