//Этот класс реализует контейнер целых чисел

#ifndef IntegerArray_hpp
#define IntegerArray_hpp
#include <cassert> // for assert()

class IntegerArray
{
private:
    int m_length{}; //Параметр длины контейнера
    int* m_data{}; //Параметр данных контейнера

public:
    IntegerArray() = default; //Конструктор пустого контейнера

    IntegerArray(int length); // Конструктор контейнера заданной длины

    IntegerArray(const IntegerArray& a); //Конструктор копирования

    ~IntegerArray(); //Деструктор

    void erase(); //Функция отчистки массива и сброса длины

    int& operator[](int index); //Перегрузка оператора [] для доступа к элементам

    void reallocate(int newLength); //Функция изменения размера контейнера с удалением элементов

    void resize(int newLength); // ... с сохранением элементов

    IntegerArray& operator=(const IntegerArray& a); //Перегрузка оператора присваивания для возможно копирования контейнера

    void insertBefore(int value, int index); //Функция вставки элемента

    void remove(int index); //Функция удаления элемента

    void insertAtBeginning(int value) { insertBefore(value, 0); } //Функция добавления элемента в начало контейнера
    void insertAtEnd(int value) { insertBefore(value, m_length); } // ... в конец контейнера

    int getLength() const { return m_length; } //Геттер длины контейнера
};


#endif /* IntegerArray_hpp */
