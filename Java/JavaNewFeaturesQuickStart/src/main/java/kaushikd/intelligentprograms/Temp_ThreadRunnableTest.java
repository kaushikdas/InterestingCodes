package kaushikd.intelligentprograms;

class MyThread implements Runnable {
    Thread t;

    MyThread(String s) {
        t = new Thread(this, s);
    }

    public void go() {
        t.start();
    }

    @Override
    public void run() {
        try {
            for (int i = 5; i > 0; i--) {
                System.out.println(i + " > From " + t.getName());
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println(t.getName() + " interrupted");
            ;
        }
        System.out.println("Bye from " + Thread.currentThread().getName());
    }
}

public class Temp_ThreadRunnableTest {
    public static void main(String[] args) throws InterruptedException {
        MyThread t = new MyThread("ForTest");
        t.go();
        System.out.println(Thread.currentThread().getName() + " going to sleep for 10 s...");
        Thread.sleep(10_000);
        System.out.println("Bye from " + Thread.currentThread().getName() + "!");
    }
}
