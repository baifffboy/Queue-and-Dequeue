#include <iostream>
#include "Queue.cpp"
#include "Dequeue.cpp"
#include "Stack.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Тесты методов очереди:" << endl;

    Queue<int> t; // инициализация
    for (size_t i = 0; i < 5; i++) { t.Push(i * 10); } // метод Push() там же и метод isEmpty()
    cout << "Метод Front(): " << t.Front() << endl; // метод Front()
    cout << "Метод Back(): " << t.Back() << endl; // метод Back()
    cout << "Метод size(): " << t.size() << endl; // метод size()
    
    t.Pop(); // удаляет 0
    cout << "Метод Pop(): " << t.Pop() << endl; // метод Pop() - должен вернуть 10
    //Queue<int> n;
    //for (size_t i = 0; i < 5; i++) { t.Push(i * 10); }
    //n.swap_(t);
    //cout << n.Front() << endl;
    //cout << t.Front() << endl;
    cout << " \n" << endl;
    

    cout << "Тесты методов двухсторонней очереди:" << endl;
    Dequeue<int> f; // инициализация
    cout << "Метод isEmpty(): " << std::boolalpha << f.isEmpty() << endl; // true
    for (int m = 0; m < 6; m++) { 
        f.PushFront(m * 10); 
    } 
    for (int a = 0; a < 4; a++) { 
        f.PushBack(a * 10); 
    }
    cout << "Метод Back(): " << f.Back() << endl; // 30
    cout << "Метод Front(): " << f.Front() << endl; // 50
    cout << "Метод PopBack(): " << f.PopBack() << endl; // 30
    cout << "Метод PopFront(): " << f.PopFront() << endl; // 50
    cout << "Метод Back(): " << f.Back() << endl; // 20
    cout << "Метод Front(): " << f.Front() << endl; // 40
    cout << "Метод size(): " << f.size() << endl; // 10-2=8
    cout << "Метод isEmpty(): " << std::boolalpha << f.isEmpty() << endl; // false
    f.insert(3, 2); // вставляет по индексу 3 значение 2
    f.insert(8, 100); // вставляет по индексу 8 значение 100
    cout << "Метод Back(): " << f.Back() << endl; // 100
    return 0;
}

