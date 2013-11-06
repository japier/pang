PKG_CONFIG_PATH := /usr/local/lib/pkgconfig:$(PKG_CONFIG_PATH)
export PKG_CONFIG_PATH

all:
	gcc main.c -o main `pkg-config --libs allegro-5.0 allegro_main-5.0 allegro_image-5.0`
	./main
