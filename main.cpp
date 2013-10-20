#include <iostream>
#include "configuration.h"

using namespace std;

int main()
{
    int A[] = {1,0,3,7,8,6,2,4,5};
    configuration B(A, 3, 3);

    try {
        cout << B.nRightPos() << endl;
        configuration *n = B.move_to(configuration::LEFT);
        cout << n->nRightPos() << endl;
        n = n->move_to(configuration::DOWN);
        cout << n->nRightPos() << endl;
        cout << *n << endl;
    }
    catch(configuration::confExcp a) {
        if(a == configuration::MvNotAllowd)
            cout << "Not allowd!" << endl;
    }

    return 0;
}

