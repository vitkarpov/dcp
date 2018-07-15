const assert = require('assert');

assert(isThereAPairOfNumbers([10, 15, 3, 7], 17));
assert(isThereAPairOfNumbers([10, -5, 3, 7], 5));
assert(isThereAPairOfNumbers([10, -5, 3, 5], 0));
assert(isThereAPairOfNumbers([-10, -5, 3, 7], -15));

assert(!isThereAPairOfNumbers([5, 10, 3, 4], 5));
assert(!isThereAPairOfNumbers([10, 5, 3, 7], 0));
assert(!isThereAPairOfNumbers([10, 15, 3, 7], 14));

function isThereAPairOfNumbers(arr, k) {
    const compl = {};

    return arr.reduce((acc, item, index) => {
        if (compl[item]) {
            return true;
        }
        compl[k - item] = true;
        return acc;
    }, false);
}
