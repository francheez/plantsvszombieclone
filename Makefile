cxx = g++

src_dir = src
obj_dir = bin
include_dir = include

cxxflags = -I$(include_dir) -std=c++17
ldflags = -lSDL2 -lSDL2_image -lSDL2_ttf

srcs = $(wildcard $(src_dir)/*.cpp)
objs = $(srcs:$(src_dir)/%.cpp=$(obj_dir)/%.o)
target = game

all: $(target)

$(target): $(objs)
	@$(cxx) -o $@ $(objs) $(ldflags)

$(obj_dir)/%.o: $(src_dir)/%.cpp
	@mkdir -p $(obj_dir)
	@$(cxx) $(cxxflags) -c $< -o $@

clean:
	@rm -f $(obj_dir)/*.o $(target)

.PHONY: all clean
