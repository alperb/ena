BINNAME=ena.out
link:
	@mkdir -p obj
	make link_core
	make link_newton
	make link_salvador
	make link_events
	make link_queue
	make link_logs
	make link_main

link_core:
	g++ -c -std=c++11 core/*.cpp -o obj/core.o

link_newton:
	g++ -c -std=c++11 newton/*.cpp -o obj/newton.o

link_salvador:
	g++ -c -std=c++11 salvador/*.cpp -o obj/salvador.o

link_events:
	g++ -c -std=c++11 events/*.cpp -o obj/events.o

link_queue:
	g++ -c -std=c++11 queue/*.cpp -o obj/queue.o

link_logs:
	g++ -c -std=c++11 logs/*.cpp -o obj/logs.o

link_main:
	g++ -c -std=c++11 main.cpp -o obj/main.o

compile:
	make clean
	@mkdir -p bin
	make link
	g++ -ldl -lglfw -std=c++11 obj/*.o -o bin/$(BINNAME)

clean:
	rm -rf obj
	rm -rf bin