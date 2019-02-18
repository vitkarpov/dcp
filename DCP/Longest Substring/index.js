const assert = require('assert');

function getLenOfLongestSubstr(s, k) {
    assert(s.length > 0, 'String should not be empty');
    assert(k > 0, 'k should be a positive integer');

    let res = 0;
    let diff = 0;
    let i = 0;
    let j = 0;
    const store = initStore(s);

    while (j < s.length) {
        if (diff <= k) {
            if (store[s[j]] === 0) {
                diff++;
            }
            store[s[j]]++;
            res = Math.max(res, j - i);
            j++;
        } else {
            store[s[i]]--;
            if (store[s[i]] === 0) {
                diff--;
            }
            i++;
        }
    }

    return res;
}

function initStore(s) {
    return s.split('').reduce((store, char) => {
        return store[char] = 0, store;
    }, {});
}

module.exports = getLenOfLongestSubstr;
