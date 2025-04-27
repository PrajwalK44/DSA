import math

def alpha_beta(node, depth, alpha, beta, maximizingPlayer):
    if depth==0 or isinstance(node, int):
        print(f"Reached leaf node with value {node}")
        return node

    if maximizingPlayer:
        maxEval=-math.inf
        print(f"Maximizing value at depth {depth} alpha={alpha} beta={beta}")
        for child in node:
            eval=alpha_beta(child, depth-1, alpha, beta, False)
            maxEval=max(maxEval, eval)
            alpha=max(alpha, eval)
            print(f"Maxval updated to {maxEval} alpha={alpha}")
            if beta<=alpha:
                print(f"Pruning branches at depth {depth} as beta<=alpha")
                break
        
        return maxEval

    else:
        minEval=math.inf
        print(f"Minimizing at depth {depth} with alpha={alpha} beta={beta}")
        for child in node:
            eval=alpha_beta(child, depth-1, alpha, beta, True)
            minEval=min(minEval, eval)
            beta=min(beta, eval)
            print(f"Minimizing value {minEval} with beta={beta}")
            
            if beta<=alpha:
                print(f"Pruning branches at depth {depth} as beta<=alpha")
                break
        
        return minEval

tree = eval(input("Enter the elements in leaf node "))

print("\nAlpha beta pruning")
best_val = alpha_beta(tree, depth=3, alpha =-math.inf, beta=math.inf, maximizingPlayer=True)
print("Best value found ",best_val)