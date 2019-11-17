package class01;

import java.util.Arrays;
import java.util.Collections;

/**
 * @author : Zheng Guoliang
 * @version V1.0
 * @Project: java
 * @Package class01
 * @Description: 插入排序
 * @date Date : 2019年11月17日 20:49
 */


public class Code_02_InsertionSort {
    /**
     * 选择排序
     * 时间复杂度：O(N^2); 空间复杂度：O(1); 不稳定性排序
     *
     * @param arr         传入数据
     * @param reverseflag true：升序; false: 逆序
     */
    public static void insertionSort(Integer[] arr, boolean reverseflag) {
        if (arr == null || arr.length < 2) {
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            int temp = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (reverseflag) {
                    if (arr[temp] > arr[j]) {
                        temp = j;
                    }
                } else {
                    if (arr[temp] < arr[j]) {
                        temp = j;
                    }
                }
            }
            swap(arr, i, temp);
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
            insertionSort(arr, true);
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
            insertionSort(arr, true);
            GenerateData.printData(arr);
        } else {
            System.out.println("排序OK！！！");
            Integer[] arr = GenerateData.generateData(20, 0, 100);
            GenerateData.printData(arr);
            insertionSort(arr, true);
            GenerateData.printData(arr);
        }
    }

}
