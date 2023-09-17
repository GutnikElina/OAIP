/*Cоздать стек для символов. Максимальный элемент стека вводится с экрана. Создать функции для ввода и вывода 
элементов стека. Добавить символы с экрана в стек. После добавления 5 - го символа перед добавлением удалять 
элемент из списка */

#include <iostream>
#include<locale>
#include <string>
#include<stdlib.h>
using namespace std;

const int MAX_SIZE = 5;
int check(string ch);
int continue_or_not();

struct Stack
{
    int symbol{};
    Stack* next{};
};

void push(Stack* &stackPtr, int c)
{
    Stack* newNode = new Stack;
    if (newNode != nullptr)
    {
        newNode->symbol = c;
        newNode->next = stackPtr;
        stackPtr=newNode;
    }
}

void pop(Stack*& stackPtr)
{
    if (stackPtr == nullptr)
    {
        cout << "Стек пуст!" << endl;
    }
    else
    {
        Stack* temp = stackPtr;
        stackPtr = stackPtr->next;
        delete temp;
    }
}

void display(Stack* stackPtr)
{
    Stack* current = stackPtr;
    while (current != nullptr) 
    {
        cout << current->symbol << endl;
        current = current->next;
    }
}

void deleteSteck(Stack*& stackPtr)
{
    Stack* temp;
    while (stackPtr != nullptr)
    {
        temp = stackPtr;
        stackPtr = stackPtr->next;
        delete temp;
    }
}

int main() 
{
    setlocale(0, "rus");
    Stack* stackPtr = nullptr;
    int choice{};

    do
    {
        int maxChar;
        string line;
        int symbol{};
        int j = 0;
        int count = 0;
        
        do
        {
            cout << "Введите максимальное количество элементов стека: " << endl;
            cin >> line;
            maxChar = check(line);
        } while (maxChar==999);

        for (int i = 0; i < maxChar; i++)
        {
            cout << endl << "Введите " << i + 1 << "-й символ: ";
            cin >> symbol;
            j++;

            if (j == MAX_SIZE + 1)
            {
                pop(stackPtr);
                j--;
            }
            push(stackPtr, symbol);
            if (stackPtr->symbol % 2 != 0)
            {
                count++;
            }
            display(stackPtr);
        }


        cout << "Количество нечетных элементов: " << count << endl;
        choice = continue_or_not();
    } while (choice);
    
    return 0;
}

int check(string ch)
{
    int chislo = 0;
    bool isbreak = false;
    char line[30]{};
    for (int i = 0; i < ch.length(); i++)
    {
        if ((ch[i] < 48 || ch[i]>57) && ch[i] != 43)
            isbreak = true;
    }
    if (isbreak)
    {
        cout << "\n-!!!- Введенные данные неверны. Попробуйте снова -!!!-\n\n";
        chislo = 999;
        return chislo;
    }
    else
    {
        for (int i = 0; i < ch.length(); i++)
        {
            line[i] = ch[i];
        }
        chislo = atoi(line);
    }
    return chislo;
}

int continue_or_not()
{
    int exit = 1;
    int ch;
    int MAX;
    char line[20]{};
    do
    {
        cout << "----------------------------------------------------" << endl;
        cout << "|                Хотите продолжить?                |" << endl;
        cout << "|    Если да, нажмите - 1; если нет, нажмите - 0.  |" << endl;
        cout << "----------------------------------------------------" << endl;
        cin >> line;
        MAX = strlen(line);
        ch = check(line);
        if (ch != 999)
        {
            if (MAX == 1 && line[0] == '1')
                return 1;
            else if (MAX == 1 && line[0] == '0')
                return 0;
        }
    } while (exit);
    return 0;
}
