# Interview Cake
> solutions to interview cake questions

## Tips to Untangling Stucky Moments
1. `Use Unordered Map or Unordered Set`
    - __most common way to improve from a brute force approach__
    - __it should always be your first thought!__
        - always ask yourself, right from the start: "__Can I save time by using an unordered map or set?__"
    - use `unordered map` to __improve access time to elements__
    - use `unordered set` instead when do not need to store additional data (just need to improve access time to values)
        - can also use it to __check like boolean using insert & remove__
2. `Use a simpler version of the problem`
    - __to see if that gets us closer to a solution for the original problem__
    - use the solution to a simpler version __as a strategy to resolve a certain issue__ within the original problem

## Check Bugs
1. off-by-one errors (ex. indexing)
2. edge cases
3. returning values by if-else conditions (ex. 2-1. inflight entertainment)

## Open ended Questions
- some questions involve dealing w/ several approaches (there are no definite answers)
- compare the approaches' pros and cons (none are perfect)
- ex. 2-3. word cloud data

## Useful Mechanisms To Remember
> list of useful mechanisms (functions) to remember

### 0. General
1. `Short-circuit evaluation`
    - __stop evaluating a logical expression as soon as the result is certain__
        - ex. if (check1 && check2) -> if check1 is false, don't even bother to check2
        - ex. if (check1 || check2) -> if check1 is true, the expression is also true so don't have to check2
    - __useful to check for end cases / edge cases__
    - beautifully ties up the complicated edge cases together in code and __ensures that edge cases are checked before doing something that may mess up the system or memory__

### 1. Array and String Manipulation
1. `swap chars in string in-place` (1-2. reverse string inplace)
2. `parse words from string` (1-3. reverse words inplace)
3. `use sort or take advantage of sort` (1-4. merge sorted arrays & 5. single riffle shuffle)

### 2. Hashing and Hash Tables
1. `find pairs in single loop` (2-1. inflight entertainment) a.k.a __one-pass hash table__
2. `parse words from string (more complex)` (2-3. word cloud data)
3. `use class ` (2-3. word cloud data)