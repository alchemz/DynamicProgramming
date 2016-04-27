#include <iostream>
#include <vector>
#include <iterator>

int main() {

  std::vector<std::vector<int>> matrix1 = { // 2 x 4
    { 1, 2, 3, 4 },
    { 5, 6, 7, 8 }
  };

  std::vector<std::vector<int>> matrix2 = { // 4 x 3
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 },
    { 10, 11, 12 }
  };

  const size_t A = matrix1.size();
  const size_t B = matrix2.size(); // Matrices must have this dimension in common
  const size_t C = matrix2[0].size();

  // matrix1 is A x B
  // matrix2 is B x C

  // Matrix multiplication. The resulting matrix is
  // (A x B) x (A x C) = A x C
  std::vector<std::vector<int>> result(A, std::vector<int>(C, 0));

  for (size_t a = 0; a < A; ++a) {
    for (size_t c = 0; c < C; ++c) {
      for (size_t b = 0; b < B; ++b) {
        result[a][c] += matrix1[a][b] * matrix2[b][c];
      }
    }
  }

  // Print out resulting matrix
  for (auto& v : result) {
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
  }

  return 0;
}
