#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <sstream>

float course = 1.0f;
std::string currency1 = "NG", currency2 = "NG";
const std::string path = std::filesystem::current_path().string() + "\\data.txt";
const char delimeter = ' ';

void setup();

void change_course();

void change_currency();

void convert();

void rewrite_file();

std::string get_currency_from_user();

bool contains_only_letters(std::string s);

long get_user_value();

short get_user_choice();

int main() {
    setup();
    while (true) {
        short option;
        std::cout << "Current course: " << "1 " << currency1 << " = " << course << ' ' << currency2 << ".\n"
                  << " | 1.Change course.\n"
                  << " | 2.Change currency.\n"
                  << " | 3.Convert.\n"
                  << " | 4.Quit.\n";
        option = get_user_choice();
        switch (option)
        {
            case 1:
                change_course();
                break;
            case 2:
                change_currency();
                break;
            case 3:
                convert();
                break;
            case 4:
                return 0;
            default:
                break;
        }
    }
    return 0;
}

void rewrite_file() {
    std::ofstream fout(path);
    fout << currency1 << delimeter << course << delimeter << currency2;
    fout.close();
}

void setup() {
    if (!std::filesystem::exists(path)) {
        rewrite_file();
    }

    std::ifstream fin;
    fin.open(path);
    if (!fin.is_open()) {
        std::cerr << "Unable to open the file.";
        return;
    }

    fin >> currency1;
    fin >> course;
    fin >> currency2;
    
    fin.close(); // Closing the ifstream
}

void change_course() {
    while (true) {
        std::cout << "Enter new course: ";
        if (std::cin >> course)
            break;
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    rewrite_file();
}

bool contains_only_letters(std::string s) {
    for (char ch : s) {
        if (!(64 < toupper(ch) && toupper(ch) < 91))
            return false;
    }
    return true;
}

std::string get_currency_from_user() {
    std::string currency;
    while (true) {
        std::cout << "Enter new currency: ";
        if (std::cin >> currency && contains_only_letters(currency))
            return currency.substr(0, 3);
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void change_currency() {
    currency1 = get_currency_from_user();
    currency2 = get_currency_from_user();
    rewrite_file();
}

long get_user_value() {
    long value;
    while (true) {
        std::cout << "Enter number: ";
        if (std::cin >> value)
            return value;
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void convert() {
    std::cout << " | How do you want to convert:\n"
              << " | 1. From " << currency1 << " to " << currency2 << ".\n"
              << " | 2. From " << currency2 << " to " << currency1 << ".\n";

    short choice = get_user_choice();
    int number;
    if (choice == 1) {
        number = get_user_value();
        std::cout << number << ' ' << currency1 << " = " << number * course << ' ' << currency2 <<".\n";
    } else if (choice == 2) {
        number = get_user_value();
        std::cout << number << ' ' << currency2 << " = " << number / course << ' ' << currency1 <<".\n";
    }
}

short get_user_choice() {
    short choice;
    while (true) {
        std::cout << "Enter your choice: ";
        if (std::cin >> choice)
            return choice;
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}