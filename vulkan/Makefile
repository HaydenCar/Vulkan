CFLAGS = -std=c++23 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

vulkan: main.cpp
	g++ $(CFLAGS) -o vulkan main.cpp src/*.cpp -g $(LDFLAGS)

.PHONY: run clean shaders

shaders:
	glslc shaders/shader.vert -o shaders/vert.spv
	glslc shaders/shader.frag -o shaders/frag.spv

run: shaders vulkan
	./vulkan

clean:
	rm -f vulkan shaders/frag.spv shaders/vert.spv
