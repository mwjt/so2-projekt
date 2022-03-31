install:
	/usr/bin/g++ -g *.cpp -pthread -o main -lncurses -pthread
run:
	./main
clean:
	rm ./main
