# Parentheses balancing.
## Objectives
- Implement the ADT SList (Single Linked List).
- Implement the ADT Stack using a SList.
- Use the TADStack to solve a parentheses balancing problem.

## Description
Implement the ADT SList using a dynamic implementation and by using this implement the ADT Stack. Here we develop an algorithm that checks the correct balance of different types of parentheses in a text (assumes the 8-bit ASCII character set).

The types of parentheses to check are '(', '[', '{', which match the corresponding closed parentheses ')', ']' and '}'. The program will display “Success” if the text is balanced or the position of the character corresponding to the first parenthesis that is unbalanced, with 1 being the first character. Priority will be given to displaying the first closed unbalanced parenthesis, for example 3 for the case “()}” or the first open parenthesis not balanced, for example 1 for the case “({}”.

To solve this problem, a stack will be used in which the found open parentheses will be stacked and unstacked according to other closed parentheses that match the top of the stack. When an open parenthesis is stacked, the position of the corresponding character must be added to have that information if the end of the parenthesis is not balanced.

The stack will be implemented using a simple list. Dynamic or bounded implementation (the maximum depth will be 100,000). 

### Examples

- Input: “”
    - Output: “Success”
- Input: “()”
    - Output: “Success”
- Input: “[]()”
    - Output: “Success”
- Input: “{[]}”
    - Output: “Success”
- Input: “(}”
    - Output: 2 (Priority to the closed parenthesis)
- Input: “({}”
    - Output: 1
- Input: “{(})”
    - Output: 3
- Input: “{}[“
    - Output: 3

## Tests
- SList
- Stack
- Check Brackets