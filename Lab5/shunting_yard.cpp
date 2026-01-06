#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Function to get precedence of operators
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to display stack contents (for visualization)
void displayStack(stack<char> s) {
    string result = "";
    while (!s.empty()) {
        result = s.top() + result;
        s.pop();
    }
    cout << "[" << result << "]";
}

// Shunting-yard algorithm to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> operators;
    string postfix = "";
    
    cout << "\nShunting-yard Algorithm - Step by Step:\n";
    cout << "========================================\n";
    cout << "Infix: " << infix << "\n\n";
    
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        // Skip whitespace
        if (c == ' ')
            continue;
        
        // If character is a digit or letter (operand)
        if (isalnum(c)) {
            postfix += c;
            cout << "Read operand '" << c << "' -> Add to output\n";
            cout << "  Output: " << postfix << "\n";
            cout << "  Stack:  ";
            displayStack(operators);
            cout << "\n\n";
        }
        // If character is '('
        else if (c == '(') {
            operators.push(c);
            cout << "Read '(' -> Push to stack\n";
            cout << "  Output: " << postfix << "\n";
            cout << "  Stack:  ";
            displayStack(operators);
            cout << "\n\n";
        }
        // If character is ')'
        else if (c == ')') {
            cout << "Read ')' -> Pop until '('\n";
            
            // Pop operators until '(' is found
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                cout << "  Pop '" << operators.top() << "' to output\n";
                operators.pop();
            }
            
            // Pop the '(' but don't add to output
            if (!operators.empty())
                operators.pop();
            
            cout << "  Output: " << postfix << "\n";
            cout << "  Stack:  ";
            displayStack(operators);
            cout << "\n\n";
        }
        // If character is an operator
        else if (isOperator(c)) {
            cout << "Read operator '" << c << "'\n";
            
            // Pop operators with greater or equal precedence
            while (!operators.empty() && 
                   operators.top() != '(' && 
                   getPrecedence(operators.top()) >= getPrecedence(c)) {
                postfix += operators.top();
                cout << "  Pop '" << operators.top() << "' (higher/equal precedence) to output\n";
                operators.pop();
            }
            
            // Push current operator
            operators.push(c);
            cout << "  Push '" << c << "' to stack\n";
            cout << "  Output: " << postfix << "\n";
            cout << "  Stack:  ";
            displayStack(operators);
            cout << "\n\n";
        }
    }
    
    // Pop remaining operators
    cout << "End of expression - Pop remaining operators:\n";
    while (!operators.empty()) {
        postfix += operators.top();
        cout << "  Pop '" << operators.top() << "' to output\n";
        operators.pop();
    }
    
    cout << "\n========================================\n";
    cout << "Final Postfix: " << postfix << "\n";
    cout << "========================================\n";
    
    return postfix;
}



int main() {
    string infix = "4 * ( 1 + 2 * ( 9 / 3 ) - 5 )";
    
    cout << "========================================\n";
    cout << "SHUNTING-YARD ALGORITHM DEMONSTRATION\n";
    cout << "========================================\n";
    
    // Convert infix to postfix
    string postfix = infixToPostfix(infix);
    
    return 0;
}
