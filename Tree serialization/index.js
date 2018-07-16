const assert = require('assert');

class Node {
    constructor(val, left, right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

const root = new Node('root', new Node('left', new Node('left.left')), new Node('right'));

const DELIMITER = '>';
const END = '<';
const serialized = ['root', 'left', 'left.left', END, END, END, 'right', END, END].join(DELIMITER);

assert(ser(root) === serialized);
assert(des(ser(root)).left.left.val === 'left.left');

function ser(node) {
    if (!node) {
        return END;
    }
    return node.val + DELIMITER + ser(node.left) + DELIMITER + ser(node.right);
}

function des(str, state = {}) {
    let pos = state.pos || 0;

    if (str[pos] == END) {
        return null;
    }

    let val = '';

    while (str[pos] != DELIMITER) {
        val += str[pos];
        pos++;
    }

    state.pos = pos + 1;

    return new Node(val, des(str, state), des(str, state));
}
