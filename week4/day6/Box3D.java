class Box {

    int length;
    int breadth;

    Box(int l, int b) {
        length = l;
        breadth = b;
    }

    int area() {
        return length * breadth;
    }
}

public class Box3D extends Box {

    int height;

    Box3D(int l, int b, int h) {
        super(l, b);
        height = h;
    }

    int volume() {
        return length * breadth * height;
    }

    public static void main(String[] args) {

        Box3D b = new Box3D(5,4,3);

        System.out.println("Area = " + b.area());
        System.out.println("Volume = " + b.volume());
    }
}