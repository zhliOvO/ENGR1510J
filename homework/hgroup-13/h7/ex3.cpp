#include "homework.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
void ex3(){
    //Write code for exercise 3
    int n=0;int size=0;int prod=0;int temp;
    ifstream f1("matrices.txt",ios::in);ofstream f2("result.txt",ios::out);
    if(f1.is_open() && f2.is_open()){
        while(f1>>temp){n++;}//count the number of integers
        f1.clear();f1.seekg(ios::beg);
        size=(int)sqrt(n/2);
        int A[500][500]={{0}};
        int B[500][500]={{0}};
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                f1>>A[i][j];
            }
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                f1>>B[i][j];
            }
        }//read the matrices
        f1.close();
        //sum
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                f2<<A[i][j]+B[i][j]<<" ";
            }
            f2<<endl;
        }
        f2<<endl;
        //product
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                for (int k = 0; k < size; k++)
                {
                    prod = prod + A[i][k] * B[k][j];
                }
                f2<<prod<<" ";
                prod = 0;
            }
            f2<<endl;
        }
        f2<<endl;
        //transpose
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                for (int k = 0; k < size; k++)
                {
                    prod = prod + A[k][i] * B[j][k];
                }
                f2<<prod<<" ";
                prod = 0;
            }
            f2<<endl;
        }
        f2.close();
    }
    else cerr<<"Unable to open the files\n";
}

