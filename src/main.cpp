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

int main() {
    setup();
    std::cout << "1 " << currency1 << " = " << course << " " << currency2 << '\n';
    change_course();
    std::cout << "1 " << currency1 << " = " << course << " " << currency2 << '\n';
    getchar();
    return 0;
}

void setup() {
    if (!std::filesystem::exists(path)) {
        std::ofstream fout;
        fout.open(path);
        fout << currency1 << ' ' << course << ' ' << currency2;
        fout.close();
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
    std::ofstream fout(path);
    fout << currency1 << delimeter << course << delimeter << currency2;
    fout.close();
}