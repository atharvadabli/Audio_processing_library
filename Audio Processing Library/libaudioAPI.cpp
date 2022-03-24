#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"cblas.h"
#include<fstream>
#include"dnn_weights.h"
#include<math.h>
#include"libaudioAPI.h"
#include<string>
using namespace std;

double WT_1[] = IP1_WT ;
double WT_2[] = IP2_WT ;
double WT_3[] = IP3_WT ;
double WT_4[] = IP4_WT ;

double Bias1[] = IP1_BIAS ;
double Bias2[] = IP2_BIAS ;
double Bias3[] = IP3_BIAS ;
double Bias4[] = IP4_BIAS ;


int m,n,k ;
void relu(double * array, int length)
{
    for(int i =0 ; i<length; i++)
    {
        if(array[i]<0)
        {
            array[i] =0;
        }
    }
    return ;
}

void softmax(double *array, int length)
{
    double sum = 0 ;
    for(int i =0; i<length ; i++)
    {
        array[i] = exp(array[i]);
        sum = sum + array[i];
    }
    for(int i =0 ;i < length; i++)
    {
        array[i] = array[i] / sum ;
    }
    return ;
}

pred_t* libaudioAPI(const char* audiofeatures, pred_t* pred)
{
    string inp_file_name = audiofeatures;
    ifstream input(inp_file_name);
    double * features;
    features = (double *)malloc( 250 * sizeof(double));
    int i =0;
    while(!input.eof())
    {
        input>>features[i];
        i++;
    }

    
    // FC1 
    m = 1;
    k = 250;
    n = 144;
    // A = features, B = WT_1, C = Bias1 
    double C[] = IP1_BIAS;
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1, features, k, WT_1, n, 1, C, n);
    relu(C , 144);

    //FC2

    m = 1;
    k = 144;
    n = 144;
    // A = features, B = WT_1, C = Bias1 
    double D[] = IP2_BIAS;
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1, C, k, WT_2, n, 1, D, n);
    relu(D , 144);

    //FC3
    
    double E[] = IP3_BIAS;
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1, D, k, WT_3, n, 1, E, n);
    relu(E , 144);

    // FC4
    n = 12;
    double F[] = IP4_BIAS;

    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1, E, k, WT_4, n, 1, F, n);
    softmax(F , 12);

    double third = -1, first= -1, second = -1;
    int label_1 = -1, label_2 = -1, label_3 = -1;
    for(int i = 0; i < 12; i++)
    {
         
        // If current element is
        // greater than first
        if (F[i] > first)
        {
            third = second;
            second = first;
            first = F[i];

            label_3 = label_2;
            label_2 = label_1;
            label_1 = i;
        }
 
        // If arr[i] is in between first
        // and second then update second
        else if (F[i] > second)
        {
            third = second;
            second = F[i];

            label_3 = label_2;
            label_2 = i;
        }
 
        else if (F[i] > third)
         {
             third = F[i];
             label_3 = i;
         }   
    }
 
    pred[0].label = label_1;
    pred[0].prob = (float)first;

    pred[1].label = label_2;
    pred[1].prob = (float)second;

    pred[2].label = label_3;
    pred[2].prob = (float)third;

    return pred;
}

