// OOP_Seminar02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <random>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>

//EX1
int     search(const char* s, char* f)
{
    int index = 0;
    while (index < strlen(s) && index < strlen(f) && s[index] == f[index])
        index++;
    if (index == strlen(f))
        return 1;
    return 0;
}

char* strfind(char* s, char* f)
{
    int index;
    for (index=0; index<strlen(s); index++)
    {
        if (s[index] == f[0])
            if (search(s + index, f) == 1)
                return (s + index);
    }
    return nullptr;
}
//EX2
typedef struct ex02
{
    long double x6;
    bool x1;
    char x2;
    int x3;
    double x4;
    long x5;
}Ex02;

//EX4

size_t myStrlen(const char* s)
{
    size_t index = 0;
    while (*(s + index) != 0)
        index++;
    return index;
}

char* myStrcpy(char* dest, const char* src)
{
    int index;
    for (index = 0; index < myStrlen(src); index++)
    {
        *(dest + index) = *(src + index);
    }
    *(dest + index) = '\0';
    return dest;
}
#include <math.h>

//EX5
double        calculatePI(float numbersToBeGenerated)
{
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-1.0, 1.0);
    float xPos;
    float yPos;
    float myPI;
    float inCircle = 0;
    int index;
    for (index = 0; index < numbersToBeGenerated; index++)
    {
        yPos = distribution(generator);
        xPos = distribution(generator);
        if (sqrt(xPos * xPos + yPos * yPos) <= 1)
            inCircle++;
    }
    myPI =float(4 * inCircle / numbersToBeGenerated);
    return myPI;
}

void        seminarTest()
{
    char s[20] = "Ana are mere";
    char f[20] = "are";
    printf("======================================\n");
    printf("=            EX 01                   =\n");
    printf("======================================\n");
    printf(" s = %s\n f = %s\n strfind(s, f) = %s\n", s, f, strfind(s, f));
    printf("//////////////////////////////////////\n");
    printf("======================================\n");
    printf("=            EX 02                   =\n");
    printf("======================================\n");
    Ex02 a;
    printf("The size of such a structure is: %d\n", sizeof(a));
    printf("//////////////////////////////////////\n");
    printf("======================================\n");
    printf("=            EX 03                   =\n");
    printf("======================================\n");
    printf("//////////////////////////////////////\n");
    printf("======================================\n");
    printf("=            EX 04                   =\n");
    printf("======================================\n");
    assert(myStrlen(s) == 12);
    assert(myStrlen(f) == 3);
    printf(" Source: %s\n Destination: %s\n", s, f);
    printf(" myStrcpy(Destination, Source) = %s\n", myStrcpy(f, s));
    printf("//////////////////////////////////////\n");
    printf("======================================\n");
    printf("=            EX 05                   =\n");
    printf("======================================\n");
    printf("Numbers generated: 30 -- Approximation %f\n", calculatePI(30));
    printf("Numbers generated: 200 -- Approximation %f\n", calculatePI(200));
    printf("Numbers generated: 10000 -- Approximation %f\n", calculatePI(10000));
    printf("Numbers generated: 100000 -- Approximation %f\n", calculatePI(100000));
}

int main()
{
    seminarTest();
    return 0;
}
