//Author: Christopher Hill For the EEE4120F course at UCT

#include<stdio.h>
#include<iostream>



using namespace std;



//creates a square matrix of dimensions Size X Size, with the values being the column number
void createKnownSquareMatrix(int Size, int* squareMatrix, bool displayMatrices){

    
    for(int i = 0; i<Size; i++){
        
        for(int j = 0; j<Size; j++){
            squareMatrix[i*Size+j] = j + 1;
            if(displayMatrices){
                cout<<squareMatrix[i*Size+j]<<"\t ";
            }
        }
        if(displayMatrices){
            cout<<"\n";
        }
    }
    

}


//creates a random square matrix of dimensions Size X Size, with values ranging from 1-100
void createRandomSquareMatrix(int Size, int* squareMatrix, bool displayMatrices){

    
    for(int i = 0; i<Size; i++){
        
        for(int j = 0; j<Size; j++){
            squareMatrix[i*Size+j] = rand() % 100 + 1;
            if(displayMatrices){
                cout<<squareMatrix[i*Size+j]<<"\t ";
            }
        }
        if(displayMatrices){
            cout<<"\n";
        }
    }
    

}




int main(void){
    clock_t start_overhead, end_overhead, start_total, end_total, start_matrix, end_matrix; //create all the timers
    start_total = clock(); //start timer to measure execution of entire program
    start_overhead = clock(); //start timer to measure overhead

    //New code for prac 2.2
    bool displayMatrices = true;
    int Size = 3;
    int countA = Size*Size;
    int matrixA[countA];
    createRandomSquareMatrix(Size,matrixA, displayMatrices);
    cout<<"Number of elements in matrix 1: "<<countA<<"\n";
    cout<<"Dimensions of matrix 1: "<<Size<<"x"<<Size<<"\n";
    cout<<"Matrix 1 pointer: "<<matrixA<<"\n";
    
    int countB = Size*Size;
    int matrixB[countB];
    createKnownSquareMatrix(Size, matrixB, displayMatrices);
    cout<<"Number of elements in matrix 2: "<<countB<<"\n";
    cout<<"Dimensions of matrix 2: "<<Size<<"x"<<Size<<"\n";
    cout<<"Matrix 2 pointer: "<<matrixB<<"\n";
    
    int output[countA];
    int temp = 0;
    
    
    
    
    end_overhead = clock();//end overhead timer and output the value
    printf ("Run Time overhead: %0.8f sec \n",((float) end_overhead - start_overhead)/CLOCKS_PER_SEC);
    
    start_matrix = clock(); //start timer to measure the execution speed of matrix multiplication
    
    //TODO: code your golden standard matrix multiplication here
    for (int i = 0; i<Size; i++) { //iterate though matrix
        for (int j = 0; j<Size; j++) { //iterate though matrix
            for (int k = 0; k<Size; k++) { //iterate though matrix
                temp = temp + matrixA[k+i*Size]*matrixB[k*Size+j]; //row of matrix A multiplied by column of matrix B
            }
            output[i*Size+j] = temp; //assign values to output matrix
            temp = 0;
        }
    }
    
    end_matrix = clock(); //end execution speed of matrix multiplication timer and output value
    printf ("Run Time of matrix multiplication: %0.8f sec \n",((float) end_matrix - start_matrix)/CLOCKS_PER_SEC);
    
    
    //This if statement will display the matrix in output
    if(displayMatrices){
        printf("\nOutput in the output_buffer \n");
        for(int j=0; j<countA; j++) {
            printf("%i \t " ,output[j]);
            if(j%Size == (Size-1)){
                printf("\n");
            }
        }
    }
    
    //end total execution timer and output value
    end_total = clock();
    printf ("Run Time total: %0.8f sec \n",((float) end_total - start_total)/CLOCKS_PER_SEC);
    
    return 0;
    
}

