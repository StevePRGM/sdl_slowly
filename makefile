.PHONY: all
ROOT_DIR:=$(shell cd)

all:
	@echo --- all o sdl ---
o: main.cpp
	g++ main.cpp -o"a.exe"
sdl: main.cpp
	g++ main.cpp @options
sdl_p: main.cpp
	g++ main.cpp -IC:/LIBS/SDL2_2.0.7/i686-w64-mingw32/include -LC:/LIBS/SDL2_2.0.7/i686-w64-mingw32/lib -lmingw32 -lSDL2main -lSDL2 -w -Wl,-subsystem,console -E >> a.txt