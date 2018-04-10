.PHONY: all
ROOT_DIR:=$(shell cd)

all:
	@echo --- all o sdl ---
o: main.cpp
	g++ main.cpp -o"a.exe"
sdl: main.cpp
	g++ main.cpp @options -o"a SDL.exe"
