const getPI = require('./');

describe('PI Approximation', () => {
    const eps = 0.1;

    test('should be close to 3.14', () => {
        const PI = getPI();
        console.log(`PI approx equals to ${PI}`);
        expect(Math.abs(PI - 3.14)).toBeLessThan(eps);
    });
});
