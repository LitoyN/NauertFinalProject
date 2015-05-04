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
int *primes = new int[78500];
int *composites = new int[921505];
int compositeCounter = 0;
int primeCounter = 0;
unsigned long int compositeRPFCount = 0;
unsigned long int rpfCount = 0;

/**
 * Credit: http://www.algolist.net/Algorithms/Number_theoretic/Sieve_of_Eratosthenes
 * @param upperBound
 */
void primeSieve(int upperBound) {
      int upperBoundSquareRoot = (int)sqrt((double)upperBound);
      bool *isComposite = new bool[upperBound + 1];
      primeCounter = 0;

      memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
      for (int m = 2; m <= upperBoundSquareRoot; m++) {
            if (!isComposite[m]) {
                  primes[primeCounter] = m;
                  primeCounter++;
                  for (int k = m * m; k <= upperBound; k += m)
                        isComposite[k] = true;
            }
            else{
                composites[compositeCounter] = m;
                compositeCounter++;
            }
      }
      for (int m = upperBoundSquareRoot; m <= upperBound; m++)
            if (!isComposite[m]){
                  primes[primeCounter] = m;
                  primeCounter++;
            }
            else{
                composites[compositeCounter] = m;
                compositeCounter++;
            }
      delete [] isComposite;
      cout << endl << "Number of Primes: " << primeCounter << endl;
      cout << endl << "Number of Composites: " << compositeCounter << endl;

}

void reducedFractionSieve2(int upperBound) {

    bool *isComposite = new bool[upperBound + 1];
    memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
    
    compositeRPFCount++; //add 1 for numerators of 1
    for (int m = 1; m < upperBound; m++) {
        
        int actualVal = m + 1;
        if(!isComposite[m]){
            if(upperBound%actualVal == 0){
                for (int k = m; k <= upperBound; k+=actualVal){
                    isComposite[k] = true;
                }
            }
            else{
                compositeRPFCount++;
            }
            
        }
    }
    
    delete [] isComposite;

}

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    compositeCounter = 0;
    int fractionCount = 0;
    int upperBound = 1000000;

    primeSieve(upperBound);
    cout << endl;
    unsigned long int primesRPF = 0;
    
    for(int i = 0; i < primeCounter; i++){
        primesRPF += (primes[i]-1);
    }

    cout << "RPF with prime denominators: " << primesRPF << endl;
    
    for(int i = 0; i < upperBound; i++){
        reducedFractionSieve2(composites[i]);
    }
    
    cout << "RPF with composite denominators: " << compositeRPFCount << endl;
    
    cout << "Total RPFs with denominator <= " << upperBound << ": " << primesRPF + compositeRPFCount << endl;
    

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

