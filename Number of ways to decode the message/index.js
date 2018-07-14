'use strict';

function count(s, k = 0, dp = []) {
    if (k === s.length) {
        return 1;
    }
    if (s[k] === '0') {
        return 0;
    }
    if (dp[k]) {
        return dp[k];
    }

    let result = count(s, k + 1, dp);

    if (s.length - k >= 2 && Number(s[k + 1] + s[k + 2]) <= 26) {
        result += count(s, k + 2, dp);
    }
    dp[k] = result;

    return result;
}

module.exports = count;
