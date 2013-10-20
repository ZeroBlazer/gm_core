#include "configuration.h"

configuration::T &configuration::elem(size_t _row, size_t _column)
{
    if(_row < m_rows && _column < m_columns)
        return m_elems[_row * m_columns + _column];
    else
        throw InvalidPos;
}

configuration::configuration(T *C,
                             size_t _rows,
                             size_t _columns) :
    m_elems(NULL),
    m_rows(_rows),
    m_columns(_columns),
    m_pivot_row(0),
    m_pivot_column(0)
{
    size_t size = m_rows * m_columns;
    m_elems = new T[size];

    for(size_t i = 0; i < size ; ++i) {
        m_elems[i] = C[i];
        if(m_elems[i] == 0) {
            m_pivot_row = i / m_rows;
            m_pivot_column = i % m_rows;
        }
    }
}

configuration::configuration(configuration &_obj)
{
    m_rows = _obj.m_rows;
    m_columns = _obj.m_columns;
    m_pivot_row = _obj.m_pivot_row;
    m_pivot_column = _obj.m_pivot_column;

    size_t size = m_rows * m_columns;

    m_elems = new T[size];

    for(size_t i = 0; i < size ; ++i)
        m_elems[i] = _obj.m_elems[i];
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

        for(size_t i = 0; i < size; i++, cmpr++) {
            if(m_elems[i] == cmpr)
            {
                sum++;
                cout << m_elems[i] << "\t";
            }
        }

        cout << endl;

        if(m_elems[size] == 0) //Elemento libre
            sum++;

        return sum;
    }
    else
        return 0;
}

//Hacer delete después de usar la configuración
configuration *configuration::move_to(MovementWay _way) {
    size_t  new_y = m_pivot_row,
            new_x = m_pivot_column;

    switch (_way) {
    case UP:
        if(m_pivot_row == 0)
            throw MvNotAllowd;
        new_y--;
        break;
    case DOWN:
        if(m_pivot_row == m_rows-1)
            throw MvNotAllowd;
        new_y++;
        break;
    case RIGHT:
        if(m_pivot_column == m_columns-1)
            throw MvNotAllowd;
        new_x++;
        break;
    case LEFT:
        if(m_pivot_column == 0)
            throw MvNotAllowd;
        new_x--;
        break;
    }

    configuration *_ret = new configuration(*this);

    _ret->elem(m_pivot_row, m_pivot_column) = _ret->elem(new_y, new_x);
    _ret->elem(new_y, new_x) = 0;
    _ret->m_pivot_row = new_y;
    _ret->m_pivot_column = new_x;

    return _ret;
}
