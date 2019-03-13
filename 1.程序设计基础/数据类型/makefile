cc = g++ -std=c++11
target = main.cpp
output = demo
BIN = Bin/

pre-build:
	if ! [ -d ./Bin ]; then mkdir ./Bin; fi
all:
	mkdir $(BIN)
	$(cc) $(target) -o $(BIN)demo

clean:
	rm -rf $(BIN)*
	