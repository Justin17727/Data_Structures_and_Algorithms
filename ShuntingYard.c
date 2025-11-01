#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char stack[100];  // array stack
int top = -1;     // top pointer of stack

// push symbol to stack
void push(char x){

    // overflow check
    if(top == 99){
        printf("Stack overflow!");
        printf("Exiting the program.\n");
        exit(2);
    }

    stack[++top] = x;
}

// pop symbol from stack
char pop(){
    if(top == -1){
        return '\0';
    }
    else{
        return stack[top--];
    }
}

// symbol priority, lower value for low priority
int priority(char x){
    switch(x){
        case '(':
            return 0;
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// validate input from user
void str_input(char* inp, int size_of_buffer){

    printf("Enter the expression : ");
    fgets(inp, size_of_buffer, stdin);

    // remove '\n' from string buffer
    for(int i = 0; i < size_of_buffer; i++){
        if(inp[i] == '\n'){
            inp[i] = '\0';
            break;
        }

        // if input too long, '\n' not taken in buffer
        if(i == size_of_buffer - 1){
            printf("Entered expression too long!\n");
            printf("Exiting the program.\n");
            exit(2);
        }

        // validate parantheses opening and closing
        
    }
}

int main(){
    
    char exp[100];  // buffer for input expression
    char* e;        // pointer to traverse string buffer 'exp'
    char x;         // popped symbol from stack
    
    // input from user
    str_input(exp, 100);
    
    e = exp;  // initialise pointer 'e' from start address of 'exp'

    // while not reached the end of string buffer
    while(*e != '\0'){
        
        // ignore whitespace character
        if(*e == ' '){
            e++;  // increment pointer to point to nect character in string buffer
            continue;
        }

        // display alpha-numeric character
        else if(isalnum(*e)){
            printf("%c",*e);
        }

        // if open parentheses then push symbol to stack
        else if(*e == '('){
            push(*e);
        }

        // if close parentheses then pop & display symbols until encounter open parentheses
        else if(*e == ')'){
            while((x = pop()) != '(')
                printf("%c", x);
        }

        // if encounter a symbol
        else{

            // if symbol priority lower than or equal to top symbol in stack
            while(priority(stack[top]) >= priority(*e)){

                // if symbol and top element of stack are '^'
                if(priority(*e) == 3 && priority(stack[top]) == 3){
                    break;
                }

                // if both not '^'
                else{
                    printf("%c", pop());
                }
            }

            // push symbol to stack
            push(*e);
        }
        
        e++;  // increment pointer to point at next character in string buffer
    }

    // if stack not empty
    while(top != -1){
        printf("%c", pop());
    }
    printf("\n");

    return 0;
}
