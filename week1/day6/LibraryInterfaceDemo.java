public class LibraryInterfaceDemo {

    public static void main(String[] args) {

        System.out.println("===== Test Case 1 : Kid User =====");

        KidUser kid1 = new KidUser(10, "Kids");
        kid1.registerAccount();
        kid1.requestBook();

        System.out.println();

        KidUser kid2 = new KidUser(18, "Fiction");
        kid2.registerAccount();
        kid2.requestBook();

        System.out.println("\n===== Test Case 2 : Adult User =====");

        AdultUser adult1 = new AdultUser(5, "Kids");
        adult1.registerAccount();
        adult1.requestBook();

        System.out.println();

        AdultUser adult2 = new AdultUser(23, "Fiction");
        adult2.registerAccount();
        adult2.requestBook();
    }
}