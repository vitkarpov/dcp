class Logs {
    constructor(n) {
        this._n = n;
        this._records = [];
        this._writePointer = 0;
    }

    record(item) {
        this._records[this._writePointer] = item;
        this._writePointer = (this._writePointer + 1) % this._n;
    }

    getLast(n) {
        return [].concat(
            this._records.slice(this._writePointer),
            this._records.slice(0, this._writePointer)
        );
    }
}

module.exports = Logs;
