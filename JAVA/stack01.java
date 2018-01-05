package stack;

import java.util.EmptyStackException;
import java.util.Stack;
/*
 * ������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
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
