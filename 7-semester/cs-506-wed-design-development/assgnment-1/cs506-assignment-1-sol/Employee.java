//Super class Employee

public class Employee {
    
     //Attributes 
    int id;      
    String name;
    double salary;

    //Default constructor
    public Employee(){
        this.id = 0;
        this.name ="notknown";
        this.salary =0.0;
    }

    //Paramaterized constructor
    public Employee(int id, String name, double salary){
        this.id = id;
        this.name = name;
        this.salary = salary;
    }

    //Method to display employee details
    public void display(){
    System.out.println("in Employee display method");
     System.out.println("Employee ID:" + id + "Name:" + name + "Salary:" + salary );
    }

    //Method return employee information in string
    public String toString(){
        return "Employee ID:" + id + " Name:" + name + "Salary:" + salary; 
    } 
        
    }
    

