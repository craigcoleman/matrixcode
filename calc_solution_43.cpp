//This code reads a text file name int21.txt and places the strings from that file
//into a 1 dimensional array then into 2 3x3 arrays
// The last three arguments are placed into a single dimensional array
// The following functions perform matrix mathematics on the three arrays
// Add, subtract, multiply, scalar, determinant and scalar.
//  Th solution to a ax+by+cz+d system of equations is also solved with is code.
//CW Coleman

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>     /* atoi */
#include <stdio.h>
using namespace std;
//do some work here
double Det33(double m[3][3]);// calulate determinant
void Display33 (double m[3][3],int length);//display 3 by 3 array
void Scale33(double A[3][3], double B[3][3],double s);// scale 3 by 3
void Add33(double A[3][3],double B[3][3], double C[3][3],double parity ); //Add 3x3 + 3x3 then indicate a subtraaction with a -1
void Mult33(double A[3][3],double B[3][3], double C[3][3] ); //Multiply 3x3 * 3x3
void Mult31(double A[3][3],double B[3], double C[3]);//Multiply 3x3 * 3x1
void Inverse33(double A[3][3],double I[3][3],double idet); //calulate the inverse of a 3 by 3
//double Inverse(double matrix[3][3]);

int main () {
    double input_array[21];
    double am[3][3];// input a
    double bm[3][3];// input b
    double cm[3][3];//sum
    double dm[3][3];//difference
    double em[3][3];// product
    double fm[3][3]; //scalar
    double im[3][3];//inverse
    double lcolm[3]; // last column
    double solm[3]; //solution matrix
    double scalar = 0;
    double scalar_numerator = 0; // intager
    double scalar_denominator = 0; // integer
    double det, idet;// determinant and inverse
    int i = 0, j = 0; int c; // i is the row and j is the column
    string line;
    double val;
    //Get inputs from  text file name int21.txt *************************************************
    ifstream myfile ("int21.txt");
    if (myfile.is_open())
    { while ( getline (myfile,line) )
        {  val = atoi(line.c_str());// This line of code converts a string named line to an integer named val
             input_array[i] = val; i++;
        }//end while
    myfile.close();
    }else cout << "Unable to open file";
  // end of inputs *************************************************
    //Scalar
      scalar_numerator = input_array[19];  //20th element of the input file
      scalar_denominator = input_array[20];// 21th element
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
    //Build the last column
    lcolm[0] = input_array[18];
    lcolm[1] = input_array[19];
    lcolm[2] = input_array[20];
    //Get Scalar
   // scalar = scalar_numerator / scalar_denominator;  // calculate a scalar decimal
    //display A
    cout<<"\nMatrix A \n";
    Display33(am,3);
    //display B
    cout<<"Matrix B  \n";
    Display33(bm,3);
    //display last column of linear equations
      cout<<"Last column of linear equations placed in a matrix (3x1) \n";
      for(i = 0;i< 3;i++)cout<<"\t\t"<<lcolm[i]<<endl;
      // Matrix B scaled by 3
      cout<<"\n Matrix A scaled by 3 \n";
      Scale33(am,em,3);
       Display33(em,3);
    //Add am + bm = cm
    cout<<"\n A + B = C"<<endl;
    Add33(am,bm,cm,1);// send a 1 s the last arguments for addtion
    Display33(cm,3);
    //Subtract am - bm = cm
    cout<<"\n A - B = C"<<endl;
    Add33(am,bm,cm,-1); // send a -1 s the last arguments for addtion
    Display33(cm,3);
    //Multiply am * bm = cm
    cout<<"\n A * B = C"<<endl;
    Mult33(am,bm,em);
    Display33(em,3);
    //Scale    //Calulcate determinant of A
    det = Det33(am);
     cout<<"\nTranspose of A with a determinant equal to "<<det<<endl;
    Inverse33(am,em,1);
    Display33(em,3);

    idet = 1/det;
    //Calculate inverse of A wiht determinant input
    Inverse33(am,im,idet);
    cout<<"\nInverse of A with a inverse determinant (1/determinant) of "<<idet<<endl;
    //Multiply
    Display33(im,3);
    //This calculates a linear equation in the from of ax+ by + cz = d
    Mult31(im,lcolm,solm);
    cout<<"\nDisplay solution of linear eqautions  \n";
    for(i = 0;i< 3;i++)cout<<" "<<solm[i]<<endl;
    //Scale33(am,scalar);
    // cout<<"\nScaled = "<<scalar<<endl;
    Inverse33(am,em,idet);
    //Display33(am,3);
return 0;
}//end of main

void Display33 (double m[3][3], int length){
    int i, j;
    for (i = 0; i < 3; i++){
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
    det = det31 + det32 + det33;
    return det;
}

void Scale33(double A[3][3],double B[3][3],double s){
    int i, j;
    for (j = 0; j <3; j++){
         for (i = 0; i <3; i++){
            B[i][j] = A[i][j]*s;
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

void Add33(double A[3][3],double B[3][3],   double C[3][3], double parity ){
    int i, j;
           for (j = 0; j < 3; j++){
            for (i = 0; i < 3; i++){
                C[i][j] = A[i][j] + (parity*B[i][j]);
            }

           }
}


void Mult31(double A[3][3],double B[3], double C[3]){
    int i, j;
            //C[0][0] = 1;
            C[0]= (A[0][0] * B[0]) + (A[0][1] * B[1]) + (A[0][2]*B[2]);
               C[1]= (A[1][0] * B[0]) + (A[1][1] * B[1]) + (A[1][2]*B[2]);
                    C[2]= (A[2][0] * B[0]) + (A[2][1] * B[1]) + (A[2][2]*B[2]);
}

void Inverse33(double A[3][3],double I[3][3],double idet ){
    int i, j;
    double T[3][3];
    // matrix of minors
            T[0][0] = (A[1][1]*A[2][2])-(A[1][2]*A[2][1]);
            T[0][1] =  -1* ((A[1][0]*A[2][2])-(A[1][2]*A[2][0]));
            T[0][2] =  (A[1][0]*A[2][1])-(A[1][1]*A[2][0]);

            T[1][0] =-1*( (A[0][1]*A[2][2])-(A[0][2]*A[2][1]));
            T[1][1] =(A[0][0]*A[2][2])-(A[0][2]*A[2][0]);
            T[1][2] = -1 * ((A[0][0]*A[2][1])-(A[0][1]*A[2][0]));

            T[2][0] = (A[0][1]*A[1][2])-(A[0][2]*A[1][1]);
            T[2][1] = -1*((A[0][0]*A[1][2])-(A[0][2]*A[1][0]));
            T[2][2] = (A[0][0]*A[1][1])-(A[0][1]*A[1][0]);
        //transpose and multiply by 1/determinant (inverse of determinant)
        for (j = 0; j < 3; j++ ){ for (i = 0; i < 3; i++){
                    I[i][j] = idet * T[j][i];
            }}
}
