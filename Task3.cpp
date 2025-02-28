#include <iostream>
#include <set>

using namespace std;

// Функция для вывода элементов множества
void printSet(const set<int>& s) {
    for (const auto& element : s) {
        cout << element << " ";
    }
    cout << endl;
}

// Функция для объединения двух множеств
set<int> unionSets(const set<int>& set1, const set<int>& set2) {
    set<int> result = set1;  // Копируем первое множество в результат
    result.insert(set2.begin(), set2.end());  // Добавляем элементы второго множества
    return result;
}

// Функция для пересечения двух множеств
set<int> intersectSets(const set<int>& set1, const set<int>& set2) {
    set<int> result;
    for (const auto& element : set1) {
        if (set2.find(element) != set2.end()) {  // Если элемент найден во втором множестве
            result.insert(element);  // Добавляем его в результат
        }
    }
    return result;
}

// Функция для разности двух множеств (set1 - set2)
set<int> differenceSets(const set<int>& set1, const set<int>& set2) {
    set<int> result = set1;  // Копируем первое множество в результат
    for (const auto& element : set2) {
        result.erase(element);  // Удаляем элементы, которые есть во втором множестве
    }
    return result;
}

// Функция для ввода множества с клавиатуры
set<int> inputSet(const string& setName) {
    set<int> s;
    int n, value;
    cout << "Введите количество элементов множества " << setName << ": ";
    cin >> n;
    cout << "Введите элементы множества " << setName << " (через пробел): ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        s.insert(value);  // Добавляем элемент в множество
    }
    return s;
}

int main() {
    setlocale(LC_ALL, "ru");
    // Ввод множеств с клавиатуры
    set<int> set1 = inputSet("Set1");
    set<int> set2 = inputSet("Set2");

    // Выводим исходные множества
    cout << "Set 1: ";
    printSet(set1);
    cout << "Set 2: ";
    printSet(set2);

    // Объединение множеств
    set<int> unionResult = unionSets(set1, set2);
    cout << "Объединение: ";
    printSet(unionResult);

    // Пересечение множеств
    set<int> intersectResult = intersectSets(set1, set2);
    cout << "Пересечение: ";
    printSet(intersectResult);

    // Разность множеств (set1 - set2)
    set<int> differenceResult = differenceSets(set1, set2);
    cout << "Разность(Set1 - Set2): ";
    printSet(differenceResult);

    return 0;
}

