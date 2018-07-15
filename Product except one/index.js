const assert = require('assert');

// O(n) time and O(1) space
function solution(arr) {
    const product = arr.reduce((product, item) => {
        return product *= item;
    }, 1);

    return arr.map(item => product / item);
}

/**
 * If I can't use division then the only way I see is O(N^2) so far :-(
 */
function solution2(arr) {
    const n = arr.length;
    const result = [];

    for (let i = 0; i < n; i++) {
        let product = 1;

        for (let j = 0; j < n; j++) {
            if (i !== j) {
                product *= arr[j];
            }
        }

        result.push(product);
    }

    return result;
}

assertArrays(solution([1, 2, 3, 4, 5]), [120, 60, 40, 30, 24]);
assertArrays(solution([3, 2, 1]), [2, 3, 6]);

assertArrays(solution2([1, 2, 3, 4, 5]), [120, 60, 40, 30, 24]);
assertArrays(solution2([3, 2, 1]), [2, 3, 6]);

function assertArrays(actual, expected) {
    actual.forEach((item, i) => {
        try {
            assert(expected[i] === item);
        } catch (e) {
            throw new Error(`expected ${expected[i]} but ${item} found`);
        }
    });
}
