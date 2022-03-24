# Audio_processing_library

We implemented a deep neural network (DNN) inference for classifying across 12 audio keywords (silence, unknown, yes, no, up, down, left, right, on, off, stop, go). [1x250] input features for each 1 second audio sample are taken through a feature gennerating python code. DNN comprise of FC1 [250x144] -> RELU -> FC2 [144x144] -> RELU -> FC3 [144X144] -> RELU -> FC4 [144x12] -> softmax.

We created your own audio processing library with an API we can call from a cpp program. Given feature vector of a 1 second audio clip, the API returns the top 3 keywords with highest softmax probabilities.

The following readme contains how we made the library.
# Implemented on Linux os.
--The libraries needed for this implementation:
   linear algebra library openblas for fast matrix multiplication.

.............................................................
--How to make and compile the library :
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
