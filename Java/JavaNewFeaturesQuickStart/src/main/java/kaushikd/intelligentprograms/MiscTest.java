package kaushikd.intelligentprograms;

class Student {
    String name;
    int age;
}

class MyException extends Exception {
    int detail;

    public MyException(int n, Exception cause) {
        super.initCause(cause);
        detail = n;
    }

    public String toSring() {
        return "Error: " + detail + ", cause: " + super.getCause();
    }
}

public class MiscTest {
    public static void foo() throws Exception {
        throw new MyException(10, new NullPointerException("nullptr"));
    }

    public static void main(String[] args) {
        try {
            foo();
        }
        catch (MyException e) {
            System.out.println("ONE: " + e);
        }
        catch (Exception e) {
            System.out.println("TWO: " + e);
        }
    }
}
