# Interview Cake
> solutions to interview cake questions

## Start
1. `Start off w/ Brute-force Method`
    - start off by coming up with slow but correct brute force solution to understand the problem
    - it's __better to have a slower solution than to have no solution at all!__
    - after, __look for repeated work__
        - optimization usually starts when brainstorming to avoid doing that repeated work
2. `Use the time and space bounds as reference points for optimizations`
    - check the time / space bounds of current solution and __try patterns w/ better complexities__ to improve current solution
    - __starting with a target runtime and working backward from there can be a powerful strategy__ for all kinds of coding interview questions.

## Tips to Untangling Stucky Moments
1. `Use a simpler version of the problem`
    - __to see if that gets us closer to a solution for the original problem__
    - use the solution to a simpler version __as a strategy to resolve a certain issue__ within the original problem
- `Take a step back and try to break the problem down into subproblems`
2. `Use Unordered Map or Unordered Set`
    - __most common way to improve from a brute force approach__
    - __it should always be your first thought!__
        - always ask yourself, right from the start: "__Can I save time by using an unordered map or set?__"
    - use `unordered map` to __improve access time to elements__
    - use `unordered set` instead when do not need to store additional data (just need to improve access time to values)
        - can also use it to __check like boolean using insert & remove__
3. `Use Greedy Approach`
    - builds up solution by __choosing the best option so far at every step__
    - should be __one of the first ways to try to break down a question__
        - always ask yourself, right from the start: "__Suppose answer is in updating the best answer so far, what additional values do you need to keep track of in order to update the best answers so far?__
    - careful since greedy algorithm does not guarantee optimal solution
        - best bet is to __try it out and see if it works__
    - curate __additional values to keep track of__ by __thinking about all the possible input cases (including edge cases)__
    - __come up with a higher-level formula using the additional values__, instead of simply dividing into if-else cases
4. `Call a Helper Function and Move On`
    - __just skip over it__ if you can't immediately think of how to implement some part of your algorithm, big or small
    - write a call to a reasonably-named helper function, __say "this will do X" and keep going__
    - it's more important to implement the core functionality of the problem (the big picture or higher-level solution) than small bits
        - come back to it later; after the core is developed
    - if the helper function is trivial, you might even get away with never implementing it

### Check Bugs
> check for common errors
1. off-by-one errors (ex. indexing)
2. returning values by if-else conditions (ex. 2-1. inflight entertainment)
3. edge cases -> check input to find edge cases
    - ex. integer: positive/negative cases, division (check if 0)

### Open ended Questions (Heuristics)
> some questions involve dealing w/ several approaches (there are no definite answers)
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
3. `counting` (2-4. top scores)
4. `define classes to tie methods together` (2-3. word cloud data & 2-5. find duplicate files)

### 3. Greedy Algorithms
1. `keep additional values to update best answer so far` (3-1. apple stocks) => __greedy algorithm approach__
2. `compare values in vector` (3-1. apple stocks)
3. `use nested max / min` (3-2. highest product of 3)
4. `Fisher-Yates shuffle algorithm` (3-4. inplace shuffle) => __to guarantee uniform distribution__

### 4. Sorting, Searching, and Logarithms
1. `binary search - make sure sorted` (4-1. find rotation point)
2. `use opposite of sorted condition to find pivot point` (4-1. find rotation point)
3. `pigeonhole principle` (4-2. find duplicates - space mode) => try to think of pigeonholes and pigeon analogy: __"what fits into what"__

### 5. Trees and Graphs
1. `DFS to hit leaf nodes in tree faster` (5-1. balanced binary tree)