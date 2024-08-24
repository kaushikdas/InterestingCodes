package kaushikd.intelligentprograms;

import java.util.Random;
import java.util.concurrent.Semaphore;

class Queue {
    private Semaphore prodSem;
    private Semaphore conSem;
    private int val;

    public Queue() {
        prodSem = new Semaphore(1);
        conSem = new Semaphore(0);
        val = 0;
    }

    public void put(int v) {
        try {
            prodSem.acquire();
            val = v;
            conSem.release();
        }
        catch (InterruptedException e) {
            System.err.println(Thread.currentThread().getName() + " (put) interrupted");
        }
    }

    public int get() {
        int v = -1;
        try {
            conSem.acquire();
            v = val;
            prodSem.release();
        }
        catch (InterruptedException e) {
            System.err.println(Thread.currentThread().getName() + " (get) interrupted");
        }
        finally {
            return v;
        }
    }
}

class Producer implements Runnable {
    private Queue q;
    public Thread t;

    public Producer(Queue q) {
        this.q = q;
        t = new Thread(this, "Producer");
        t.start();
    }

    @Override
    public void run() {
        Random random = new Random();
        try {
            for (int i = 0; i < 5; i++) {
                int v = random.nextInt(100) + 1;
                System.out.println("Producing value " + v);
                q.put(v);
                Thread.sleep(1000);
            }
            q.put(-1);
            System.out.println();
        }
        catch (InterruptedException e) {
            System.err.println(Thread.currentThread().getName() + " interrupted");
        }
        System.out.println("Producer done!");
    }
}

class Consumer implements Runnable {
    private Queue q;
    public Thread t;

    public Consumer(Queue q) {
        this.q = q;
        t = new Thread(this, "Consumer");
        t.start();
    }

    @Override
    public void run() {
        try {
            int v = 0;
            System.out.println(Thread.currentThread().getName() + " trying to read from q...");
            while ((v = q.get()) != -1) {
                System.out.println(Thread.currentThread().getName() + " got " + v);
                Thread.sleep(1000);
            }
        }
        catch (InterruptedException e) {
            System.err.println(Thread.currentThread().getName() + " interrupted");
        }
        System.out.println("Consumer done!");
    }
}

public class ProducerConsumerDemo {
    public static void main(String[] args) throws InterruptedException {
        Queue q = new Queue();
        Producer prod = new Producer(q);
        Consumer con = new Consumer(q);

        prod.t.join();
        con.t.join();
    }
}
