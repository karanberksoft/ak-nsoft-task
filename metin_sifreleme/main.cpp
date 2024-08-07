#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

// karan berk kuthan 07.08.2024


std::string readTextFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Dosya açılamadı: " << filename << std::endl;
        return "";
    }

    std::string text, line;
    while (std::getline(file, line)) {
        text += line;
    }
    file.close();
    return text;
}


std::string removeSpaces(const std::string& text) {
    std::string result;
    for (std::string::size_type i = 0; i < text.size(); ++i) {
        if (!std::isspace(static_cast<unsigned char>(text[i]))) {
            result += text[i];
        }
    }
    return result;
}


void printEncryptedMatrix(const std::string& text) {
    int l = text.length();
    int m = std::floor(std::sqrt(l));
    int n = std::ceil(std::sqrt(l));

    while (m * n < l) {
        if (m < n) {
            m++;
        } else {
            n++;
        }
    }

    std::cout << "m: " << m << ", n: " << n << std::endl;

    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int index = i * n + j;
            if (index < l) {
                std::cout << text[index];
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string filename = "metin.txt"; 
    std::string originalText = readTextFromFile(filename);
    
    if (originalText.empty()) {
        return 1; 
    }

    std::string textWithoutSpaces = removeSpaces(originalText);

    printEncryptedMatrix(textWithoutSpaces);

    return 0;
}
