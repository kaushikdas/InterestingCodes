package kaushik.java.hackerrank;

import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

// https://www.hackerrank.com/challenges/queens-attack-2/problem
public class QueenAttackIISolution {
    private static int LEFT_MIN = 0;
    private static int DOWN_MIN = 0;
    private static int RIGHT_MAX = 0;
    private static int TOP_MAX = 0;

    private static int LEFT_DIAG_MIN = 0;       // Left DIAG (/)
    private static int LEFT_DIAG_MAX = 0;
    private static int RIGHT_DIAG_MIN = 0;      // Right DIAG (\)
    private static int RIGHT_DIAG_MAX = 0;

    private static boolean isRight(int r_q, int c_q,
                                   int r_o, int c_o) {
        if (r_q != r_o) return false;

        if (c_o > c_q) {
            // obstacle is to the right of the queen
            RIGHT_MAX = Math.min(RIGHT_MAX, c_o);
            return true;
        }
        return false;
    }

    private static boolean isLeft(int r_q, int c_q,
                                  int r_o, int c_o) {
        if (r_q != r_o) return false;

        if (c_o < c_q) {
            // obstacle is to the left of the queen
            LEFT_MIN = Math.max(LEFT_MIN, c_o);
            return true;
        }
        return false;
    }

    private static boolean isTop(int r_q, int c_q,
                                 int r_o, int c_o) {
        if (c_q != c_o) return false;

        if (r_o > r_q) {
            // obstacle is to the top of the queen
            TOP_MAX = Math.min(TOP_MAX, r_o);
            return true;
        }
        return false;
    }


    private static boolean isDown(int r_q, int c_q,
                                  int r_o, int c_o) {
        if (c_q != c_o) return false;

        if (r_o < r_q) {
            // obstacle is to the top of the queen
            DOWN_MIN = Math.max(DOWN_MIN, r_o);
            return true;
        }
        return false;
    }

    private static boolean isDiag(int r_q, int c_q,
                                  int r_o, int c_o) {
        return Math.abs(r_q - r_o) == Math.abs(c_q - c_o);
    }

    private static boolean isOnLeftDiag(int r_q, int c_q,
                                        int r_o, int c_o) {
        if (!isDiag(r_q, c_q, r_o, c_o))
            return false;

        if ((r_o > r_q) && (c_o > c_q)) {
            // obstacle is left diagonally up
            LEFT_DIAG_MAX = Math.min(LEFT_DIAG_MAX, c_o);
            return true;
        }
        if ((r_o < r_q) && (c_o < c_q)) {
            // obstacle is left diagonally down
            LEFT_DIAG_MIN = Math.max(LEFT_DIAG_MIN, c_o);
            return true;
        }
        return false;
    }

    private static boolean isOnRightDiag(int r_q, int c_q,
                                         int r_o, int c_o) {
        if (!isDiag(r_q, c_q, r_o, c_o))
            return false;

        if ((r_o < r_q) && (c_o > c_q)) {
            // obstacle is right diagonally down
            RIGHT_DIAG_MAX = Math.min(RIGHT_DIAG_MAX, c_o);
            return true;
        }
        if ((r_o > r_q) && (c_o < c_q)) {
            // obstacle is right diagonally up
            RIGHT_DIAG_MIN = Math.max(RIGHT_DIAG_MIN, c_o);
            return true;
        }
        return false;
    }

    private static boolean isInside(int r, int c, int n) {
        if ((r > 0) && (r < n+1)
                && (c > 0) && (c < n+1))
            return true;
        return false;
    }

    public static int queensAttack(int n, int k, int r_q, int c_q,
                                   List<List<Integer>> obstacles) {
        // Mark default right and top boundaries
        RIGHT_MAX = TOP_MAX = n+1;

        LEFT_DIAG_MIN = c_q - Math.min(r_q, c_q);
        LEFT_DIAG_MAX = c_q + (RIGHT_MAX - Math.max(r_q, c_q));

        // Go up along the right diagonal:      c ↓(v), r ↑(^)
        // Go down along the right diagonal:    c ↑(^), r ↓(v)
        int deltaRow = TOP_MAX - r_q;
        int deltaCol = c_q;
        RIGHT_DIAG_MIN = c_q - Math.min(deltaRow, deltaCol);
        RIGHT_DIAG_MIN = Math.max(RIGHT_DIAG_MIN, LEFT_MIN);    // Safety guard

        deltaRow = r_q;
        deltaCol = RIGHT_MAX - c_q;
        RIGHT_DIAG_MAX = c_q + Math.min(deltaRow, deltaCol);
        RIGHT_DIAG_MAX = Math.min(RIGHT_DIAG_MAX, RIGHT_MAX);   // Safety guard

        for (int i = 0; i < k; i++) {
            int r_o = obstacles.get(i).get(0);
            int c_o = obstacles.get(i).get(1);

            if (!isInside(r_o, c_o, n))             continue;
            if (isRight(r_q, c_q, r_o, c_o))        continue;
            if (isLeft(r_q, c_q, r_o, c_o))         continue;
            if (isTop(r_q, c_q, r_o, c_o))          continue;
            if (isDown(r_q, c_q, r_o, c_o))         continue;
            if (isOnLeftDiag(r_q, c_q, r_o, c_o))   continue;
            isOnRightDiag(r_q, c_q, r_o, c_o);
        }

        int attackCnt = 0;
        if (RIGHT_MAX > c_q)
            attackCnt += (RIGHT_MAX - c_q - 1);

        if (LEFT_MIN < c_q)
            attackCnt += (c_q - LEFT_MIN - 1);

        if (TOP_MAX > r_q)
            attackCnt += (TOP_MAX - r_q - 1);

        if (DOWN_MIN < r_q)
            attackCnt += (r_q - DOWN_MIN - 1);

        if (LEFT_DIAG_MAX > c_q)
            attackCnt += (LEFT_DIAG_MAX - c_q - 1);
        if (LEFT_DIAG_MIN < c_q)
            attackCnt += (c_q - LEFT_DIAG_MIN - 1);

        if (RIGHT_DIAG_MAX > c_q)
            attackCnt += (RIGHT_DIAG_MAX - c_q - 1);
        if (RIGHT_DIAG_MIN < c_q)
            attackCnt += (c_q - RIGHT_DIAG_MIN - 1);

        return attackCnt;
    }

    public static void main(String[] args) {
        List<List<Integer>> obstacles = new ArrayList<>();
        obstacles.add(Arrays.asList(20001, 20002));
        obstacles.add(Arrays.asList(20001, 20004));
        obstacles.add(Arrays.asList(20000, 20003));
        obstacles.add(Arrays.asList(20002, 20003));
        obstacles.add(Arrays.asList(20000, 20004));
        obstacles.add(Arrays.asList(20000, 20002));
        obstacles.add(Arrays.asList(20002, 20004));
        obstacles.add(Arrays.asList(20002, 20002));
        obstacles.add(Arrays.asList(564, 323));
        int attackCnt = queensAttack(88587, 9, 20001, 20003, obstacles);
        System.out.println(attackCnt);
    }
}
