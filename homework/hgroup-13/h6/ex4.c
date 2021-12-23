#include "assignment.h"
#include <math.h>
// ex. 4 function: disptach work to other functions for exercise 4
void ex4() {
    int n=0;int size=0;int temporary=0;int prod=0;
    FILE* f1=fopen("matrices.txt","r");
    while(1==fscanf(f1,"%d",&temporary)){n++;}//count the number of integers
    size=(int)sqrt(n/2);
    int A[500][500]={{0}};
    int B[500][500]={{0}};
    rewind(f1);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(fscanf(f1,"%d",&A[i][j])){}
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(fscanf(f1,"%d",&B[i][j])){}
        }
    }// read the matrices
    fclose(f1);
    FILE* f2=fopen("result.txt","w");
    //sum
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            fprintf(f2,"%d ",A[i][j]+B[i][j]);
        }
        fprintf(f2,"\n");
    }
    fprintf(f2,"\n");
    //product
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                prod=prod+A[i][k]*B[k][j];
            }
            fprintf(f2,"%d ",prod);
            prod=0;
        }
        fprintf(f2,"\n");
    }
    fprintf(f2,"\n");
    //transpose
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                prod=prod+A[k][i]*B[j][k];
            }
            fprintf(f2,"%d ",prod);
            prod=0;
        }
        fprintf(f2,"\n");
    }
    fclose(f2);
}



