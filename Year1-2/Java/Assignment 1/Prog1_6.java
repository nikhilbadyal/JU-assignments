
class Prog1_6
{
	static void show(int i)
	{
		System.out.println("Inside show function"+i);
	}
	
	static void show(double d)
	{
		System.out.println("Inside show function"+d);
	}
	
	public static void main(String args[])
	{
		short s=5;
		show(s);
		double d= 5.56;
		show(d);  
	}
}