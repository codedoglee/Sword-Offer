package stack;

import java.util.Stack;

/*
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
 */
public class stack02 {
	public static void main(String[] args)
	{

	}
	Stack<Integer> data = new Stack<Integer>();
	Stack<Integer> mindata = new Stack<Integer>();
	public void push(int node)
	{
		data.push(node);
        if (mindata.isEmpty() || node <= mindata.peek())
        {
        	mindata.push(node);
        }
        else
        {
        	mindata.push(mindata.peek());
        }
    }
    
    public void pop()
    {
        data.pop();
        mindata.pop();
    }
    
    public int top()
    {
        return data.peek();
    }
    
    public int min()
    {
        return mindata.peek();
    }
}
