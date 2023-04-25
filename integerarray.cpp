#include "integerarray.h"
#include "exceptions.h"

using namespace std;

IntegerArray::IntegerArray(int length):
    m_length{ length }
{
    try
    {
        if (length <= 0)
        {
            throw BadLength();
        }
    }
    catch (BadLength& a)
    {
        cout << a.what() << endl;
    }

    if (length > 0)
        m_data = new int[length]{};
};

IntegerArray::IntegerArray(const IntegerArray& a)
{
    reallocate(a.getLength());

    for (int index{ 0 }; index < m_length; ++index)
        m_data[index] = a.m_data[index];
};

IntegerArray::~IntegerArray()
{
    delete[] m_data;
};

void IntegerArray::erase()
{
    delete[] m_data;

    m_data = nullptr;
    m_length = 0;
};

int& IntegerArray::operator[](int index)
{
    try
    {
        if (index < 0)
        {
            throw BadIndex();
        }
        if (index > m_length)
        {
            throw BadIndex();
        }
    }
    catch (BadIndex& e)
    {
        cout << e.what() << endl;
    }

    return m_data[index];
};

void IntegerArray::reallocate(int newLength)
{
    erase();

    if (newLength <= 0)
        return;

    m_data = new int[newLength];
    m_length = newLength;
};

void IntegerArray::resize(int newLength)
{
    if (newLength == m_length)
        return;

    if (newLength <= 0)
    {
        erase();
        return;
    }

    int* data{ new int[newLength] };

    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

        for (int index{ 0 }; index < elementsToCopy; ++index)
            data[index] = m_data[index];
    }

    delete[] m_data;

    m_data = data;
    m_length = newLength;
};

IntegerArray& IntegerArray::operator=(const IntegerArray& a)
{
    if (&a == this)
        return *this;

    reallocate(a.getLength());

    for (int index{ 0 }; index < m_length; ++index)
        m_data[index] = a.m_data[index];

    return *this;
};

void IntegerArray::insertBefore(int value, int index)
{
    try
    {
        if (index > m_length)
        {
            throw BadIndex();
        }
        if (index < 0)
        {
            throw BadIndex();
        }
    }
    catch (BadIndex& e)
    {
        cout << e.what() << endl;
    }

    int* data{ new int[m_length+1] };

    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];

    data[index] = value;

    for (int after{ index }; after < m_length; ++after)
        data[after+1] = m_data[after];

    delete[] m_data;
    m_data = data;
    ++m_length;

};

void IntegerArray::remove(int index)
{
    try
    {
        if (index > m_length)
        {
            throw BadIndex();
        }
        if (index < 0)
        {
            throw BadIndex();
        }
    }
    catch (BadIndex& e)
    {
        cout << e.what() << endl;
    }

    if (m_length == 1)
    {
        erase();
        return;
    }

    int* data{ new int[m_length-1] };

    for (int before{ 0 }; before  < index; ++before)
        data[before] = m_data[before];

    for (int after{ index+1 }; after < m_length; ++after)
        data[after-1] = m_data[after];

    delete[] m_data;
    m_data = data;
    --m_length;
};
