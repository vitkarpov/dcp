'use strict';

const assert = require('assert');

class Node {
    constructor(value, left, right) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

function getNumberOfUnivalSubTrees(root) {
    if (root === null) {
        return 0;
    }
    if (root.left === null && root.right === null) {
        return 1;
    }

    const result = root.left.value === root.right.value ? 1 : 0;

    return result + getNumberOfUnivalSubTrees(root.left) + getNumberOfUnivalSubTrees(root.right);
}

function TestAll() {
    const root = new Node(0,
        new Node(1, null, null),
        new Node(0,
            new Node(1,
                new Node(1, null, null),
                new Node(1, null, null)
            ),
            new Node(0, null, null)
        )
    )
    assert(getNumberOfUnivalSubTrees(root) === 5);
}

TestAll();

module.exports = getNumberOfUnivalSubTrees;
