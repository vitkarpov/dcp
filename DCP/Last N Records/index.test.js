const Logs = require('./');

describe('Last N Records', () => {
    [
        [5, [1, 2, 3, 4, 5], [1, 2, 3, 4, 5]],
        [5, [1, 2, 3, 4, 5, 6, 7, 8], [4, 5, 6, 7, 8]],
        [5, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11], [7, 8, 9, 10, 11]]
    ].forEach(([N, input, output]) => {
        it(`should return last ${N} records`, () => {
            const logs = new Logs(N);
            input.forEach((i) => logs.record(i));
            expect(logs.getLast(N)).toEqual(output);
        });
    });
});
