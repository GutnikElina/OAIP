#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <Windows.h>

using namespace std;

/*1 1342089 Иванов Иван Иванович
2 3265576 Гутник Элина Андреевна
3 8247480 Медведев Мстислав Робертович
4 2112447 Богданов Владимир Генадьевич
5 5293513 Лобанова Елена Витальевна
6 3025431 Котова Арина Натановна
7 8692541 Соловьёва Лана Артемовна
8 8617218 Денисов Евгений Максимович*/


struct Node 
{
    int key{};
    string surname{};
    string name{};
    string otch{};
    Node* left{};
    Node* right{};
};

int checkInt();
void save(int size, int pasport, string surname, string name, string otch);
void print(Node* root, int level, int& count);
void printNode(Node* node);
void countNodesAtEachLevel(Node* root, int level, int& count);

void menu()
{
    cout << endl << "---------------------МЕНЮ---------------------" << endl;
    cout << "| 1. Добавить новую запись                   |" << endl;
    cout << "| 2. Поиск записи                            |" << endl;
    cout << "| 3. Удалить запись                          |" << endl;
    cout << "| 4. Вывести записи                          |" << endl;
    cout << "| 5. Определить число узлов на каждом уровне |" << endl;
    cout << "| 6. Вывести как дерево                      |" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "\t\tВАШ ВЫБОР" << endl;
}

// Функция для создания нового узла дерева
Node* createNode(int key, string surname, string name, string otch)
{
    Node* newNode = new Node;
    newNode->key = key;
    newNode->surname = surname;
    newNode->name = name;
    newNode->otch = otch;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Функция для добавления нового узла в дерево
void insert(Node*& root, int key, string surname, string name, string otch)
{
    if (root == nullptr) 
    {
        root = createNode(key, surname, name, otch);
        return;
    }

    if (key < root->key) 
    {
        insert(root->left, key, surname, name, otch);
    }
    else 
    {
        insert(root->right, key, surname, name, otch);
    }
}

// Функция для поиска узла в дереве
Node* search(Node* root, int key) 
{
    if (root == nullptr || root->key == key) 
    {
        return root;
    }

    if (key < root->key) 
    {
        return search(root->left, key);
    }
    else 
    {
        return search(root->right, key);
    }
}

// Функция для удаления узла из дерева
Node* remove(Node* root, int key) 
{
    if (root == nullptr) 
    {
        return root;
    }

    if (key < root->key) 
    {
        root->left = remove(root->left, key);
    }
    else if (key > root->key) 
    {
        root->right = remove(root->right, key);
    }
    else {
        if (root->left == nullptr) 
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) 
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = root->right;
        while (temp->left != nullptr) 
        {
            temp = temp->left;
        }

        root->key = temp->key;
        root->surname = temp->surname;
        root->name = temp->name;
        root->otch = temp->otch;
        root->right = remove(root->right, temp->key);
    }
    return root;
}

// Функция для вывода информации об узле
void printNode(Node* node) 
{
    cout << "Номер паспорта: " << node->key << endl << "ФИО: " << node->surname << " " << 
        node->name << " " << node->otch << endl << endl;
}

// Функция для вывода информации обо всех узлах дерева
void printTree(Node* root) 
{
    if (root != nullptr) {
        printTree(root->left);
        printNode(root);
        printTree(root->right);
    }
}

void printKey(Node* node, int )
{
    cout << node->key << endl;
}

//функция для вывода дерева
void print(Node* root, int level, int& count)
{
    if (root == nullptr)
    {
        return;
    }

    if (level == 0)
    {
        count++;
    }
    else
    {
        countNodesAtEachLevel(root->left, level - 1, count);
        countNodesAtEachLevel(root->right, level - 1, count);
    }

    if (root != nullptr) 
    {
        print(root->right, level+1, count);
        for (int i = 0; i < level; i++) 
        {
            cout << "   ";
        }
        cout << root->key << endl;
        print(root->left, level+1, count);
    }
}

void printTreePassports(Node* root, int level = 0) 
{
    if (root == nullptr) 
    {
        return;
    }

    const int indentSize = 4;  

    printTreePassports(root->right, level + 1);

    for (int i = 0; i < level * indentSize; i++) 
    {
        cout << " ";
    }

    cout << root->key << endl;
    printTreePassports(root->left, level + 1);
}

// Функция для определения числа узлов на каждом уровне дерева
void countNodesAtEachLevel(Node* root, int level, int& count) 
{
    if (root == nullptr) 
    {
        return;
    }

    if (level == 0) 
    {
        count++;
    }
    else 
    {
        countNodesAtEachLevel(root->left, level - 1, count);
        countNodesAtEachLevel(root->right, level - 1, count);
    }
}

    // Функция для освобождения памяти, занятой деревом
void freeTree(Node*& root)
{
    if (root != nullptr) 
    {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
        root = nullptr;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* root = nullptr;
    
    ifstream file("derevo.txt", ios::in);
    if (!file.is_open()) 
    {
        cout << "-!!!- ОШИБКА ПРИ ОТКРЫТИИ ФАЙЛА -!!!-" << endl;
        return 1;
    }

    int pasport, numberOfPasport, size;
    string surname, name, otch;
    bool flag = true;

    while (file >> size >> pasport >> surname >> name >> otch)
    {
        insert(root, pasport, surname, name, otch);
    }
    file.close();

    while (flag)
    {
        menu();

        int choice = checkInt();

        switch (choice)
        {
        case 1:
        {
            cout << endl << " ------------ Добавление новой записи ------------ ";
            cout << endl << "Введите номер паспарта: " << endl;
            numberOfPasport = checkInt();
            cout << endl << "Введите фамилию: " << endl;
            cin >> surname;
            cout << endl << "Введите имя: " << endl;
            cin >> name;
            cout << endl << "Введите отчество: " << endl;
            cin >> otch;
            insert(root, numberOfPasport, surname, name, otch);
            ++size;
            save(size, numberOfPasport, surname, name, otch);
            cout << endl << " --------- Новая запись успешно добавлена -------- ";
            break;
        }
        case 2:
        {
            cout << endl << " --------------- Поиск информации ---------------- ";
            cout << endl << "Введите номер паспорта: " << endl;
            numberOfPasport = checkInt();
            Node* node = search(root, numberOfPasport);
            if (node != nullptr)
            {
                cout << endl << "Найденная запись: ";
                printNode(node);
            }
            else
            {
                cout << endl << "Запись не найдена!";
            }
            cout << endl << " ------------------------------------------------- " << endl;
            break;
        }
        case 3:
        {
            cout << endl << " ------------- Удаление информации --------------- ";
            cout << endl << "Введите номер паспорта, который хотите удалить: " << endl;
            numberOfPasport = checkInt();
            root = remove(root, numberOfPasport);
            cout << endl << " ------------------------------------------------- " << endl;
            break;
        }
        case 4:
        {
            cout << endl << " -------------- Вывести информацию --------------- " << endl;
            printTree(root);
            cout << " ------------------------------------------------- " << endl;
            break;
        }
        case 5:
        {
            cout << endl << " ------------ Определить число узлов ------------- " << endl;
            for (int i = 0; i < size; i++)
            {
                int count = 0;
                countNodesAtEachLevel(root, i, count);
                if (count!=0)
                cout << "Уровень " << i << ": " << count << " узлов. " << endl;
            }
            cout << endl << " ------------------------------------------------- " << endl;
            break;
        }
        case 6:
        {
            printTreePassports(root, 0);
            break;
        }
        case 7: 
            flag = false;
            break;
        }
    }

    freeTree(root);

    return 0;
}

void save(int size, int pasport, string surname, string name, string otch)
{
    ofstream file("derevo.txt", ios::app);

    file << endl << size << "\t" << pasport << "\t" << surname << "\t" << name << "\t" << otch;
    file.close();
}

int checkInt()
{
    int ch;
    string result;
    while (true)
    {
        bool flag = true;
        ch = _getch();
        if ((ch >= 48 && ch <= 57) || ch == 13 || ch == 8)
        {
            if (ch == 13)
            {
                if (result.size() != 0)
                    break;
            }
            else
                if (ch == 8)
                {
                    cout << (char)8 << ' ' << char(8);
                    if (!result.empty())
                        result.erase(result.length() - 1);
                }
                else
                {
                    cout << (char)ch;
                    result += (char)ch;
                }
        }
    }
    cout << endl;

    return stoi(result);
}
