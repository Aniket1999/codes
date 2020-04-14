public class x {
    public static int len = 0;

    public static int paths(int[][] b, int sx, int sy, String s, int[][] vis, int nowlen) {

        if (sx < 0 || sy < 0 || sx >= b.length || sy >= b[0].length || vis[sx][sy] == 1)
            return 0;

        if (sx == (0) && sy == (3)) {
            System.out.println(s + b[sx][sy] + " ");
            if (nowlen + 1 > len)
                len = nowlen + 1;
            return 1;
        }

        int cnt = 0;
        vis[sx][sy] = 1;
        if (sx + 1 <= b.length - 1) {
            cnt += paths(b, sx + 1, sy, s + b[sx][sy] + " ", vis, nowlen + 1);
        }
        if (sy + 1 <= b[0].length - 1) {
            cnt += paths(b, sx, sy + 1, s + b[sx][sy] + " ", vis, nowlen + 1);
        }
        if (sx - 1 >= 0) {
            cnt += paths(b, sx - 1, sy, s + b[sx][sy] + " ", vis, nowlen + 1);
        }
        if (sy - 1 >= 0) {
            cnt += paths(b, sx, sy - 1, s + b[sx][sy] + " ", vis, nowlen + 1);
        }
        vis[sx][sy] = 0;
        return cnt;
    }

    public static void main(String[] a) {
        int[][] b = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
        int[][] vis = new int[4][4];
        System.out.println(paths(b, 3, 0, "", vis, 0));
        System.out.println(len);
    }
}
