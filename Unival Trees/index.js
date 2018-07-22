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
        return [0, true];
    }

    const [leftCount, isLeftUniversal] = getNumberOfUnivalSubTrees(root.left);
    const [rightCount, isRightUniversal] = getNumberOfUnivalSubTrees(root.right);
    const totalCount = leftCount + rightCount;

    if (isLeftUniversal && isRightUniversal) {
        if (root.left && root.value !== root.left.value) {
            return [totalCount, false];
        }
        if (root.right && root.value !== root.right.value) {
            return [totalCount, false];
        }
        return [totalCount + 1, true];
    }
    return [totalCount, false];
}

function TestAll() {
    {
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
        const [result] = getNumberOfUnivalSubTrees(root);
        assert(result === 5);
    }
    {
        const root = new Node(0,
            new Node(1, null, null),
            new Node(0,
                new Node(1,
                    new Node(0, null, null),
                    new Node(1, null, null)
                ),
                new Node(0, null, null)
            )
        )
        const [result] = getNumberOfUnivalSubTrees(root);
        assert(result === 4);
    }
}

TestAll();

module.exports = getNumberOfUnivalSubTrees;
