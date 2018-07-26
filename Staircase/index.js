'use strict';

function getNumberOfWays(n, steps) {
    const dp = steps.reduce((dp, step) => {
        dp[step] = 1;
        return dp;
    }, []);

    for (let i = 1; i <= n; i++) {
        dp[i] = steps.reduce((sum, step) => {
            sum += dp[i - step] || 0;
            return sum;
        }, dp[i] || 0);
    }
    return dp[n];
}

module.exports = getNumberOfWays;
