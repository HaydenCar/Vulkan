CFLAGS = -std=c++23 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

vulkan: main.cpp
	g++ $(CFLAGS) -o vulkan main.cpp src/*.cpp -g $(LDFLAGS)

.PHONY: run clean

run: vulkan
	./vulkan

clean:
	rm -f vulkan
