
#include <bits/stdc++.h>
using namespace std;
int main() {
    Map<int, int> myMap;

    // Test Case 1: Insert and access elements using operator[]
    std::cout << "Test Case 1: Insert and Access Elements using operator[]\n";
    myMap[0] = 10;  // Insert (0, 10)
    myMap[1] = 20;  // Insert (1, 20)

    std::cout << "myMap[0]: " << myMap[0] << std::endl;  // Output: 10
    std::cout << "myMap[1]: " << myMap[1] << std::endl;  // Output: 20
    std::cout << "-----------------------------------\n";

    // Test Case 2: Access elements using the get method
    std::cout << "Test Case 2: Access Elements using get Method\n";
    try {
        std::cout << "Get myMap[0]: " << myMap.get(0) << std::endl;  // Output: 10
        std::cout << "Get myMap[1]: " << myMap.get(1) << std::endl;  // Output: 20
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------------\n";

    // Test Case 3: Update existing element using operator[]
    std::cout << "Test Case 3: Update Existing Element\n";
    myMap[0] = 100;  // Update (0, 100)
    std::cout << "Updated myMap[0]: " << myMap[0] << std::endl;  // Output: 100
    std::cout << "-----------------------------------\n";

    // Test Case 4: Clear map
    std::cout << "Test Case 4: Clear Map\n";
    myMap.clear();
    try {
        std::cout << "Get myMap[0] after clear: " << myMap.get(0) << std::endl;  // Should throw error
    } catch (const std::runtime_error& e) {
        std::cout << "Error after clear: " << e.what() << std::endl;  // Expected error
    }
    std::cout << "-----------------------------------\n";

    return 0;
}