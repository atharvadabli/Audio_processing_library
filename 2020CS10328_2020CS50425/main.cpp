#include"libaudioAPI.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include"libaudioAPI.cpp"

using namespace std;

string label_name(int label)
{
    switch(label)
    {
        case 0:
            return "silence";
        case 1:
            return "unknown";

        case 2:
            return "yes";
        case 3:
            return "no" ;
        case 4:
            return "up";
        case 5:
            return "down" ;
        case 6:
            return "left";
        case 7:
            return "right" ;
        case 8:
            return "on";
        case 9:
            return "off" ;
        case 10:
            return "stop";
        case 11:
            return "go" ;
    }
    return " ";
}

int main(int argc, char const *argv[])
{
    ifstream myFile(argv[1]);
    if(myFile.fail()){
        printf("Input file does not exist\n");
        return 0;
    }

    char const *input = argv[1];
    string output_name = argv[2];
    pred_t *pred;
    pred = (pred_t *)malloc(3*sizeof(pred_t));

    pred = libaudioAPI(input, pred);

    ofstream out;
    out.open(output_name, std::ios_base::app);
    out<<input<<" "<<label_name(pred[0].label)<<" "<<label_name(pred[1].label)<<" "<<label_name(pred[2].label)<<" "<<pred[0].prob<<" "<<pred[1].prob<<" "<<pred[2].prob<<"\n";
    out.close();
    return 0;
}