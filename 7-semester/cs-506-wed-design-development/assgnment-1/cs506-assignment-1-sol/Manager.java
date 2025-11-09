//Sub-class of Employee
public class Manager extends Employee {
    
    //Attributes
    String department;

    //Default constructor
    public Manager(){
       super();
        this.department = "notdefine";
    }

    //Parametrized constructor
    public Manager(int id, String name, double salary, String department){
        super(id, name, salary);
        this.department = department;
    }
    //Override display method
    @Override
    public void display(){
        System.out.println("in Manager display method");
        super.display();
         System.out.println(" Manager Department:" + department);
    }

    //Override tostring method
      @Override
      public String toString(){
        return super.toString() + "Department:" + department;

      }

}
