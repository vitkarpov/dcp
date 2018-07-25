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
        let next;

        for (let i = 0; i < item.length; i++) {
            const symbol = item[i];
            next = current.children.find((node) => node.value === symbol);

            if (!next) {
                next = new Node(symbol);
                current.children.push(next);
            }
            current = next;
        }

        current.wordEnd = true;
        current.word = item;

        return this;
    }

    find(prefix) {
        return this._findAllWordsFromNode(this._getPrefixNode(prefix));
    }

    _findAllWordsFromNode(node) {
        if (!node) {
            return [];
        }

        const queue = [node];
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

    _getPrefixNode(prefix) {
        let current = this.root;

        for (let i = 0; i < prefix.length; i++) {
            const symbol = prefix[i];

            current = current.children.find((node) => node.value === symbol);

            if (!current) {
                return null;
            }
        }
        return current;
    }
}

const completer = new AutoComplete(['dog', 'deer', 'deal']);

assert(completer.find('de'), ['deer', 'deal']);
assert(completer.find('dea'), ['deal']);
assert(completer.find('d'), ['dog', 'deer', 'deal']);
assert(completer.find('da'), []);
assert(completer.find('b'), []);

module.exports = AutoComplete;
