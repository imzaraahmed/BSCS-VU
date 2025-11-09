//Sub-class teacher
public class Teacher extends Employee {

    //Attributes
    String qualification;

    //Default constructor
    public Teacher(){
        super();
        this.qualification ="";
    }

    //Parameterized constructor
    public Teacher(int id, String name, double salary, String qualification){
     super(id, name, salary);
     this.qualification = qualification;
    }

    //Overridden display method
    @Override
    public void display(){
        System.out.println("in Teacher display method");
        super.display();
        System.out.println("Teacher Qualification:" + qualification);
    }

      //Overridden Tostring method
      @Override
      public String toString(){
        return super.toString() + "Qualification:" + qualification;

      }

}
