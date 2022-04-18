/*
Задание 2
Дан текстовый файл.
Переписать в другой файл все его строки с заменой в них символа 0 на символ 1 и наоборот.
*/

#include <iostream>

#include <fstream>/*ifstream ofstream*/
#include <string.h>

using namespace std;

/**
 *  Открытие нового файла
 *
 * @param name имя файла
 * @return открытый файл
 */
bool openFile(string name, fstream* file) {
    (*file).open(name + ".txt");

    if (!(*file).is_open()) {
        return false;
    }
    return true;
}

/**
 * Копирование текста в другой файл с заменой 1 и 0
 *
 * @param file1 исходный текстовый файл
 * @param file2 записываемый файл
 */
void changeOneToZeroAndZeroToOne(fstream* file1, fstream* file2) {
    char ch;

    //переписывание содержимого файла с заменой 1 на 0 и 0 на 1
    while ((*file1).get(ch)) {
        if(ch == '0') {
            (*file2).put('1');
        } else if (ch == '1') {
            (*file2).put('0');
        } else {
            (*file2).put(ch);
        }
    }
}

int main() {
    system("chcp 1251>nul");

    string name;
    fstream firstFile;
    fstream secondFile;

    cout << "Введите имя первого файла: ";
    cin >> name;

    if(!openFile(name, &firstFile)) {
        cout << "Файл не открылся!";
        return 0;
    }

    cout << "Введите имя второго файла: ";
    cin >> name;

    if(!openFile(name, &secondFile)) {
        cout << "Файл не открылся!";
        return 0;
    }

    changeOneToZeroAndZeroToOne(&firstFile, &secondFile);

    firstFile.close();
    secondFile.close();

    return 0;
}
