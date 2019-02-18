'use strict';

const assert = require('assert');

assert(solve([3, 4, -1, 1]) === 2);
assert(solve2([3, 4, -1, 1]) === 2);
assert(solve([1, 2, 0]) === 3);
assert(solve2([1, 2, 0]) === 3);
assert(solve([3, 4, -1, 1, 2]) === 5);
assert(solve2([3, 4, -1, 1, 2]) === 5);
// assert(solve([-1, -2, -3]) === 1);
// assert(solve2([-1, -2, -3]) === 1);
// assert(solve([2, 3, 4]) === 1);
// assert(solve2([2, 3, 4]) === 1);
// assert(solve([1, 1, 1, 1, 1]) === 2);
// assert(solve2([1, 1, 1, 1, 1]) === 2);

function solve(arr) {
    let min = 1;

    arr.forEach(i => {
        if (i > 0 && i === min) {
            min++;
        }
    });
    arr.forEach(i => {
        if (i > 0 && i === min) {
            min++;
        }
    });
    return min;
}

function solve2(arr) {
    const len = arr.unshift(0);

    for (let i = 1; i < len; i++) {
        if (arr[i] > 0 && arr[i] < len) {
            swap(arr, i, arr[i]);
        }
    }
    for (let i = 2; i < len; i++) {
        if (arr[i] != i) {
            return i;
        }
    }
    return len;
}

function swap(arr, i, j) {
    [arr[i], arr[j]] = [arr[j], arr[i]];
}
