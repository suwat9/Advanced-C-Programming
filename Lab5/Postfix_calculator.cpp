#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Function to check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to perform arithmetic operations
int performOperation(int operand1, int operand2, char operation) {
    switch(operation) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': 
            if (operand2 == 0) {
                cout << "Error: Division by zero!" << endl;
                return 0;
            }
            return operand1 / operand2;
        default: return 0;
    }
}

// Function to evaluate postfix expression
int evaluatePostfix(string expression) {
    stack<int> s;
    
    cout << "\nStep-by-step evaluation:\n";
    cout << "------------------------\n";
    
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        
        // If character is a digit, push to stack
        if (isdigit(c)) {
            s.push(c - '0');  // Convert char to int
            cout << "Push " << (c - '0') << " | Stack: ";
            
            // Display stack
            stack<int> temp = s;
            int arr[100], idx = 0;
            while (!temp.empty()) {
                arr[idx++] = temp.top();
                temp.pop();
            }
            cout << "[";
            for (int j = idx - 1; j >= 0; j--) {
                cout << arr[j];
                if (j > 0) cout << ", ";
            }
            cout << "]\n";
        }
        // If character is an operator
        else if (isOperator(c)) {
            if (s.size() < 2) {
                cout << "Error: Invalid expression!" << endl;
                return 0;
            }
            
            // Pop two operands
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            
            // Perform operation
            int result = performOperation(operand1, operand2, c);
            
            // Push result back
            s.push(result);
            
            cout << "Pop " << operand2 << " and " << operand1 
                 << ", compute " << operand1 << c << operand2 
                 << " = " << result << " | Stack: ";
            
            // Display stack
            stack<int> temp = s;
            int arr[100], idx = 0;
            while (!temp.empty()) {
                arr[idx++] = temp.top();
                temp.pop();
            }
            cout << "[";
            for (int j = idx - 1; j >= 0; j--) {
                cout << arr[j];
                if (j > 0) cout << ", ";
            }
            cout << "]\n";
        }
    }
    
    // Final result should be the only element in stack
    if (s.size() != 1) {
        cout << "Error: Invalid expression!" << endl;
        return 0;
    }
    
    return s.top();
}

int main() {
    string expression = "41293/*+5-*";
    
    cout << "Postfix Expression: " << expression << endl;
    
    int result = evaluatePostfix(expression);
    
    cout << "\n========================\n";
    cout << "Final Result: " << result << endl;
    cout << "========================\n";
    
    return 0;
}
