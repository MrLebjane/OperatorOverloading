#include <iostream>

#include "IntegerCollection .h"

using namespace std;

int main()
{
     IntegerCollection Array1(10);
     IntegerCollection Array2;
     Array2=Array1;
     cout<<Array1<<endl;
     IntegerCollection AddArray=Array1+Array2;
     cout<<AddArray<<endl;
     Array1[2]=5;
     Array1[5]=5;
     cout<<Array1(5)<<endl;
     cout<<Array2<<endl;
     IntegerCollection IncrementedArray1=++Array2;
     cout<<IncrementedArray1<<endl;
     IntegerCollection IncrementedArray2=Array2+2;
     cout<<IncrementedArray2<<endl;
	 

}
