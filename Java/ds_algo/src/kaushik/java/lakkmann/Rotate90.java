package kaushik.java.lakkmann;

public class Rotate90 {
    public static void apply(int[][] buf, int n, boolean anticlock) {
        int srcx, srcy, dstx, dsty, saved;

        for (int level = 0; level < (n>>1); level++) {
            for (int i = 0; i < n-1-(level<<1); i++) {
                // left -> top
                srcx = level;
                srcy = n-1-level-i;
                dstx = level+i;
                dsty = level;
                if (anticlock == true) {
                    int temp = dstx; dstx = srcx; srcx = temp;
                    temp = dsty; dsty = srcy; srcy = temp;
                }
                saved = buf[dsty][dstx];
                buf[dsty][dstx] = buf[srcy][srcx];

                // bottom -> left
                dstx = srcx;
                dsty = srcy;
                srcx = n-1-level-i;
                srcy = n-1-level;
                if (anticlock == true) {
                    int temp = dstx; dstx = srcx; srcx = temp;
                    temp = dsty; dsty = srcy; srcy = temp;
                }
                buf[dsty][dstx] = buf[srcy][srcx];

                // right -> bottom
                dstx = srcx;
                dsty = srcy;
                srcx = n-1-level;
                srcy = level+i;
                if (anticlock == true) {
                    int temp = dstx; dstx = srcx; srcx = temp;
                    temp = dsty; dsty = srcy; srcy = temp;
                }
                buf[dsty][dstx] = buf[srcy][srcx];

                // top -> right
                dstx = srcx;
                dsty = srcy;

                buf[dsty][dstx] = saved;
            }
        }
    }

    public static void main(String[] args) {
        int[][] buf = {
                { 1,  2,  3,  4},
                {12,  1,  2,  5},
                {11,  4,  3,  6},
                {10,  9,  8,  7}
        };

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                System.out.printf("%2d ", buf[i][j]);
            }
            System.out.println();
        }

        Rotate90 rt = new Rotate90();

        rt.apply(buf, 4, false);

        System.out.println();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                System.out.printf("%2d ", buf[i][j]);
            }
            System.out.println();
        }
    }
}
