CXX		  := g++ 
CXX_FLAGS :=   -std=c++17 -ggdb 

all: DyH

DyH: 
	$(CXX)  -o ./DyH ./*.cpp 

clean:

	rm -f ./DyH