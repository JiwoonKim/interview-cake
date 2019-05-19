# Interview Cake
> solutions to interview cake questions

## Tips to Untangling Stucky Moments
1. `Use a simpler version of the problem`
    - __to see if that gets us closer to a solution for the original problem__
    - use the solution to a simpler version __as a strategy to resolve a certain issue__ within the original problem
2. `Short-circuit evaluation`
    - __stop evaluating a logical expression as soon as the result is certain__
        - ex. if (check1 && check2) -> if check1 is false, don't even bother to check2
        - ex. if (check1 || check2) -> if check1 is true, the expression is also true so don't have to check2
    - __useful to check for end cases / edge cases__
    - beautifully ties up the complicated edge cases together in code and __ensures that edge cases are checked before doing something that may mess up the system or memory__
3. `Use Unordered Map or Unordered Set`
    - __most common way to improve from a brute force approach__
    - __it should always be your first thought!__
        - always ask yourself, right from the start: "__Can I save time by using an unordered map or set?__"
    - use `unordered map` to improve access time to elements

## Check Bugs
1. off-by-one errors (ex. indexing)
2. edge cases
3. returning values by if-else conditions (ex. 2-1. inflight entertainment)

## Useful Functions To Remember
> list of useful mechanisms (functions) to remember

### 1. Array and String Manipulation
1. `swap chars in string in-place` (1-2. reverse string inplace)
2. `parse words from string` (1-3. reverse words inplace)
3. `use sort or take advantage of sort` (1-4. merge sorted arrays & 5. single riffle shuffle)

### 2. Hashing and Hash Tables
1. `find pairs in single loop` (2-1. inflight entertainment)
    - a.k.a __one-pass hash table__
2. `use unordered set` (2-1. inflight entertainment)
3. `use unordered set instead` 