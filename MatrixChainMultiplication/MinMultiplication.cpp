#include <iostream>
#include <vector>

int minimumNumberOfMultiplications(std::vector<int>& dimVec, int start, int end) {

  if (start >= end)
    return 0; // Cost is 0 (neuter element for addition) when this is an invalid range

  int minFound = std::numeric_limits<int>::max(); // The minimum cost found

  // Place a parenthesis break from 0 to k. E.g.
  // 2 4 3 7 with k = 1 means "Break from 0 to k including the element at k"
  // -> (2 4) 3 7
  // -> (2x4) 4x3 3x7
  for (int k = start; k < end; ++k) {
    // Every sub-parenthesized expression must yield a matrix of dimensions
    // dimVec[start] x dimVec[k].
    // We take advantage of this fact to "merge" the results of the recursions:
    // ( 2x4 4x3 ) (3x7)
    // ^^^^^^^^^^^
    // This yields a 2x3 matrix. The other parenthesis yields a 3x7 matrix.
    // The above can be written as
    //  minimumNumberOfMultiplications( (2x4 4x3) ) +
    //  minimumNumberOfMultiplications( (3x7 ) +
    //  merge price of a 2x3 x 3x7 matrix join -> 2*3*7 operations
    int newMin = minimumNumberOfMultiplications(dimVec, start, k) +
                 minimumNumberOfMultiplications(dimVec, k + 1, end) +
                 dimVec[start - 1] * dimVec[k] * dimVec[end];

    if (newMin < minFound)
      minFound = newMin;
  }

  return minFound;
}

int main() {
  std::vector<int> matrixDimensions = { 2, 4, 3, 7 }; // Three matrices: 2x4, 4x3, 3x7

  std::cout << "Minimum number of multiplications for the input sized matrices is "
            << minimumNumberOfMultiplications(matrixDimensions, 1,
                static_cast<int>(matrixDimensions.size() - 1)); // 66

  return 0;
}
