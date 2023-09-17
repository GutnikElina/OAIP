/*Создать хеш-таблицу со случайными целыми ключами и найти запись
с максимальным ключом. */

/*кол-во четных нечетных и нулей*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>

// Количество элементов в хеш-таблице
const int number_of_elements = 10;

struct Entry 
{
    int key;
    int value;
    Entry* next;
};

int hash_function(int key) 
{
    return key % number_of_elements;
}

int main() 
{
    setlocale(0, "rus");
    std::srand(std::time(nullptr));  
    int kol_chet = 0;
    int kol_nechet = 0;
    int kol_nul = 0;
    int numb;

    // Создаем хеш-таблицу в виде массива списков
    Entry** hash_table = new Entry * [number_of_elements];

    for (int i = 0; i < number_of_elements; ++i) 
    {
        hash_table[i] = nullptr;
    }

    for (int i = 0; i < 10; ++i) 
    {
        int key = std::rand() % 100; 
        int value = std::rand() % 10; 

        std::cout << "Ключ - " << key << "   Значение - " << value << std::endl;

        int index = hash_function(key);  
        numb = index;

        if (numb % 2 == 0)
        {
            kol_chet++;
        }
        else
        {
            kol_nechet++;
        }

        if (numb == 0)
        {
            kol_nul++;
        }


        Entry* new_entry = new Entry{ key, value, hash_table[index] };
        hash_table[index] = new_entry;   
    }

    int max_key = 0;
    int max_value = 0;
    for (int i = 0; i < number_of_elements; ++i) 
    {
        Entry* current = hash_table[i];
        while (current != nullptr) 
        {
            if (current->key > max_key)
            {
                max_key = current->key;
                max_value = current->value;
            }
            current = current->next;
        }
    }

    std::cout << std::endl <<"Кол-во нечетных - " << kol_nechet << "   Кол-во четных - " << kol_chet << "   Кол-во нулей - " << kol_nul << std::endl;

    std::cout << std::endl << "Запись с максимальным ключом: {" << max_key << ", " << max_value << "}" << std::endl;

    for (int i = 0; i < number_of_elements; ++i) 
    {
        Entry* current = hash_table[i];
        while (current != nullptr) {
            Entry* next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] hash_table;

    return 0;
}