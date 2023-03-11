COMPILER=g++
CXXFLAGS = -std=c++20
OBJS=image.o frame_sequence.o helpers.o extractor.o
default: compile
compile: $(OBJS)
	$(COMPILER) -o extractor $(OBJS)
 
run: $(OBJS) compile
	./extractor

clean:
	rm *.o extractor