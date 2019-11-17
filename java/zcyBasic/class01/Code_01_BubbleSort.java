package class01;

import java.util.Arrays;

/**
 * @author : Zheng Guoliang
 * @version V1.0
 * @Project: java
 * @Package class01
 * @Description: 冒泡排序
 * @date Date : 2019年11月17日 20:26
 */


public class Code_01_BubbleSort {

    /**
     * 冒泡排序
     * 时间复杂度：O(N^2)；空间复杂度：O(1)；稳定性排序
     *
     * @param arr         传入数据
     * @param reverseFlag true: 升序；false:降序
     */
    public static void bubbleSort(Integer[] arr, boolean reverseFlag) {
        if (arr == null || arr.length < 2) {
            return;
        }
        boolean flag = true;
        for (int i = 0; i < arr.length && flag; i++) {
            flag = false;
            for (int j = arr.length - 1; j > i; j--) {
                if (reverseFlag) {
                    if (arr[j - 1] > arr[j]) {
                        flag = true;
                        swap(arr, j - 1, j);
                    }
                } else {
                    if (arr[j - 1] < arr[j]) {
                        flag = true;
                        swap(arr, j - 1, j);
                    }
                }
            }
        }
    }

    private static void swap(Integer[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }


    public static void main(String[] args) {
        boolean flag = true;
        for (int i = 1; i < 1000 && flag; i++) {
            Integer[] arr = GenerateData.generateData(i, 0, 100);
            Integer[] arrcopy = GenerateData.copyData(arr);
            bubbleSort(arr, true);
            Arrays.sort(arrcopy);
            for (int j = 0; j < arr.length; j++) {
                if (!arr[j].equals(arrcopy[j])) {
                    System.out.println("排序错误！！");
                    flag = false;
                    break;
                }
            }
        }
        if (!flag) {
            Integer[] arr = GenerateData.generateData(20, 0, 100);
            GenerateData.printData(arr);
            bubbleSort(arr, true);
            GenerateData.printData(arr);
        } else {
            System.out.println("排序OK！！！");
            Integer[] arr = GenerateData.generateData(20, 0, 100);
            Integer[] arrcopy = GenerateData.copyData(arr);
            GenerateData.printData(arr);
            bubbleSort(arr, true);
            Arrays.sort(arrcopy, new MyComparatorAsc());
            GenerateData.printData(arr);
            GenerateData.printData(arrcopy);
        }
    }
}
