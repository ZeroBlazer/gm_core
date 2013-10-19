#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <iostream>

using namespace std;

class configuration {
    typedef int T;
private:
    T *m_elems;
    size_t m_rows,
           m_columns;

public:
    configuration(T *C,
                  size_t _rows,
                  size_t _columns);

    ~configuration();

    size_t nRightPos();

};

#endif // CONFIGURATION_H
