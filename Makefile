OS := ${shell uname}

ifeq (${OS}, Linux)
tinyfetch: src/main.c src/linux/linuxinfo.c
	@echo "Running on Linux"
	gcc src/main.c src/linux/linuxinfo.c -o tinyfetch
else ifeq (${OS}, Darwin)
tinyfetch: src/main.c src/apple/appleinfo.c
	@echo "Running on macOs"
	gcc src/main.c src/apple/appleinfo.c -o tinyfetch
else
all:
	@echo "This is not an officially supported system"
endif
