package other;
/*
 * ���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
 * ����˼·�����Ϊ��1��2��ӵõ�n�м������򷽷���
 */
public class other04 {
	public static void main(String[] args)
	{

	}
	public int RectCover(int target) {
		if (target <= 0)
		{
			return 0;
		}
		if (target == 1)
		{
			return 1;
		}
		if (target == 2)
		{
			return 2;
		}
		int F1 = 1;
		int F2 = 2;
		for (int i = 3; i <= target; ++i)
		{
			F2 = F2 + F1;
			F1 = F2 - F1;
		}
		return F2;
    }
}
