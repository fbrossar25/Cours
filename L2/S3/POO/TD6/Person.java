public class Person implements Comparable<Person>{
	private int birth;
	private String firstName,lastName;

	Person(){
		this("","",0);
	}

	Person(String firstName,String lastName,int birth){
		this.firstName = firstName;
		this.lastName = lastName;
		this.birth = birth;
	}

	public int compareTo(Person that){
		if(birth != that.birth) return birth - that.birth;
		else if(lastName.compareTo(that.lastName) != 0) return lastName.compareTo(that.lastName);
		else return firstName.compareTo(that.firstName);
	}
}