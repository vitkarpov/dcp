const assert = require('assert');

// O(n) time and O(1) space
function solution(arr) {
    if (arr.length === 1) {
        return arr;
    }

    const product = arr.reduce((product, item) => {
        return product *= item;
    }, 1);

    return arr.map(item => product / item);
}

/**
 * Without divison: O(n) time and O(n) space
 */
function solution2(arr) {
    if (arr.length === 1) {
        return arr;
    }

    const left = initCompl(arr);
    const right = initCompl(arr.reverse());

    return arr.map((item, index) => {
        return left[index] * right[right.length - 1 - index];
    });
}

function initCompl(arr) {
    const result = [1];

    for (let i = 0; i < arr.length - 1; i++) {
        const prev = result[result.length - 1];
        result.push(prev * arr[i]);
    }

    return result;
}

assertArrays(solution([1, 2, 3, 4, 5]), [120, 60, 40, 30, 24]);
assertArrays(solution([3, 2, 1]), [2, 3, 6]);
assertArrays(solution([2, 2]), [2, 2]);
assertArrays(solution([10]), [10]);

assertArrays(solution2([1, 2, 3, 4, 5]), [120, 60, 40, 30, 24]);
assertArrays(solution2([3, 2, 1]), [2, 3, 6]);
assertArrays(solution2([2, 2]), [2, 2]);
assertArrays(solution2([10]), [10]);

function assertArrays(actual, expected) {
    actual.forEach((item, i) => {
        try {
            assert(expected[i] === item);
        } catch (e) {
            throw new Error(`expected ${expected[i]} but ${item} found`);
        }
    });
}
