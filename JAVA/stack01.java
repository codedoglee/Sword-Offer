package stack;

import java.util.EmptyStackException;
import java.util.Stack;
/*
 * 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
 */
public class stack01 {
	public static void main(String[] args) {
		
	}
	Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();
    
    public void push(int node) {
    	stack1.push(node);
    	if (stack2.isEmpty())
    	{
    		while (!stack1.isEmpty())
    		{
    			stack2.push(stack1.pop());
    		}
    	}
    }
    
    public int pop() {
    	if (stack2.isEmpty())
    	{
    		if (!stack1.isEmpty())
    		{
    			while (!stack1.isEmpty())
        		{
        			stack2.push(stack1.pop());
        		}
    		}
    		else
    		{
    			throw new EmptyStackException();
    		}
    	}
    	return stack2.pop();
    }
}
