# A program in python to convert infix expressions to postfix

precedence = {
    '^': 3,
    '*': 2,
    '/': 2,
    '+': 1,
    '-': 1,
    '(': 0,
    ')': 0
}

def convert(infix):
    postfix = ""
    stack = []

    tokens = infix.split()

    for token in tokens:
        if token.isdigit():
            postfix += token + " "
        elif token == '(':
            stack.append(token)
        elif token == ')':
            while stack and stack[-1] != '(':
                postfix += stack.pop() + " "
            stack.pop() 
        else: 
            if stack and precedence[token] > precedence[stack[-1]]:
                stack.append(token)
            else:
                while stack and stack[-1] != '(' and precedence[token] <= precedence[stack[-1]]:
                    postfix += stack.pop() + " "
                stack.append(token)

    while stack:
        postfix += stack.pop() + " "

    return postfix

infix = input("Enter the infix expression: ")
postfix = convert(infix)
print(f"The expression in postfix form is: {postfix}")