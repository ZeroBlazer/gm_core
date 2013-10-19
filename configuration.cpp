#include "configuration.h"

configuration::configuration(T C[],
                             size_t _rows,
                             size_t _columns) :
    m_elems(NULL),
    m_rows(_rows),
    m_columns(_columns)
{
    size_t size = m_rows * m_columns;
    m_elems = new T[size];

    for(size_t i = 0; i < size ; ++i)
        m_elems[i] = C[i];
}

configuration::~configuration() {
    if(m_elems)
        delete []m_elems;
}

size_t configuration::nRightPos() {
    if(m_elems) {
        size_t size = m_rows * m_columns,
               sum = 0,
               cmpr = 1; //Primer elemento
        size--;

        for(size_t i = 0; i < size; ++i, cmpr++) {
            cout << m_elems[i] << "\t" << cmpr << endl;
            if(m_elems[i] == cmpr)
                sum++;
        }

        if(m_elems[size] == 0) //Elemento libre
            sum++;

        return sum;
    }
    else
        return 0;
}
