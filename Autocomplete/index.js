const assert = require('assert');

class Node {
    constructor(value) {
        this.value = value;
        this.children = [];
        this.wordEnd = false;
        this.word = '';
    }
}

class AutoComplete {
    constructor(items) {
        this.root = new Node('');

        items.forEach((item) => {
            this.addWord(item);
        });
    }

    addWord(item) {
        let current = this.root;

        item.split('').forEach((symbol) => {
            let next = current.children.find((node) => node.value === symbol);

            if (!next) {
                next = new Node(symbol);
                current.children.push(next);
            }
            current = next;
        });
        current.wordEnd = true;
        current.word = item;

        return this;
    }

    find(prefix) {
        let current = this.root;

        prefix.split('').forEach((symbol) => {
            if (!current) {
                return;
            }
            current = current.children.find((node) => node.value === symbol);
        });

        if (!current) {
            return [];
        }

        const queue = [current];
        const words = [];

        while (queue.length > 0) {
            const node = queue.pop();

            if (node.wordEnd) {
                words.push(node.word);
            }

            node.children.forEach((node) => {
                queue.push(node);
            });
        }

        return words;
    }
}

const completer = new AutoComplete(['dog', 'deer', 'deal']);

assert(completer.find('de'), ['deer', 'deal']);
assert(completer.find('dea'), ['deal']);
assert(completer.find('d'), ['dog', 'deer', 'deal']);
assert(completer.find('da'), []);
assert(completer.find('b'), []);

module.exports = AutoComplete;
