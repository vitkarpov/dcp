# Number of ways to decode the message

Let you have an encoded string and a set of rules to decode that string.

- `a` → 1
- `b` → 2
- …
- `z` → 26

Find the number of ways you can decode the given string.

For instance, let you have `123` as an input. Let's write down the possible decoded messages:

- `123` → `abc`
- `123` → `lc`

As you can see there're two different options, the one when you consider 1, 2, 3 as a single characters and another one when you consider 12 as character `l`.

Time Complexity: O(`n`)
Space Complexity: O(`n`)
