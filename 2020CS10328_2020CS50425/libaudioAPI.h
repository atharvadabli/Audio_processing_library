#include"cblas.h"

#ifndef _lib_audio__
#define _lib_audio__

typedef struct{
    int label;
    float prob;
}pred_t;

extern pred_t* libaudioAPI(const char* audiofeatures, pred_t* pred);

#endif