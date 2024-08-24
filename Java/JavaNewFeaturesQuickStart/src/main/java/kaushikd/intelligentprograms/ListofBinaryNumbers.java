package kaushikd.intelligentprograms;

import java.util.LinkedList;
import java.util.Queue;

public class ListofBinaryNumbers {
    /*
       1. Add 1 to queue
       2. Remove e = queue front

       generate(8)

       START        Queue: 1                        generatedCnt = 1
       FRONT 1      Queue: 10 11                    generatedCnt = 3
       FRONT 10     Queue: 11 100 101               generatedCnt = 5
       FRONT 11     Queue: 100 101 110 111          generatedCnt = 7
       FRONT 100    Queue: 101 110 111 1000 1001    generatedCnt = 9
       FRONT 101    Queue: 110 111 1000 1001 1010   generatedCnt = 10
     */
    public static void generate(int n) {
        System.out.println("generate(" + n + ")...");
        if (n < 0) {
            System.out.println("NOTHING TO DISPLAY");
        }
        else if (n == 0) {
            System.out.println("0");
        }
        else {
            Queue<String> binaryNumbers = new LinkedList<>();

            binaryNumbers.add("1");
            int generatedCount = 1;

            while (!binaryNumbers.isEmpty()) {
                String binary = binaryNumbers.remove();
                System.out.printf("%20s%n", binary);
                if (generatedCount < n) {
                    binaryNumbers.add(binary + "0");
                    generatedCount++;
                }
                if (generatedCount < n) {
                    binaryNumbers.add(binary + "1");
                    generatedCount++;
                }
            }
        }
    }

    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);

        for (int i = 0; i < n; i++) {
            generate(Integer.parseInt(args[i + 1]));
        }
    }
}

/*
$ java ListofBinaryNumbers 7 1 0 10 4 3 -4 8
generate(1)...
                   1
generate(0)...
0
generate(10)...
                   1
                  10
                  11
                 100
                 101
                 110
                 111
                1000
                1001
                1010
generate(4)...
                   1
                  10
                  11
                 100
generate(3)...
                   1
                  10
                  11
generate(-4)...
NOTHING TO DISPLAY
generate(8)...
                   1
                  10
                  11
                 100
                 101
                 110
                 111
                1000
 */