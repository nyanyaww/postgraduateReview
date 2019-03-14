cc = g++ -std=c++11
target = main
test_target = test
output = demo
BIN = ./Bin/

all:
	$(cc) ../main.cpp ../test.cpp -o $(BIN)demo

pre-build:
	if ! [ -d ./Bin ]; then mkdir ./Bin; fi
	if ! [ -d ./Obj ]; then mkdir ./Obj; fi

clean:
	if [ -d ./Bin ]; then rm -r ./Bin; fi
	if [ -d ./Obj ]; then rm -r ./Obj; fi

run:
	$(BIN)demo

