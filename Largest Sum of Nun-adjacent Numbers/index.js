'use strict';

const assert = require('assert');

assert(solve([2]) === 2);
assert(solve([2, 4, 6, 2, 5]) === 13);
assert(solve([5, 1, 1, 5]) === 10);

function solve(arr) {
    let mPrev = 0;
    let mCurr = 0;

    arr.forEach((item) => {
        const mNext = Math.max(mPrev, mCurr);

        mCurr = mPrev + item;
        mPrev = mNext;
    });

    return Math.max(mPrev, mCurr);
}
