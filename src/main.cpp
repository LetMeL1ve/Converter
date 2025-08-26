#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>

float course;
std::string currency1, currency2;
const std::string path = std::filesystem::current_path().string() + "\\data.txt";

void setup();

int main() {
    setup();
    std::cout << currency1 << " - " << course << " - " << currency2;
    return 0;
}

void setup() {
    std::ifstream fin;
    fin.open(path);

    std::string line;
    getline(fin, line); // Getting data

    currency1 = line.substr(0, 3);
    course = std::stof(line.substr(4, 8));
    currency2 = line.substr(9, 12);

    fin.close(); // Closing the ifstream
}