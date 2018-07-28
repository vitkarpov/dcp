/**
 * The key idea here is that you can uniformly distribute points
 * on the 1x1 square area and then count how many points ended up
 * inside the inscribed circle.
 * The ratio of the inside-count and the total-sample-count approximates PI/4.
 * As soos as points are well distributed the approximation should be accurate.
 */

function getPI() {
    const R = 0.5;
    const N = 1000;
    const points = (new Array(N)).fill().map(() => {
        return [Math.random(), Math.random()];
    });

    return 4 * points.reduce((res, [x, y]) => {
        return sqr(x - 0.5) + sqr(y - 0.5) <= sqr(R) ? ++res : res;
    }, 0) / points.length;
}

function sqr(x) {
    return x * x;
}

module.exports = getPI;
