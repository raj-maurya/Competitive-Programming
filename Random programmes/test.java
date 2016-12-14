class time
{int h,m,s;
	time()
	{
		h=5;
		m=5;
		s=5;
	}
	time(time &t)
	{
		h=t.h;
		m=t.m;
		s=t.s;
	 }
	void show()
	{
		System.out.println("HOURS="+h+"min="+m+"sec="+s);}
}
class test
{
	public static void main(String args[])
	{
		time t1=new time();
		time t=new time(t1);
		t1.show();
		t.show();
	}
}	
