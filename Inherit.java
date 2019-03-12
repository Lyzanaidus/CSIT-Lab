import java.util.*;

class Employee
{
	int eid;
	String name;
	float salary;

	void getData()
	{
		System.out.print("\n\t\t-------- * Enter Data * --------  ");
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("\n\t\t\tEnter eid :-");
		eid=sc.nextInt();
		System.out.print("\n\t\t\tEnter name :-");
		name=sc.next();
		System.out.print("\n\t\t\tEnter salary :-");
		salary=sc.nextFloat();
		
	}
	void show()
	{
		System.out.print("\n\t\t-------- * Displaying Data * --------  ");
		
		System.out.print("\n\t\t\tEid :-" + eid);
		System.out.print("\n\t\t\tName :-" + name);
		System.out.print("\n\t\t\tSalary :-" + salary);
		
	}
}

class Typist extends Employee
{
	int type_speed;

	void getData()
	{
		super.getData();

		Scanner sc = new Scanner(System.in);
		
		System.out.print("\n\t\t\tEnter Type speed :-");
		type_speed=sc.nextInt();
		
		
	}
	void show()
	{
		super.show();

		System.out.print("\n\t\t\tType speed :-" + type_speed);
	}
}

class Manager extends Employee
{
	String dept;

	void getData()
	{
		super.getData();

		Scanner sc = new Scanner(System.in);
		
		System.out.print("\n\t\t\tEnter Department :-");
		dept=sc.next();
		
		
	}
	void show()
	{
		super.show();

		System.out.print("\n\t\t\tDepartment :-" + dept);
	}
}

class Inherit
{
	public static void main (String[] a)
	{
		Typist t = new Typist();
		t.getData();
		t.show();
		
		Manager m = new Manager();
		m.getData();
		m.show();

	}
}