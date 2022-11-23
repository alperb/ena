BINNAME=ena.out

CFLAGS := -Wall -g -std=c++11 -ldl -lglfw
LFLAGS := -std=c++11 -c -Wall

SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))


only_compile:
	@mkdir -p obj
	make only_compile_core
	make only_compile_newton
	make only_compile_salvador
	make only_compile_events
	make only_compile_queue
	make only_compile_logs
	make only_compile_main

only_compile_core:
	g++ $(LFLAGS) core/*.cpp -o obj/core.obj

only_compile_newton:
	g++ $(LFLAGS) newton/*.cpp -o obj/newton.obj

only_compile_salvador:
	g++ $(LFLAGS) salvador/*.cpp -o obj/salvador.obj

only_compile_events:
	g++ $(LFLAGS) events/*.cpp -o obj/events.obj

only_compile_queue:
	g++ $(LFLAGS) queue/*.cpp -o obj/queue.obj

only_compile_logs:
	g++ $(LFLAGS) logs/*.cpp -o obj/logs.obj

only_compile_main:
	g++ $(LFLAGS) main.cpp -o obj/main.obj

only_compile_all:
	make only_compile 
	ld -relocatable *.o -o ena.obj

link:
	g++ $(CFLAGS) obj/*.obj -o bin/$(BINNAME)

run:
	make clean
	@mkdir -p bin
	make only_compile
	make link
	make clean_objs

clean_objs:
	rm -rf obj

clean:
	make clean_objs
	rm -rf bin
	rm -f *.obj
	rm -f *.o

.PHONY: run clean link clean_objs