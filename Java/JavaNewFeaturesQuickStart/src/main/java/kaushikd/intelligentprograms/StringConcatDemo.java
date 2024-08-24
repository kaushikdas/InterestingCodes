package kaushikd.intelligentprograms;

public class StringConcatDemo {
    public static void main(String[] args) {
        String majorVersion = "1";
        String minorVersion = "8";

        // Regular concatenation
        var version = majorVersion + "." + minorVersion;
        System.out.println("Version: " + version);

        // Using StringBuilder
        StringBuilder strBldr = new StringBuilder("I");
        strBldr.append(" know Java");
        strBldr.insert(7, "C++, ");
        String s1 = strBldr.toString();
        System.out.println(s1);
        strBldr.delete(7, 12);
        System.out.println(strBldr.toString());

        // Using StringBuffer - THREAD SAFE (methods are sync)
        StringBuffer strBuf = new StringBuffer(strBldr.toString());
        strBuf.append(", C"); // I know Java, C
        strBuf.insert(13, "C++, ");
        System.out.println(strBuf.toString()); // I know Java, C++, C
        strBuf.delete(16, 17);
        System.out.println(strBuf.toString()); // I know Java, C++ C
        System.out.println(strBuf.insert(17, "and ").toString());
    }
}

/*
OUTPUT
I know C++, Java
I know Java
I know Java, C++, C
I know Java, C++ C
I know Java, C++ and C
 */
