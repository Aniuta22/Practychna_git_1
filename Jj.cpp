#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

class Osoba {
public:
    Osoba(string ім_я, int вік, string адреса)
        : ім_я(ім_я), вік(вік), адреса(адреса) {}

    string getІм_я() const {
        return ім_я;
    }

    int getВік() const {
        return вік;
    }

    string getАдреса() const {
        return адреса;
    }

private:
    string ім_я;
    int вік;
    string адреса;
};

class СлужбаЗайнятості {
public:
    void додатиОсобу(const Osoba& особа) {
        особи.push_back(особа);
    }

    void вивестиВсіОсоби() const {
        for (const Osoba& особа : особи) {
            cout << "Ім'я: " << особа.getІм_я() << ", Вік: " << особа.getВік() << ", Адреса: " << особа.getАдреса() << endl;
        }
    }

private:
    vector<Osoba> особи;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Створення об'єкта для роботи зі службою зайнятості
    СлужбаЗайнятості службаЗайнятості;

    cout << "Скільки осіб ви хочете додати? ";
    int кількістьОсіб;
    cin >> кількістьОсіб;
    cin.ignore(); // Очистка буфера вводу

    for (int i = 0; i < кількістьОсіб; ++i) {
        cout << "Введіть ім'я: ";
        string ім_я;
        getline(cin, ім_я);

        cout << "Введіть вік: ";
        int вік;
        cin >> вік;
        cin.ignore(); // Очистка буфера вводу

        cout << "Введіть адресу: ";
        string адреса;
        getline(cin, адреса);

        // Додавання особи до служби зайнятості
        службаЗайнятості.додатиОсобу(Osoba(ім_я, вік, адреса));
    }

    // Виведення інформації про всіх осіб
    службаЗайнятості.вивестиВсіОсоби();

    return 0;
}
