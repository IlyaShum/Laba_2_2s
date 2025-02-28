#include <iostream>
#include <string>

using namespace std;
// Функция для проверки соответствия строки шаблону
bool isMatch(const string& str, const string& pattern) {
    // Если шаблон закончился, строка тоже должна закончиться
    if (pattern.empty()) {
        return str.empty();
    }

    // Если текущий символ шаблона '*'
    if (pattern[0] == '*') {
        // Пропускаем '*' и проверяем, соответствует ли оставшаяся строка шаблону
        // или пропускаем один символ строки и продолжаем проверку
        return (!str.empty() && isMatch(str.substr(1), pattern) || isMatch(str, pattern.substr(1)));
    }

    // Если текущий символ шаблона '?' или совпадает с текущим символом строки
    if (!str.empty() && (pattern[0] == '?' || pattern[0] == str[0])) {
        return isMatch(str.substr(1), pattern.substr(1));
    }

    // Если ни одно из условий не выполнено, строки не соответствуют
    return false;
}

int main() {
    string str, pattern;

    // Ввод строки и шаблона от пользователя
    cout << "Введите строку: ";
    getline(cin, str);
    cout << "Введите шаблон: ";
    getline(cin, pattern);

    // Проверка соответствия
    if (isMatch(str, pattern)) {
        cout << "Строка соответствует шаблону." << endl;
    } else {
        cout << "Строка НЕ соответствует шаблону." << endl;
    }

    return 0;
}

