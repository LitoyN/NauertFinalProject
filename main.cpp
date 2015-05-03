/* 
 * File:   main.cpp
 * Author: elliot
 *
 * Created on April 28, 2015, 4:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <Windows.h>


using namespace std;

int gcd(int a, int b);

unsigned long int rpfCount = 0;

void phi(int limit){
    
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    
    cout << "Total: " << rpfCount;

    return 0;
}

int gcd(int a, int b){
    while (b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

