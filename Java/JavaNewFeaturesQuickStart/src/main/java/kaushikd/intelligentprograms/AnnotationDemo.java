package kaushikd.intelligentprograms;

import java.lang.annotation.Annotation;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;

@Retention(RetentionPolicy.RUNTIME)
@interface MyAnno1 {
    String desc() default "My Annotation ONE";
    int intVal();
}

@Retention(RetentionPolicy.RUNTIME)
@interface MyAnno2 {
    String value(); // This variable name must be value
}

@Retention(RetentionPolicy.RUNTIME)
@interface ThisIsMain {

}

@MyAnno1(desc = "Public class annotation", intVal = 100)
public class AnnotationDemo {
    @MyAnno1(intVal = 50)
    @MyAnno2("Public static method foo")
    public static void foo() {
        AnnotationDemo ad = new AnnotationDemo();

        Class<?> mainClass = ad.getClass();

        Annotation allClassAnnos[] = mainClass.getAnnotations();
        System.out.println("Main class annotations...");
        for (Annotation a : allClassAnnos) {
            System.out.println(a);
        }
        System.out.println("main class MyAnno1: " + mainClass.getAnnotation(MyAnno1.class));
        System.out.println("main class MyAnno1: desc() = "
                + mainClass.getAnnotation(MyAnno1.class).desc()
                + ", intVal() = " + mainClass.getAnnotation(MyAnno1.class).intVal());

        System.out.println("main class MyAnno2: " + mainClass.getAnnotation(MyAnno2.class));

        try {
            Method methodClass = mainClass.getMethod("foo");
            Annotation allMethodAnnos[] = methodClass.getAnnotations();
            System.out.println("foo method annotations");
            for (Annotation a : allMethodAnnos) {
                System.out.println(a);
            }
        }
        catch (NoSuchMethodException e) {

        }
    }

    @ThisIsMain
    public static void main(String[] args) {
        foo();
        System.out.println("Getting annos for main...");
        try {
            Method mainMethod = AnnotationDemo.class.getMethod("main", String[].class);
        }
        catch (NoSuchMethodException e) {

        }
    }
}
