#include <bits/stdc++.h> 


void sort_insert(stack<int> &stack, int x){
	if(stack.empty() || x>stack.top()){
		stack.push(x);
		return;
	}

	int num=stack.top();
	stack.pop();
	sort_insert(stack, x);
	stack.push(num);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return ;
	}

	int val=stack.top();
	stack.pop();
	sortStack(stack);
	sort_insert(stack, val);
	
}