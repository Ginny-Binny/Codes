#include <iostream>
#include <vector>

std::vector<std::vector<char>> createMatrix(int m, int n, const std::vector<char>& targets, const std::vector<int>& columnIndices, const std::vector<int>& rowPointers) {
    // Create an empty matrix filled with 'z' characters
    std::vector<std::vector<char>> matrix(m, std::vector<char>(n, 'z'));

    // Iterate through rowPointers to populate the matrix
    for (int row = 0; row < m; ++row) {
        int start_index = rowPointers[row];
        int end_index = rowPointers[row + 1];

        for (int i = start_index; i < end_index; ++i) {
            int column = columnIndices[i];
            char target = targets[i];
            matrix[row][column] = target;
        }
    }

    return matrix;
}