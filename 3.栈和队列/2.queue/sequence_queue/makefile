CC = gcc
RELEASEFLAGS = -O3
DEBUGFLAGS = -DDEBUG

release:compile_release run

debug:compile_debug run

compile_release:
	$(CC) $(RELEASEFLAGS) main.c -o main

compile_debug:
	$(CC) $(DEBUGFLAGS) main.c -o main

run:
	./main

clean:
	rm main

.PHONY: clean