#include <iostream>
#include <vector>
#include <limits>

int minimumNumberOfMultiplications(std::vector<int>& dimVec) {

  // A memoization matrix of NxN
  const size_t N = dimVec.size();
  std::vector<std::vector<int>> matrix(N, std::vector<int>(N, 0));

  // Base cases: 1-length subexpressions
  // Code is unnecessary (included in the zero-initialization above)
  // for (int i = 0; i < N; ++i) {
  //  matrix[i][i] = 0;
  // }

  // For every subexpression length
  for (int l = 2; l <= N - 1 /* First element is not a real element */; ++l) {
    for (int i = 1; i <= N - l; ++i) { // For every beginning i
      int j = i + l - 1; // And get the subexpression ending too

      int minFound = std::numeric_limits<int>::max();
      for (int k = i; k < j; ++k) {

        int newMin = matrix[i][k] + matrix[k + 1][j] +
                     dimVec[i - 1] * dimVec[k] * dimVec[j]; // See quote

        if (newMin < minFound)
          minFound = newMin;
      }

      matrix[i][j] = minFound; // Store the minimum obtained for this interval
    }
  }

  return matrix[1][N - 1];
}

int main() {
  std::vector<int> matrixDimensions = { 2, 4, 3, 7 }; // Three matrices: 2x4, 4x3, 3x7

  std::cout << "Minimum number of multiplications for the input sized matrices is "
            << minimumNumberOfMultiplications(matrixDimensions); // 66

  return 0;
}
