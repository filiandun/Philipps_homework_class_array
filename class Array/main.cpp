#include <iostream>
#include "array.h"

int main()
{
    setlocale(LC_ALL, "rus");



// ФУНКЦИЯ ADD (РАБОТАЕТ)
    std::cout << "ФУНКЦИЯ ADD: " << std::endl;

    Array<int> array;
    std::cout << "Пуст ли массив (да): " << array.is_empty() << std::endl << std::endl;

    array.add(22); std::cout << "Добавлено 22" << std::endl;
    array.add(404); std::cout << "Добавлено 404" << std::endl;
    array.add(1); std::cout << "Добавлено 1" << std::endl;
    array.add(19); std::cout << "Добавлено 19" << std::endl << std::endl;

    std::cout << "ARRAY: "; array.print(); std::cout << std::endl;

    std::cout << "Пуст ли массив (нет): " << array.is_empty() << std::endl << std::endl << std::endl;



// ФУНКЦИЯ GET (РАБОТАЕТ, НО НЕТ TRY)
    std::cout << "ФУНКЦИЯ GET: " << std::endl;

    std::cout << "ARRAY: "; array.print();
    std::cout << "Элемент под номером 2: " << array.get_at(2) << std::endl << std::endl << std::endl;



// ФУНКЦИЯ SET (РАБОТАЕТ, НО НЕТ TRY)
    std::cout << "ФУНКЦИЯ SET: " << std::endl;

    std::cout << "ARRAY ДО: "; array.print();
    array.set_at(2, 777);
    std::cout << "ARRAY ПОСЛЕ: "; array.print(); std::cout << std::endl << std::endl;



// ФУНКЦИЯ GET_DATA (РАБОТАЕТ)
    std::cout << "ФУНКЦИЯ GET_DATA: " << std::endl;
    std::cout << "АДРЕС ARRAY: " << array.get_data() << std::endl << std::endl << std::endl;



// ФУНКЦИЯ APPEND (РАБОТАЕТ, НО НЕТ TRY)
    std::cout << "ФУНКЦИЯ APPEND: " << std::endl;

    Array<int> array_1 = array;
    Array<int> array_2 = array;

    std::cout << "ARRAY_1 ДО: "; array_1.print();
    std::cout << "ARRAY_2 ДО: "; array_2.print(); std::cout << std::endl;

    array_1.append(array_2);
    std::cout << "ARRAY_1 ПОСЛЕ: "; array_1.print();
    std::cout << "ARRAY_2 ПОСЛЕ: "; array_2.print(); std::cout << std::endl << std::endl;











// ФУНКЦИЯ REMOVE_ALL
    //std::cout << "ФУНКЦИЯ REMOVE_ALL: " << std::endl;

    //std::cout << "ARRAY ДО: "; array.print();
    //array.remove_all();
    //std::cout << "ARRAY ПОСЛЕ: "; array.print(); std::cout << std::endl;


    return 0;
}


// НЕ ЗАБЫТЬ ИСПРАВИТЬ В QUEUE if (array.begin_node == nullptr && /////this->end_node///// == nullptr) И
// И ПЕРЕМЕНОВАТЬ Array addition_array = *this; 



/*
* 1. ПРОПИСАТЬ ВЕЗДЕ TRY, THROW, CATCH
* 2. РЕАЛИЗОВАТЬ SIZE
* 
* 
* 



*/