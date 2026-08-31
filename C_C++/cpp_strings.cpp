#include <iostream>
#include <string>

int main() {
    std::string sentence = "Manners maketh man";
    std::string word = "man";
    
    // Find the substring "man"
    size_t index = sentence.find(word); 
    
    // Always check against std::string::npos to verify success
    if (index != std::string::npos) {
        std::cout << "Found at index: " << index << std::endl; // Outputs 15
    }
}