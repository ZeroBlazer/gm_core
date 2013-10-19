#include <iostream>
#include "configuration.h"

using namespace std;

int main()
{
    int A[] = {1,0,3,7,8,6,2,4,5};
    configuration B(A, 3, 3);
    cout << B.nRightPos() << endl;
    cout << "Hello World!" << endl;
    return 0;
}

