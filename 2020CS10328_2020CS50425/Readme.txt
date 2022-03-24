The following readme contains how we made the library.


.............................................................
How to make and compile the library :
(This part is already done)
The code for the library is included in libaudioAPI.h and libaudioAPI.cpp

We will write the following commands to generate libaudioAPI.o and libaudioAPI.so files

g++ -I usr/include/openblas -c libaudioAPI.cpp -fopenmp -lpthread -lm -ldl -lopenblas -llibaudioAPI -fPIC

g++ -I usr/include/openblas -shared -o libaudioAPI.so libaudioAPI.o

Now we have libaudioAPI.so library.
......................................................................................


Now run the make file.
We can now run our code by writing in the command line
./yourcode.out input.txt output.txt

The function libaudioAPI has been implemented and calculates the top 3 possible things that the audio would
be generating.