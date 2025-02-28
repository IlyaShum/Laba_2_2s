#include <iostream>
#include <unordered_map>
#include <algorithm> // для max

using namespace std;

int lengthOfLongestSubstring(const string& s) {
    unordered_map<char, int> lastSeen; // Хранит последний индекс каждого символа
    int maxLength = 0; // Максимальная длина подстроки
    int left = 0; // Левый указатель окна

    for (int right = 0; right < s.size(); ++right) {
        char currentChar = s[right];

        // Если символ уже встречался в текущем окне, сдвигаем левый указатель
        if (lastSeen.find(currentChar) != lastSeen.end() && lastSeen[currentChar] >= left) {
            left = lastSeen[currentChar] + 1;
        }

        // Обновляем последний индекс символа
        lastSeen[currentChar] = right;

        // Обновляем максимальную длину
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    string s;
    cout << "Введите строку: ";
    cin >> s;

    int result = lengthOfLongestSubstring(s);
    cout << "Максимальная длина подстроки без повторяющихся символов: " << result << endl;

    return 0;
}

