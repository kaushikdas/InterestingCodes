package kaushikd.intelligentprograms;

public class ThreadMain {
    /*
    public synchronized static void main(String[] args) throws InterruptedException {
        Thread f = new Thread();
        f.start();
        System.out.println("A");
        f.wait(1000);
        System.out.println("B");
    }*/

    private static class MyThread extends Thread {
        @Override
        public void run() {
            System.out.println(Thread.currentThread().getName() + ": Thread run");
            super.run();
            System.out.println(Thread.currentThread().getName() + ": Thread finished");
        }
    }

    public synchronized static void foo() throws InterruptedException {
        MyThread t = new MyThread();
        t.start();
        System.out.println("A");
        t.wait();
        System.out.println("B");
        t.notify();
        while (t.isAlive()) {
            System.out.println("main going to sleep");
            Thread.sleep(100);
        }
    }

    public static void main(String[] args) {
        try {
            foo();
        }
        catch (InterruptedException e) {
            System.out.println("Exception");;
        }
    }
}
