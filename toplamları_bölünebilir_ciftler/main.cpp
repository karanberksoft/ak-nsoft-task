#include <iostream>
#include <vector>
#include <random>

// karan berk kuthan 07.08.2024


std::vector<int> generateRandomArray(int n, int min = -1000, int max = 1000) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    std::vector<int> array(n);
    for (int &num : array) {
        num = dis(gen);
    }
    return array;
}


void findDivisiblePairs(const std::vector<int>& arr, int k) {
    bool found = false;
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if ((arr[i] + arr[j]) % k == 0) {
                std::cout << "(" << i << ", " << j << ")\n";
                found = true;
            }
        }
    }
    if (!found) {
        std::cout << "Uygun çift bulunamadı.\n";
    }
}

int main() {
    int n, k;

    
    do {
        std::cout << "Dizinin uzunluğunu girin (2 < n < 1000): ";
        std::cin >> n;
        if (n <= 2 || n >= 1000) {
            std::cout << "Geçersiz uzunluk. Lütfen 2 ile 1000 arasında bir değer girin.\n";
        }
    } while (n <= 2 || n >= 1000);

    
    do {
        std::cout << "Çiftlerin toplamlarının tam bölüneceği pozitif tam sayıyı girin (1 < k < 100): ";
        std::cin >> k;
        if (k <= 1 || k >= 100) {
            std::cout << "Geçersiz k değeri. Lütfen 1 ile 100 arasında bir değer girin.\n";
        }
    } while (k <= 1 || k >= 100);

    
    std::vector<int> array = generateRandomArray(n);

    
    std::cout << "Rastgele oluşturulan dizi: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    
    findDivisiblePairs(array, k);

    return 0;
}
