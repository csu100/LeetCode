package class01;

/**
 * @author : Zheng Guoliang
 * @version V1.0
 * @Project: java
 * @Package class01
 * @Description:
 * @date Date : 2019年11月17日 20:37
 */


public class GenerateData {
    public static Integer[] generateData(int n, int L, int R) {
        if (n < 1 || L > R) {
            return null;
        }
        Integer[] number = new Integer[n];
        for (int i = 0; i < n; i++) {
            int temp = (int) (Math.random() * (R - L) + L);
            number[i] = temp;
        }
        return number;
    }

    public static Integer[] copyData(Integer[] number) {
        if (number == null || number.length < 1) {
            return null;
        }
        Integer[] datas = new Integer[number.length];
        for (int i = 0; i < number.length; i++) {
            datas[i] = number[i];
        }
        return datas;
    }

    public static void printData(Integer[] number) {
        if (number == null || number.length < 1) {
            return;
        }
        for (int i = 0; i < number.length; i++) {
            System.out.print(number[i] + "\t");
        }
        System.out.println();
    }
}
