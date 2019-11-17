package class01;

import java.util.Arrays;

/**
 * @author : Zheng Guoliang
 * @version V1.0
 * @Project: java
 * @Package class01
 * @Description:
 * @date Date : 2019年11月17日 21:22
 */


public class Code_03_SelectionSort {
    /**
     * 选择排序
     * 时间复杂度：O(N^2)；空间复杂度：O(1); 稳定性排序
     *
     * @param arr          list
     * @param reverseFlag: true: 升序; false :逆序
     */
    public static void selectionSort(Integer[] arr, boolean reverseFlag) {
        if (arr == null || arr.length < 2) {
            return;
        }
        for (int i = 1; i < arr.length; i++) {
            if (reverseFlag) {
                for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
                    swap(arr, j - 1, j);
                }
            } else {
                for (int j = i; j > 0 && arr[j - 1] < arr[j]; j--) {
                    swap(arr, j - 1, j);
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
            selectionSort(arr, true);
            Arrays.sort(arrcopy, new MyComparatorAsc());
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
            selectionSort(arr, true);
            GenerateData.printData(arr);
        } else {
            System.out.println("排序OK！！！");
            Integer[] arr = GenerateData.generateData(20, 0, 100);
            GenerateData.printData(arr);
            selectionSort(arr, true);
            GenerateData.printData(arr);
        }
    }
}
