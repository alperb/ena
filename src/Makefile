CPPFLAGS=''

compile:
	g++ *.cpp \
		vendors/stb_image/*.cpp \
		vendors/imgui/*.cpp \
		objects/*.cpp \
		`pkg-config --cflags freetype2` \
		`pkg-config --libs freetype2` \
		-lglfw -framework OpenGL -L/usr/local/Cellar/assimp/5.2.5/lib -L/usr/local/Cellar/glew/2.2.0_1/lib -lassimp -lGLEW -std=c++11

debug:
	g++ -g Application.cpp ${CPPFLAGS}

obj:
	g++ -c *.cpp vendors/stb_image/*.cpp vendors/imgui/*.cpp ${CPPFLAGS} -o ena.obj

run:
	make compile
	./a.out