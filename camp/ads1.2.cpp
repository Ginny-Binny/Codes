#include <iostream>
#include <vector>
#include <algorithm>

bool checkCharacter(const std::vector<char>& characterList, char targetCharacter) {
    auto it = std::find(characterList.begin(), characterList.end(), targetCharacter);
    return it != characterList.end();
}

int main() {
    std::vector<char> characters = {'a', 'c', 'e', 'g', 'i', 'k'};
    char target;

    std::cout << "Enter the character to search: ";
    std::cin >> target;

    bool result = checkCharacter(characters, target);

    if (result) {
        std::cout << "Character found in the list." << std::endl;
    } else {
        std::cout << "Character not found in the list." << std::endl;
    }

    return 0;
}
