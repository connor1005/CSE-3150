CXX = g++
CXXFLAGS = -std=c++17 -g

all: solution

solution: solution.cpp
	$(CXX) $(CXXFLAGS) -o solution solution.cpp

clean:
	rm -f solution game_output.csv game_input.csv

test:
	pytest test_game.py
