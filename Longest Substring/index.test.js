const getLenOfLongestSubstr = require('./');

describe('Longest Substring', () => {
    [
        ['abcba', 2, 3],
        ['aaaabcaadfg', 3, 8],
        ['abcdefg', 1, 1],
        ['a', 2, 0],
    ].forEach(([s, k, expected]) => {
        test(`s = "${s}", k = ${k} should be equal ${expected}`, () => {
            expect(getLenOfLongestSubstr(s, k)).toBe(expected);
        });
    });
});
