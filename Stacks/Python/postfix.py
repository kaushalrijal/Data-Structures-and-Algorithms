def operate(op1, op2, sign):
    if sign == '+':
        return op1 + op2
    elif sign == '-':
        return op1 - op2
    elif sign == '*':
        return op1 * op2
    elif sign == '/':
        return op1 / op2
    elif sign == '^':
        return op1 ** op2
    else:
        print("Invalid Symbol", sign);
        exit(-1)


def evaluate(exp:str):
    stack = []
    tokens = exp.split();

    for token in tokens:
        if token.isdigit() or (token[0] == '-' and token[1].isdigit()):
            stack.append(float(token))
        else:
            op1 = stack.pop()
            op2 = stack.pop()
            result = operate(op2, op1, token)
            stack.append(result)
    
    return stack.pop()

expression = input("Enter the postfix expression: ")
result = evaluate(expression)

print(result)
