package other;
/*
 * ����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
 * a^n = a^(n/2)*a^(n/2)��nΪż��
 * a^n = a^((n-1)/2)*a^((n-1)/2)*a��nΪ����
 * ��Ҫ����������0�͸�������
 */
public class other06 {
	public static void main(String[] args)
	{

	}
	boolean invalidInput = false;
	public double Power(double base, int exponent)
	{
		if (base == 0.0 && exponent == 0)
		{
			invalidInput = true;
			return 0;
		}
		if (exponent < 0)
		{
			return 1.0/PowerWithUnsignedExponent(base, -1*exponent);
		}
		else
		{
			return PowerWithUnsignedExponent(base, exponent);
		}
	}
	public static double PowerWithUnsignedExponent(double base, int exponent)
	{
		if (exponent == 0)
		{
			return 1;
		}
		if (exponent == 1)
		{
			return base;
		}
		double result = PowerWithUnsignedExponent(base, exponent >> 1);
		result *=result;
		if ((exponent & 0x1) == 1)
		{
			result *= base;
		}
		return result;
	}
}
