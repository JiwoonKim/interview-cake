/**
 *  Given the JavaScript code, 
 *  what will the browser's console show?
 *  
 *  ** What I learned:
 *     
 *     ** Scopes in JavaScript
 *        (1) function-level scope
 *            : functions create new scopes in JavaScript
 *        (2) NO if-scope or loop-scope
 *            : if statements and for loops do not create a new scope
 *              (also for Python <-> Java and C: creates new scope)
 * 
 *     * undefined (<-> ReferenceError)
 *       = variable declared but not yet initialized to specific value
 *       -> by default, variables declared but not yet assigned are initialized to 'undefined'
 *
 *      ** Hoisting
 *        : raising things to the top
 *        ; in JavaScript, variable & function DECLARATIONS are hoisted to the top of the current scope
 *                         however, variable & function ASSIGNMENTS are not 
 * 
 *        * var, function, function* declaration === 'undefined'
 *        * const, let, class declaration === uninitialized => access throws ReferenceError
 * 
 *        => both sides are hoisted (declared at its current scope)
 *           BUT, (var, function, function*) can be accessed and return 'undefined'
 *           while (const, let, class) cannot be accessed at all (throws ReferenceError)
 * 
 *       => hoisting can cause UNEXPECTED BEHAVIOR
 *          so a good way to keep things clear is to 
 *          ALWAYS DELCARE VARIABLES AT THE TOP OF THE SCOPE!!
 * 
 */

var text = 'outside';
function logIt() {
    console.log(text);
    var text = 'inside'; // declaration hoisted to top of logIt()'s scope
}
logIt(); // log: undefined


/**
 *  function-level scope
 *  : varInFunction is only available in function's scope
 */
function setVar() {
    var varInFunction = 'inside a function';
}
setVar();
console.log(varInFunction); // throws 'ReferenceError: varInFunction is not defined'

/**
 *  NO if-scope or loop-scope
 *  : varInIf is available in global scope
 */
if (true) {
    var varInIf = 'inside an if statement';
}
console.log(varInIf); // log: 'inside an if statement'

/**
 *  declaration Vs. assignment
 */
var unicorn; // declaration
console.log(unicorn); // log: undefined (X referenceError)
unicorn = 'sparkly'; // assignment
var centaur = 'clouds'; // declaration & assignment

/** Hoisting changes the original 
 *  problem code to below code
 */
var text = 'outside';
function logIt() {
    var text; // hoisted from below text variable; 
    console.log(text); // undefined (bcuz text declared but not assigned yet)
    text = 'inside';
}
logIt(); // log: undefined