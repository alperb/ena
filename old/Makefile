compile:
	g++ src/*.cpp src/objects/*.cpp src/vendors/stb_image/*.cpp src/vendors/imgui/*.cpp -lglfw -lGLEW -framework OpenGL -std=c++11

debug:
	g++ -g src/Application.cpp -lglfw -lGLEW -framework OpenGL -std=c++11

run:
	make compile
	./a.out