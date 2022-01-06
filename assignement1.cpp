#include <iostream>
#include <math.h>
#include <limits>
#include <iomanip>
using namespace std;

float interpolation(double coord[][3],int n, int counter,double xp);
void Banner();
float generateX(float k,float interval);
float coordinates(int nodes,double coord[][3], bool choice);
float functionA(float X);
float functionB(float X);


int main() {
    Banner();
/*TODO
 * two functions:
 *  f(x) = Root(1+x^2)  ;
 *  f(x) = (1+25x^2)^-1 ;
 *  for n+1 nodes we have to compute WHERE n is our iteration.
 *  we should compute the following for n
 *
 *  X(k) = -1 + 2(k-1)/n,                   k = 1, 2, 3, ... n + 1 times
 *  how do we find our x points and y ?
 *
 *
 *
 * */
    int nodes;
   /* printf("enter nodes(5-15-25): ");
    cin >> nodes;
    cout << endl;
*/


    double coord[41][3];
    int choice;

        while (1) {

            cout << "Selection Menu" << endl;
            cout << "1) Function A\n";
            cout << "2) Function B\n";
            cout << "3) exit\n";

            printf("Selection >> ");
            cin >> choice;
            int i;
            switch (choice) {
                case 1:
                    printf("\n\nfunction A\n");
                    for (i = 1; i < 4; i++) {
                        coordinates(i * 5, coord, true);
                    }
                    break;
                case 2:
                    printf("\n\nfunction B\n");
                    for (i = 1; i < 4; i++) {
                        coordinates(i * 5, coord, false);
                    }
                    break;
                case 3:
                    cout << "\ngoodbye!";
                    exit(0);
                default:
                    printf("\ninvalid choice\n");
                    break;

            }


        }




    return 0;
}



float interpolation(double coord[][3],int n, int counter,double xp)
{

    double yp=0;
    int i;
    int j;
    for(i=0;i<n;i++){
        double point=1;
        for(j=0;j<n;j++){
            if(i!=j) {
                point *= (xp - coord[j][0]) /((coord[i][0] - coord[j][0]));
            }
        }
        yp += point*coord[i][counter];
    }
    return yp;
 }


float coordinates(int nodes,double coord[][3], bool choice )
{
    float X=0;
    float y1=0;
    float y2=0;
    int k;
    double a;
    printf("*************************************************************************************************************\n");
    printf("k\tXk\t\tP(x)n\t\tY\t\tabsolute Error\n");
    printf("*************************************************************************************************************\n");
    cout << "WHEN N = "<<nodes<<endl;

    for(k=0; k<41;k++){
        X = generateX(k,40.0);
        y1 = functionA(X);
        y2 = functionB(X);

        //building my tables
        coord[k][0]=X;
        coord[k][1]=y1;
        coord[k][2]=y2;
        }
int counter;
    if(choice){
        counter =1;
    }else{
        counter=2;
    }


 for(k=0;k<41;k++) {
     a = interpolation(coord, nodes,counter,coord[k][0]);
    // printf("interpolate: %2.7lf\n", a);
     printf("%d\t",k);
     printf("%2.7f\t",coord[k][0]);
    // printf("%2.7f\t ",a);
     cout <<setprecision(7) <<setw(9)<<a<<"\t";
     if(choice) {
         printf("%2.7f\t", coord[k][1]);
     }else {
         printf("%2.7f\t", coord[k][2]);
     }
     printf("%.2E.\n",abs(a- coord[k][1]));
 }
    return 0;
}



float functionA(float X)
{
    return (float) sqrt(1+pow(X,2));
}
float functionB(float X)
{
    return pow(1+25*pow(X,2),-1);
}

float generateX(float k, float nodes)
{
    return (float)(-1.0 + 2.0*(k) /nodes);
}

void Banner()
{
    cout << "Numerical C/C++ Assignement 1 in C++" << endl;
    cout << "*********************************" << endl;
    cout << "Interpolating two functions using lagrange interpolation." << endl;
}