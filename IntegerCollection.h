#ifndef INTEGERCOLLECTION_H_INCLUDED
#define INTEGERCOLLECTION_H_INCLUDED

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class IntegerCollection
{
public:
    static const int DEFAULT_LENGTH = 10;

    IntegerCollection();  ///no args constructor
    IntegerCollection(const IntegerCollection& original);  ///Copy Constructor
    IntegerCollection(int intRows);  ///paramatized constructor
    const IntegerCollection& operator=(const IntegerCollection& objRHS); ///An assignment Operator
    int& operator[](int r);  ///Indexing operator
    int operator()(int intTerm);  ///Invocation operator

    IntegerCollection& operator+(const IntegerCollection& objRHS);
    friend IntegerCollection& operator+(IntegerCollection& objRHS,int intIncrement);
    IntegerCollection operator++();

    friend ostream& operator<<(std::ostream& sLHS, const IntegerCollection& objRHS); ///Stream operator

    int CountTerms(int intTerm);
    ~IntegerCollection();

    string toPPM() const;
    int getLength();
    //int* OneDArray;

private:
   int Length;
   int* OneDArray; // 2D array of black or white pixels.
};


#endif // IntegerCollection_H_INCLUDED
