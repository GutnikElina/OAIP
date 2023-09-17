/*создать очередь для символов. максимальный размер очереди вводится с экрана. 
создать функции для ввода и вывода элементов очереди. вводить символы с экрана в очередь. 
после введения 3-го символа в ответ на каждый вводимый выводить предыдущий символ*/

#include <iostream>
#include<locale>
#include <string>
#include<stdlib.h>
using namespace std;


struct Queue
{
    string symbol{};
    Queue* next{};
};

const int MAX_SIZE = 3;
int check(string ch);
int continue_or_not();
void create_och(Queue*& begin, Queue*& end, string symbol);
void deleteQueue(Queue*& QueuePtr);
string lastSymbol(Queue* begin, Queue* end, int i);
pair<int, int> count(Queue* begin);


int main()
{
    setlocale(0, "rus");
    Queue* begin = nullptr, *end = nullptr;
    int choice;

    do
    {
        int maxChar{};
        string line{};
        string symbol{};

        do
        {
            cout << "--------Введите максимальный размер очереди--------" << endl;
            cin >> line;
            maxChar = check(line);
        } while (maxChar == 999);

        for (int i = 0; i < maxChar; i++)
        {
            cout << endl << "Введите " << i + 1 << "-й символ: ";
            cin >> symbol;
            create_och(begin, end, symbol);

            if (i > MAX_SIZE - 1)
            {
                cout << lastSymbol(begin, end, i);
            }
        }

        pair<int, int> number = count(begin);
        cout << endl << "Количество четных элементов: " << number.first;
        cout << endl << "Количество нечетных элементов: " << number.second;

        cout << endl;
        choice = continue_or_not();
        deleteQueue(begin);
        system("cls");
    } while (choice);

    return 0;
}

pair<int, int> count(Queue* begin)
{
    int chet = 0;
    int nechet = 0;
    Queue* current = begin;

    while (current != nullptr)
    {
        int value = stoi(current->symbol);
        if (value % 2 == 0)
            chet++;
        else
            nechet++;

        current = current->next;
    }

    return make_pair(chet, nechet);
}

void create_och(Queue*& begin, Queue*& end, string symbol)
{
    Queue* QueuePtr = new Queue;
    QueuePtr->next = nullptr;
    
    if (begin == nullptr)
    {
        begin = end = QueuePtr;
        QueuePtr->symbol = symbol;
    }
    else
    {
        QueuePtr->symbol = symbol;
        end->next = QueuePtr;
        end = QueuePtr;
    }
}

string lastSymbol(Queue* begin, Queue* end, int i)
{
    Queue* current = begin;
    int j = 0;
    while (current != nullptr)
    {
        if (j == i - 1)
        {
            return current->symbol;
        }
        j++;
        current = current->next;
    }
}

void deleteQueue(Queue*& begin)
{
    Queue* temp;
    while (begin != nullptr)
    {
        temp = begin;
        begin = begin ->next;
        delete temp;
    }
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
