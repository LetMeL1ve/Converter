#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>

float course;
std::string currency1, currency2;
const std::string path = std::filesystem::current_path().string() + "\\data.txt";
const char delimeter = '/';

void setup();

void change_course();

int main() {
    setup();
    change_course();
    return 0;
}

void setup() {
    std::ifstream fin;
    fin.open(path);
    if (!fin.is_open()) 
        std::cerr << "Unable to open the file.";

    std::string temp;

    getline(fin, temp, delimeter);
    currency1 = temp;

    getline(fin, temp, delimeter);
    course = std::stof(temp);
    
    getline(fin, temp, delimeter);
    currency2 = temp;

    fin.close(); // Closing the ifstream
}

void change_course() {
    std::cout << "Current course: " << course << ".\nEnter new course:";
    float new_course = 0;

    // Getting new course
    while (true) {
        if (std::cin >> new_course)
            break;
        else {
            std::cout << "Please try again.";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    course = new_course;

    // Saving new course to the file
    std::ofstream fout;
    fout.open(path);
    fout << currency1 << delimeter << course << delimeter << currency2;
    fout.close();
}