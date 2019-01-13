
/**
* Description : Performance and height analysis for pointer and array based trees
*/

#include "analysis.h"
#include <random>


///supportive functions
void performanceOutput(int, double, double);
double diffclock(clock_t, clock_t);

///performance analysis
void Analysis::performanceAnalysis(){

    ///title
    cout<<"\nPart e - Performance analysis of BST implementations"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"\nArray Size\t"<<"Array Based\t"<<"Pointer Based"<<endl;
    cout<<"----------------------------------------------------------"<<endl;


    ///controller

    for(int curSize = 2000;curSize<=20000;curSize+=2000){
        ///initial variables
        clock_t begin=0, end=0;
        double elapsed1=0, elapsed2=0;

        ///pointer based
        PbBST sampleP;

        ///calculator loops
        begin = clock();
        for(int i=0;i<curSize;i++){
            sampleP.insert(rand()%curSize+1);
        }
        end = clock();

        elapsed2 = diffclock( begin, end );

        ///array based


        AbBST sampleA;

        begin = clock();
        for(int i=0;i<curSize;i++){
            sampleA.insert(rand()%curSize+1);
        }
        end = clock();

        elapsed1 = diffclock( begin, end );

        ///output
        performanceOutput(curSize, elapsed1, elapsed2);

    }

}

/// part (f)

///height analysis with supportive functions
void heightOutput(int, int, int);

void Analysis::heightAnalysis(){

    ///title
    cout<<"\n\nPart f - Analysis of BST height"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"Array Size\t"<<"Random numbers\t"<<"Ascending numbers"<<endl;
    cout<<"----------------------------------------------------------"<<endl;

    ///controller
    for(int curSize = 2000;curSize<=20000;curSize+=2000){
        ///initial variables
        int height1 = 0, height2 = 0;

        ///pointer based
        PbBST sample1, sample2;

        ///calculator loops
        for(int i=0;i<curSize;i++){
            sample1.insert((rand()%curSize)+1);

        }
        height1 = sample1.getHeight();

        for(int i=0;i<curSize;i++){
            sample2.insert(i);
        }

        height2 = sample2.getHeight();

        ///output
        heightOutput(curSize, height1, height2);

    }
}

///supportive functions///

/// testing height and obtaining results
void heightOutput(int sizeInput, int height1, int height2){

    cout<<sizeInput<<"\t\t"<<height1<<"\t\t"<<height2<<endl;
}

/// testing trees and obtaining results
void performanceOutput(int sizeInput, double time1, double time2){

    cout<<sizeInput<<"\t\t"<<time1<<"\t\t"<<time2<<endl;
}

/// clock difference calculation
double diffclock( clock_t clock1, clock_t clock2 ) {

    clock_t diffticks = clock2 - clock1;
    double diffms    =  ((double)diffticks *100  / CLOCKS_PER_SEC);///diffticks / ( CLOCKS_PER_SEC / 1000 );

    return diffms;
}
