//Main class to test Employee, Manager and Teacher classes
public class Test {

    public static void main(String[] args) {
        System.out.println("Creating Employee, Manager and Teacher objects...");

        // Made objects of each class
        Employee emp1 = new Employee (101, "Ali",  50000.0);
        emp1.display();

        Teacher t1 = new Teacher(102, "Sara", 60000, "PhD");
        t1.display();

        Manager m1 = new Manager(103, "Ahmed", 70000, "IT");
        m1.display();

        // demonstrating Polymorphism
        System.out.println("\n Demonstrating Polymorphism");
        Employee emp2;

        emp2 = new Teacher(104, "Bilal", 65000, "MPhil");
        emp2.display(); // call teacher's display

        emp2 = new Manager(105, "Hina", 80000, "HR");
        emp2.display(); // call manager's display
    }
}
