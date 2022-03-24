COMPILER_FLAGS = -fopenmp -lpthread -lm -ldl -lopenblas -laudioAPI
OPENBLASS_LIB_DIR =  /usr/lib/x86_64-linux-gnu/libopenblas.a
OPENBLASS_INCLUDE_DIR = usr/include/openblas

main : main.cpp
	g++ -L$(OPENBLASS_LIB_DIR) -L . -I$(OPENBLASS_INCLUDE_DIR)  main.cpp -o yourcode.out $(COMPILER_FLAGS)
.PHONY : clean

clean : 
	rm main