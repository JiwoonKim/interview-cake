# Interview Cake :cake:
> solutions to interview cake questions

## :running_woman: Start
1. `use simple example to understand the problem`
    - if needed, even create drawings
    - helps to __find how to approach the problem__
2. `Start off w/ Brute-force Method`
    - start off by coming up with slow but correct brute force solution to __understand the problem__
    - it's __better to have a slower solution than to have no solution at all!__
    - after, __look for repeated work__
        - optimization usually starts when brainstorming to avoid doing that repeated work
3. `Use the time and space bounds as reference points for optimizations`
    - check the time / space bounds of current solution and __try patterns w/ better complexities__ to improve current solution
    - __starting with a target runtime and working backward from there can be a powerful strategy__ for all kinds of coding interview questions.

## :airplane: Optimize
0.  `check what we should optimize for`: __time or space?__
    - efficiency depends on situation: optimization could be for time or space depending on inputs
    - use the expected characteristics of the input as reference to what we should optimize for
1. `Use Unordered Map or Unordered Set`
    - __most common way to improve from a brute force approach__
    - __it should always be your first thought!__
        - always ask yourself, right from the start: "__Can I save time by using an unordered map or set?__"
    - use `unordered map` to __improve access time to elements__
    - use `unordered set` instead when do not need to store additional data (just need to improve access time to values)
        - can also use it to __check like boolean using insert & remove__
2. `Use Greedy Approach`
    - builds up solution by __choosing the best option so far at every step__
    - should be __one of the first ways to try to break down a question__
        - always ask yourself, right from the start: "__Suppose answer is in updating the best answer so far, what additional values do you need to keep track of in order to update the best answers so far?__
    - careful since greedy algorithm does not guarantee optimal solution
        - best bet is to __try it out and see if it works__
    - curate __additional values to keep track of__ by __thinking about all the possible input cases (including edge cases)__
    - __come up with a higher-level formula using the additional values__, instead of simply dividing into if-else cases
3. `Use Dynamic Programming Approach`
    - does not mean to just build from 1 to n

## :stuck_out_tongue_closed_eyes: Tips to Untangling Stucky Moments
1. `Use a simpler version of the problem`
    - __to see if that gets us closer to a solution for the original problem__
    - use the solution to a simpler version __as a strategy to resolve a certain issue__ within the original problem
    - __simplify, solve, and adapt__ strategy => take a breath: __don't over complicate the problem__
2. `Take a step back and try to break the problem down into subproblems`
    - subproblems mean similar __smaller problems__ => they should be smaller
3. `Call a Helper Function and Move On`
    - __just skip over it__ if you can't immediately think of how to implement some part of your algorithm, big or small
    - write a call to a reasonably-named __helper function__, __say "this will do X" and keep going__
    - it's more important to implement the core functionality of the problem (the big picture or higher-level solution) than small bits
        - come back to it later; after the core is developed
    - if the helper function is trivial, you might even get away with never implementing it

### :beetle: Check Bugs 
> check for common errors
1. off-by-one errors (ex. indexing)
2. returning values by if-else conditions (ex. 2-1. inflight entertainment)
3. __Edge Cases__ -> __check input__ to find edge cases
    - integer: positive/negative cases, division (check if 0), duplicates
    - graphs: nodes w/ no edges, cycles, loops (to itself)
    - stacks/queues: empty cases
    - linked lists: head node, last node, prev/current/next node pointing to empty node

### * Open ended Questions (Heuristics) :rocket:
> some questions involve dealing w/ several approaches (there are no definite answers)
- compare the approaches' pros and cons => none are perfect! (ex. 2-3. word cloud data)
- acknowledge that there can be imperfect solutions
    - it's okay to throw exceptions to cases where you cannot solve due to input constraints (8-1. delete node)

## :wrench: Useful Mechanisms To Remember
> list of useful mechanisms (functions) to remember

### 0. General
1. `Short-circuit Evaluation`
    - __stop evaluating a logical expression as soon as the result is certain__
        - ex. if (check1 && check2) -> if check1 is false, don't even bother to check2
        - ex. if (check1 || check2) -> if check1 is true, the expression is also true so don't have to check2
    - __useful to check for end cases / edge cases__
    - beautifully ties up the complicated edge cases together in code and __ensures that edge cases are checked before doing something that may mess up the system or memory__
2. `Handle Error Cases first`
    - create logic to __handle error cases or break conditions first w/ series of if conditions__
    - __write code in small blocks__ to simplify complex logic
    - break code into __series of if conditions__ instead of complex nested if-else chains
    - see if negating the condition and break / return value logic works cleaner or simplier in logic

### 1. Array and String Manipulation
1. `merge ranges by using sort + check overlapping condition` ([1-1. merge meeting times](https://github.com/JiwoonKim/interview-cake/blob/master/1_array_string/1_merge_meeting_times.cpp))
2. `swap chars in string in-place` ([1-2. reverse string inplace](https://github.com/JiwoonKim/interview-cake/blob/master/1_array_string/2_reverse_string_inplace.cpp))
3. `parse words from string` ([1-3. reverse words inplace](https://github.com/JiwoonKim/interview-cake/blob/master/1_array_string/3_reverse_words_inplace.cpp))
4. `use sort or take advantage of sort` ([1-4. merge sorted arrays](https://github.com/JiwoonKim/interview-cake/blob/master/1_array_string/4_merge_sorted_arrays.cpp) & [1-5. single riffle shuffle](https://github.com/JiwoonKim/interview-cake/blob/master/1_array_string/5_single_riffle_shuffle.cpp))

### 2. Hashing and Hash Tables
1. `find pairs in single loop` ([2-1. inflight entertainment](https://github.com/JiwoonKim/interview-cake/blob/master/2_hash_table/1_inflight_entertainment.cpp)) a.k.a __one-pass hash table__
2. `parse words from string (more complex)` ([2-3. word cloud data](https://github.com/JiwoonKim/interview-cake/blob/master/2_hash_table/3_word_cloud_data.cpp))
3. `counting` ([2-4. top scores](https://github.com/JiwoonKim/interview-cake/blob/master/2_hash_table/4_top_scores.cpp))
4. `define classes to tie methods together` ([2-3. word cloud data](https://github.com/JiwoonKim/interview-cake/blob/master/2_hash_table/3_word_cloud_data.cpp) & [2-5. find duplicate files](https://github.com/JiwoonKim/interview-cake/blob/master/2_hash_table/5_find_duplicate_files.cpp))

### 3. Greedy Algorithms
1. `keep additional values to update best answer so far` ([3-1. apple stocks](https://github.com/JiwoonKim/interview-cake/blob/master/3_greedy_algorithm/1_apple_stocks.cpp)) => __greedy algorithm approach__
2. `compare values in vector` ([3-1. apple stocks](https://github.com/JiwoonKim/interview-cake/blob/master/3_greedy_algorithm/1_apple_stocks.cpp))
3. `use nested max / min` ([3-2. highest product of 3](https://github.com/JiwoonKim/interview-cake/blob/master/3_greedy_algorithm/2_highest_product_3.cpp))
4. `Fisher-Yates shuffle algorithm` ([3-4. inplace shuffle](https://github.com/JiwoonKim/interview-cake/blob/master/3_greedy_algorithm/4_inplace_shuffle.cpp)) => __to guarantee uniform distribution__

### 4. Sorting, Searching, and Logarithms
1. `binary search - make sure sorted` ([4-1. find rotation point](https://github.com/JiwoonKim/interview-cake/blob/master/4_sorting_searching_logarithms/1_find_rotation_point.cpp))
2. `use opposite of sorted condition to find pivot point` ([4-1. find rotation point](https://github.com/JiwoonKim/interview-cake/blob/master/4_sorting_searching_logarithms/1_find_rotation_point.cpp))
3. `pigeonhole principle` ([4-2. find duplicates - space mode](https://github.com/JiwoonKim/interview-cake/blob/master/4_sorting_searching_logarithms/2_find_duplicates_space_mode.cpp)) => try to think of pigeonholes and pigeon analogy: __"what fits into what"__

### 5. Trees and Graphs
1. `define binary tree class` ([5-1. balanced binary tree](https://github.com/JiwoonKim/interview-cake/blob/master/5_trees_graphs/1_balanced_binary_tree.cpp))
2. `DFS to hit leaf nodes in tree faster` ([5-1. balanced binary tree](https://github.com/JiwoonKim/interview-cake/blob/master/5_trees_graphs/1_balanced_binary_tree.cpp))
3. `use DFS for better space complexity when tree is balanced` ([5-2. binary search tree checker](https://github.com/JiwoonKim/interview-cake/blob/master/5_trees_graphs/2_binary_search_tree_checker.cpp))
4. `can return combination of bool values for recursive DFS using &&` ([5-2. binary search tree checker](https://github.com/JiwoonKim/interview-cake/blob/master/5_trees_graphs/2_binary_search_tree_checker.cpp))
5. `how to find element in BST` ([5-3. 2nd largest item in BST](https://github.com/JiwoonKim/interview-cake/blob/master/5_trees_graphs/3_2nd_largest_item_in_bst.cpp))
6. `define graph class` ([5-4. graph coloring](https://github.com/JiwoonKim/interview-cake/blob/master/5_trees_graphs/4_graph_coloring.cpp))
7. `backtracking using unordered map` ([5-5. mesh message](https://github.com/JiwoonKim/interview-cake/blob/master/5_trees_graphs/5_mesh_message.cpp))
8. `use array positions to find cycles` ([5-6. find duplicates - beast edition](https://github.com/JiwoonKim/interview-cake/blob/master/5_trees_graphs/6_find_duplicates_beast_edition.cpp))

### 6. Dynamic Programming & Recursion
1. `how to create string permutations` ([6-1. recursive string permutations](https://github.com/JiwoonKim/interview-cake/blob/master/6_dp_recursion/1_recursive_string_permutations.cpp))
2. `how to solve unbounded knapsack problem` ([6-3. make change](https://github.com/JiwoonKim/interview-cake/blob/master/6_dp_recursion/3_make_change.cpp) & [6-4. cake thief](https://github.com/JiwoonKim/interview-cake/blob/master/6_dp_recursion/4_cake_thief.cpp))

### 7. Stacks and Queues
1. `make sure not empty when pop / top / front` ([7-1. largest stack](https://github.com/JiwoonKim/interview-cake/blob/master/7_stacks_queues/1_largest_stack.cpp))
2. `how to implement queue using two stacks` ([7-2. queue with two stacks](https://github.com/JiwoonKim/interview-cake/blob/master/7_stacks_queues/2_queue_with_two_stacks.cpp))
3. `use stack to check parenthesis` ([7-3. parenthesis matching](https://github.com/JiwoonKim/interview-cake/blob/master/7_stacks_queues/3_parenthesis_matching.cpp) & [7-4. bracket validator](https://github.com/JiwoonKim/interview-cake/blob/master/7_stacks_queues/4_bracket_validator.cpp))
    - if only one kind of parenthesis, `can use count to save space`
4. `use unordered set to check if something is part of group or not` ([7-4. bracket validator](https://github.com/JiwoonKim/interview-cake/blob/master/7_stacks_queues/4_bracket_validator.cpp))
5. `use unordered map to find the matching other pair for something` ([7-4. bracket validator](https://github.com/JiwoonKim/interview-cake/blob/master/7_stacks_queues/4_bracket_validator.cpp))

### 8. Linked Lists
1. `in-place modifications to delete node` ([8-1. delete node](https://github.com/JiwoonKim/interview-cake/blob/master/8_linked_lists/1_delete_node.cpp))
2. `two runner approach to check cycle` ([8-2. check cycle](https://github.com/JiwoonKim/interview-cake/blob/master/8_linked_lists/2_check_cycle.cpp))
3. `reverse linked list inplace and outplace` ([8-3. reverse linked list in-place](https://github.com/JiwoonKim/interview-cake/blob/master/8_linked_lists/3_reverse_linked_list_inplace.cpp))
4. `use k-wide stick` ([8-4. kth to last node](https://github.com/JiwoonKim/interview-cake/blob/master/8_linked_lists/4_kth_to_last_node.cpp))

### 9. General Programming
1. `define RECT and RANGE class` ([9-1. rectangle love](https://github.com/JiwoonKim/interview-cake/blob/master/9_general_programming/1_rectangle_love.cpp))
2. `O(1000) is more efficient than  O(n) in theory!` ([9-2. temperature tracker](https://github.com/JiwoonKim/interview-cake/blob/master/9_general_programming/2_temperature_tracker.cpp))

### 10. Bit Manipulation
1. `use XOR to cancel out matching numbers` ([10-1. stolen breakfast drone](https://github.com/JiwoonKim/interview-cake/blob/master/10_bit_manipulation/1_stolen_breakfast_drone.cpp))

### 11. Combination, Probability, Math
1. `use math (triangular series) to optimize memory use` ([11-1. which appears twice](https://github.com/JiwoonKim/interview-cake/blob/master/11_combination_probability_math/1_which_appears_twice.cpp))
2. `check searching condition (end >= start) for both versions of binary search - iterative & recursive` ([11-2. find in ordered set](https://github.com/JiwoonKim/interview-cake/blob/master/11_combination_probability_math/2_find_in_ordered_set.cpp))
3. `first define desired possible outcomes w/ equal probability` and then, `match everything else to that` ([11-3. simulate 5-sided die](https://github.com/JiwoonKim/interview-cake/blob/master/11_combination_probability_math/3_simulate_5_sided_die.cpp) && [11-4. simulate 7-sided die](https://github.com/JiwoonKim/interview-cake/blob/master/11_combination_probability_math/4_simulate_7_sided_die.cpp))
    - define desired possible outcomes: `increase rolling numbers to expand possible outcomes && re-roll to cut off extraneous bits for equal probability`
    - match everything else: `re-roll until outcome in desired range to reduce possible outcomes`
> can use math and logic to solve brain teaser questions ([11-5. two egg problem](https://github.com/JiwoonKim/interview-cake/blob/master/11_combination_probability_math/5_two_egg_problem.cpp))

### 12. JavaScript
1. scopes (12-1. javascript scope)
    - `functional-level scope`
    - `no if-scope or loop-scope`
2. `variable hoisting` ([12-1. javascript scope](https://github.com/JiwoonKim/interview-cake/blob/master/12_javascript/1_javascript_scope.js))
    - `var, function, function* === undefined (declared but not yet assigned`
    - `let, const, class === ReferenceError (access denied)`
3. `use IIFE to pass value when adding event listener` ([12-2. whats wrong with this javascript](https://github.com/JiwoonKim/interview-cake/blob/master/12_javascript/2_whats_wrong_with_this_javascript.html))
    - `use closure method for final return function to access the value passed to IIFE`
    
### 13. System Design
1. 

## :vertical_traffic_light: NP Problems
- feasible problems: problems solved in polynomial time
- intractable problems: solutions taking higher than polynomial time (ex. exponential time)
- __NP Problems__: problems w/ non-deterministic polynomial time
