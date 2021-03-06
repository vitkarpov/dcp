'use strict';

const assert = require('assert');

assert(count('111') === 3);

function count(s, k = 0, dp = []) {
    if (k === s.length) {
        return 1;
    }
    if (dp[k]) {
        return dp[k];
    }

    let result = count(s, k + 1, dp);

    if (s.length - k >= 2 && Number(s[k] + s[k + 1]) <= 26) {
        result += count(s, k + 2, dp);
    }
    dp[k] = result;

    return result;
}

module.exports = count;
