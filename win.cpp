#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
#include <Windows.h>

const int FILE_COUNT = 100;
const int MIN_LENGTH = 10;
const int MAX_LENGTH = 100;
const std::string CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

std::mt19937 randEngine(time(0));

std::string randomString(int length) {
    std::uniform_int_distribution<int> charDist(0, CHARS.size() - 1);
    std::string result;
    for (int i = 0; i < length; i++) {
        result += CHARS[charDist(randEngine)];
    }
    return result;
}

int main() {
    std::uniform_int_distribution<int> lengthDist(MIN_LENGTH, MAX_LENGTH);
    for (int i = 0; i < FILE_COUNT; i++) {
        std::string fileName = "." + std::to_string(i) + ".txt";
        std::ofstream file(fileName);
        file << randomString(lengthDist(randEngine));
        file.close();
        SetFileAttributes(fileName.c_str(), FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY);
    }
    return 0;
}
