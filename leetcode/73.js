/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
  const m = matrix.length;
  if (m == 0) {
    return matrix;
  }

  const n = matrix[0].length;
  const zeroCols = new Set();
  const zeroRows = new Set();

  for (let y = 0; y < m; y++) {
    for (let x = 0; x < n; x++) {
      if (matrix[y][x] == 0) {
        zeroCols.add(x);
        zeroRows.add(y);
      }
    }
  }
  for (let y of zeroRows) {
    for (let x = 0; x < n; x++) {
      matrix[y][x] = 0;
    }
  }
  for (let x of zeroCols) {
    for (let y = 0; y < m; y++) {
      matrix[y][x] = 0;
    }
  }
  return matrix;
};
