const getNumberOfWays = require('./');

describe('Staicase', () => {
    test('should return 5 for 4 steps and [1, 2] options', () => {
        expect(getNumberOfWays(4, [1, 2])).toBe(5);
    });
});
