const assert = require('assert');

assert(car(cons(1, 2), 1));
assert(cdr(cons(2, 4), 4));

function cons(a, b) {
    return function(f) {
        return f(a, b);
    }
}

function car(pair) {
    return pair((a, b) => a);
}

function cdr(pair) {
    return pair((a, b) => b);
}
