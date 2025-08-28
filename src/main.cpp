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

int main() {
    setup();
    std::cout << "1 " << currency1 << " = " << course << " " << currency2 << '\n';
    change_course();
    change_currency();
    std::cout << "1 " << currency1 << " = " << course << " " << currency2 << '\n';
    getchar();
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