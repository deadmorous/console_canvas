#include <iostream>

#include "Point.h"

using namespace std;

int main()
{
    using namespace ctm;
    Box b;
    b << Point(1,2) << Point(10,5);
    cout << b << endl;
    cout << "Hello World!" << endl;
    return 0;
}

