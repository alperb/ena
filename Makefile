compile:
	g++ src/Application.cpp -lglfw -lGLEW -framework OpenGL -std=c++11

debug:
	g++ -g src/Application.cpp -lglfw -lGLEW -framework OpenGL -std=c++11