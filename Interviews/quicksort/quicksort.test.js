const quicksort = require('./quicksort');

describe('quicksort', () => {
  let n = 1;

  generateTests(100).forEach((arr) => {
    it(`${n++}`, () => {
      expect(quicksort([].concat(arr))).toEqual(arr.sort((a, b) => a - b));
    });
  });
});

function generateTests(N) {
  const result = [];

  for (let i = 0; i < N; i++) {
    result.push(new Array(N));

    for (let j = 0; j < N; j++) {
      result[result.length - 1][j] = Math.floor(Math.random() * Number.MAX_SAFE_INTEGER);
    }
  }

  return result;
}
