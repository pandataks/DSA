class Outer {

    void display() {
        System.out.println("Outer Class");
    }

    class Inner {

        void display() {
            System.out.println("Inner Class");
        }
    }
}

public class Main {

    public static void main(String[] args) {

        Outer o = new Outer();
        o.display();

        Outer.Inner i = o.new Inner();
        i.display();
    }
}