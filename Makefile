CPPC = g++ --std=gnu++17
EXE = fixpoint.exe

.PHONY: all clean run

all: $(EXE)

$(EXE): main.cpp fixpoint.hpp
	$(CPPC) main.cpp -o $(EXE)

clean:
	mkdir -p .out
	# mv -f *.o ./.out/
	mv -f $(EXE) ./.out/
