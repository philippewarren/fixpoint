CPPC = g++ --std=gnu++17

all: fixpoint.exe

fixpoint.exe: main.cpp fixpoint.hpp
	$(CPPC) main.cpp -o fixpoint.exe

clean:
	mkdir -p .out
	# mv -f *.o ./.out/
	mv -f fixpoint.exe ./.out/
