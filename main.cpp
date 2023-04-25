#include <iostream>
#include "integerarray.h"
#include <exception>
#include "exceptions.h"

using namespace std;

int main()
{
    IntegerArray array(10); //Объявим контейнер

    for (int i{ 0 }; i<10; ++i)//Заполним контейнер числами от 1 до 10
    array[i] = i+1;

    array.resize(8);//Изменим размер контейнера

    array.insertBefore(20, 5);//Вставим число 20

    array.remove(3);//Удалим элемент

    cout << array[1] << endl;//Выведем элемент

    //Вставим числа 30 и 40 в начало и в конец
    array.insertAtEnd(30);
    array.insertAtBeginning(40);

    //Выведем контейнер в консоль
    for (int i{ 0 }; i<array.getLength(); ++i)
    cout << array[i] << ' ';

    cout << '\n';

    return 0;
}
