//This code reads a text file name int20.txt and places the strings from that
//into a 1 dimensional array the placed into 2 2 dimensional arrays
// two additional arguments are put into variables double scalar_numerator and scalar_denominator
//CW Coleman

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>     /* atoi */
#include <stdio.h>
using namespace std;
//do some work here
void Display33 (double matrix[3][3],int length);
double Det33(double matrix[3][3]);
void Scale33(double matrix[3][3],double s);
void Mult33(double A[3][3],double B[3][3], double C[3][3] );
void Inverse33(double A[3][3],double I[3][3]);
//double Inverse(double matrix[3][3]);

int main () {
    double input_array[20];
    double am[3][3];
    double bm[3][3];

    double cm[3][3];
    double dm[3][3];
    double im[3][3];
    double scalar = 0;
    double scalar_numerator = 0;
    double scalar_denominator = 0;
    double det;
    int i = 0, j = 0; int c; // i is the row and j is the column
    string line;
    double val;
    ifstream myfile ("int20.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {  val = atoi(line.c_str());// This line of code converts a string named line to an integer named val
             input_array[i] = val;
             i++;
        }//end while
    myfile.close();
  }else cout << "Unable to open file";
    //Scalar
      scalar_numerator = input_array[18];  //19th element of the input file
      scalar_denominator = input_array[19]; // 20th element
    // Build 2 arrays
    i = 0; j = 0;
    for (c = 0; c < 9;c++)
    { am[i][j] = input_array[c];
        j++;
        if(j>2){i++; j=0;}
    }
     i = 0; j = 0;
     for (c = 9; c < 18;c++)
     { bm[i][j] = input_array[c];
        j++;if(j>2){i++;j=0;}
    }
//end  Build 2 Arrays
//Get Scalar

   scalar = scalar_numerator / scalar_denominator;  // calculate a scalar decimal
  cout<<"\nMatrix A \n";
  Display33(am,3);
  cout<<"Matrix B  \n";
  Display33(bm,3);
det = Det33(am);
Mult33(am,bm,cm);
  cout<<"\n A * B = C"<<endl;
Display33(cm,3);
Inverse33(am,im);
  cout<<"\nInverse of A = det = "<<det<<endl;
Display33(im,3);
//Scale33(am,scalar);
 // cout<<"\nScaled = "<<scalar<<endl;
//Display33(am,3);
return 0;
}//end of main

void Display33 (double m[3][3], int length){
    int i, j;
    for (i = 0; i < length; i++){
            cout<<" ";
        for(j = 0; j < length;j++){
        if (m[i][j]>= 0)cout<<" "; //print space
        cout << m[i][j]<<" ";
        }//end for
        cout<<" "<<endl;
    }//end for i
}

double Det33(double m[3][3])
{
    int det31, det32, det33, det;
    // i+j^3+1 = 1
    det31 = m[2][0]*((m[0][1]*m[1][2])-(m[0][2]*m[1][1]));
    // i+j^3+2 = -1
    det32 = (-1* m[2][1])*((m[0][0]*m[1][2])-(m[0][2]*m[1][0]));
    // i+j^3+3 = 1
    det33 = m[2][2]*((m[0][0]*m[1][1])-(m[0][1]*m[1][0]));

/*debug
    cout<<"\n\n";
    cout<<matrix[2][2]<<endl;
    cout<<det31<<" "<<det32<<" "<<det33<<endl;
    */
    det = det31 + det32 + det33;

    return det;
}

void Scale33(double m[3][3],double s){
    int i, j;
    for (j = 0; j <3; j++){
         for (i = 0; i <3; i++){
            m[i][j] = m[i][j]*s;
    }
}
}

void Mult33(double A[3][3],double B[3][3],   double C[3][3] ){
    int i, j;
            //C[0][0] = 1;
            C[0][0] = (A[0][0] * B[0][0]) + (A[0][1] * B[1][0]) + (A[0][2]*B[2][0]);
            C[0][1] = (A[0][0] * B[0][1]) + (A[0][1] * B[1][1]) + (A[0][2]*B[2][1]);
            C[0][2] = (A[0][0] * B[0][2]) + (A[0][1] * B[1][2]) + (A[0][2]*B[2][2]);

            C[1][0] = (A[1][0] * B[0][0]) + (A[1][1] * B[1][0]) + (A[1][2]*B[2][0]);
            C[1][1] = (A[1][0] * B[0][1]) + (A[1][1] * B[1][1]) + (A[1][2]*B[2][1]);
            C[1][2] = (A[1][0] * B[0][2]) + (A[1][1] * B[1][2]) + (A[1][2]*B[2][2]);

            C[2][0] = (A[2][0] * B[0][0]) + (A[2][1] * B[1][0]) + (A[2][2]*B[2][0]);
            C[2][1] = (A[2][0] * B[0][1]) + (A[2][1] * B[1][1]) + (A[2][2]*B[2][1]);
            C[2][2] = (A[2][0] * B[0][2]) + (A[2][1] * B[1][2]) + (A[2][2]*B[2][2]);
}

void Inverse33(double A[3][3],double I[3][3] ){
    int i, j;
            I[0][0] = (A[1][1]*A[2][2])-(A[1][2]*A[2][1]);
            I[0][1] = 0;
            I[0][2] = 0;

            I[1][0] = 0;
            I[1][1] = 0;
            I[1][2] = 0;

            I[2][0] = 0;
            I[2][1] = 0;
            I[2][2] = 0;
}
