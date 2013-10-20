#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <iostream>

using namespace std;

class configuration {
public:
    enum confExcp {
        MvNotAllowd,
        InvalidPos
    };

    enum MovementWay {
        UP,
        DOWN,
        RIGHT,
        LEFT
    };

    typedef int T;

private:
    T *m_elems;
    size_t  m_rows,
            m_columns,
            m_pivot_row,
            m_pivot_column;

private:
    T &elem(size_t _row, size_t _column);

public:
    configuration(T *C,
                  size_t _rows,
                  size_t _columns);

    configuration(configuration &_obj);

    ~configuration();

    friend ostream &operator<<(ostream &os, configuration &obj) {
        size_t pos = 0;
        for(size_t i = 0; i < obj.m_rows; ++i) {
            for(size_t j = 0; j < obj.m_columns; ++j) {
                os << obj.m_elems[pos] << "\t";
                pos++;
            }
            os << endl;
        }
        return os;
    }

    size_t nRightPos();

    configuration *move_to(MovementWay _way);
};

#endif // CONFIGURATION_H
