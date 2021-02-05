#include "IntegerCollection .h"

#include<cassert>
#include <sstream>

using namespace std;

IntegerCollection ::IntegerCollection () : IntegerCollection (DEFAULT_LENGTH) {} ///no args constrcutor

IntegerCollection ::IntegerCollection (int intRows) ///parameterized constructor
{
    Length = intRows;

    OneDArray = new int[Length];
    for(int r = 0; r < Length; r++)
    {
        OneDArray[r]=r+1;

    }
}
IntegerCollection ::IntegerCollection (const IntegerCollection & original) ///Copy Constructor
{ //Copy Constructor
    Length = original.Length;
    OneDArray = new int[Length];
    for(int r = 0; r < Length; r++)
    {
        OneDArray[r] = original.OneDArray[r];
    }

}

const IntegerCollection & IntegerCollection ::operator=(const IntegerCollection & objRHS)
{
    if(this != &objRHS)
    {
        for(int r = 0; r < Length; r++)
        {
            OneDArray[r] = objRHS.OneDArray[r];

        }
    }
    return *this; /// Support chaining.
}

/// UJIntCollection(r) "Indexing" Operator [Member]
int& IntegerCollection ::operator[](int r)
{
    return OneDArray[r];
}

IntegerCollection IntegerCollection ::operator++()
{
    for(int r = 0; r < Length; r++)
    {
        ++OneDArray[r];
    }
    return *this;
}
IntegerCollection & operator+( IntegerCollection & objRHS,int intIncrement)
{
    IntegerCollection * Newobj = new IntegerCollection (objRHS.Length);
    for(int i=0; i<objRHS.Length; i++)
    {
        Newobj->OneDArray[i]=objRHS.OneDArray[i]+intIncrement;
    }
    return *Newobj;
}

IntegerCollection & IntegerCollection ::operator+(const IntegerCollection & objRHS)
{
    if(Length != objRHS.Length)
    {
        cout << " cannot be different sizes" << endl;
        exit(-1);
    }
    IntegerCollection * newImage = new IntegerCollection (Length);
    for(int r = 0; r < Length; r++)
    {
      //Do addition
        newImage->OneDArray[r] = OneDArray[r] + objRHS.OneDArray[r];
    }
    return *newImage;
}

int IntegerCollection ::operator()(int intTerm)
{
    int intNumTerms=0;
    for(int r = 0; r < Length; r++)
    {
      //Do addition
        if(OneDArray[r] == intTerm)
           intNumTerms++;
    }
    return intNumTerms;
}

ostream& operator<<(ostream& sLHS, const IntegerCollection & objRHS)
{
    sLHS << objRHS.toPPM();
    return sLHS;
}

int IntegerCollection ::getLength()
{
    return Length;
}

string IntegerCollection ::toPPM() const
{
    //This method produces and returns a P1 PPM string.

    stringstream ssPPM;
    //ssPPM << "P1" << endl
         //<< cols << ' ' << rows << endl;

    for(int r = 0; r < Length; r++)
    {

        ssPPM << OneDArray[r] << ' ';

    }
    return ssPPM.str();
}

IntegerCollection ::~IntegerCollection ()
{
    delete[] OneDArray;
}
