const assert = require('assert');

assert(isThereAPairOfNumbers([10, 15, 3, 7], 17));
assert(isThereAPairOfNumbers([10, -5, 3, 7], 5));
assert(isThereAPairOfNumbers([10, -5, 3, 5], 0));
assert(isThereAPairOfNumbers([-10, -5, 3, 7], -15));

assert(!isThereAPairOfNumbers([10, 5, 3, 7], 0));
assert(!isThereAPairOfNumbers([10, 15, 3, 7], 14));

function isThereAPairOfNumbers(arr, k) {
    const compl = arr.reduce((acc, item, index) => {
        return acc[k - item] = index, acc;
    }, {});

    return arr.filter((item, index) => {
        return typeof compl[item] !== 'undefined' && compl[item] !== index;
    }).length > 0;
}
