#ifndef STATIC_STRING_H
#define STATIC_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//静态串
//串的核心数据时一个char 的数组，所以叫静态串
#define MAX_SIZE  100

typedef struct STATIC_STRING
{
    char data[MAX_SIZE];
}string_t;




#endif


