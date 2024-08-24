package kaushikd.intelligentprograms;

import java.time.chrono.ThaiBuddhistEra;
import java.util.concurrent.CountDownLatch;

public class LatchTest {
    public static void main(String[] args) throws InterruptedException {
        CountDownLatch latch = new CountDownLatch(1);

        new Thread(() -> {
            System.out.println("Inside worker, going to sleep");
            try {
                for (int i = 0; i < 5; i++) {
                    System.out.println(".".repeat(i + 1));
                    Thread.sleep(500);
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Worker done");
            //latch.countDown();
        }).start();
        System.out.println(Thread.currentThread() + " going to latch wait");
        latch.await();
        System.out.println(Thread.currentThread() + " done");
        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            System.out.println("Shutdown executed");
        }));
    }
}
