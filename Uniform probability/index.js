/**
 * The idea here is that we should pick up the next element from stream with 1 / i probability,
 * where i is the number of elements seen so far.
 * 
 * It's pretty simple since we can pick a random number from range [1..i]
 * and it should be equal to 1 with 1 / i probability.
 */

let i = 0;
let result;

process.stdin.on('data', (s) => {
    s.toString().split('\n').map(Number).forEach((item) => {
        i++;
        if (Math.ceil(Math.random() * i) === 1) {
            result = item;
        }
    })
});

process.stdin.on('end', () => {
    console.log(result);
});
