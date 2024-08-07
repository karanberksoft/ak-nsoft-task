#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

// karan berk kuthan 07.08.2024

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 20);

    std::vector<int> visited_points;
    int current_position = 0;

    for (int i = 0; i < 10; ++i) {
        int new_position;
        do {
            new_position = dis(gen);
        } while (std::abs(new_position - current_position) < 5 || 
                 std::find(visited_points.begin(), visited_points.end(), new_position) != visited_points.end());

        visited_points.push_back(new_position);
        current_position = new_position;
    }
    
    std::cout << "Mini Ada'nin gezinti haritasi: ";
    for (int point : visited_points) {
        std::cout << point << " ";
    }
    std::cout << std::endl;

    return 0;
}
