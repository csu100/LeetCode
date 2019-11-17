package class01;

import java.util.Arrays;

/**
 * @author : Zheng Guoliang
 * @version V1.0
 * @Project: java
 * @Package class01
 * @Description:
 * @date Date : 2019年11月17日 23:25
 */


public class Code_05_MergeSort {
    /**
     * 归并排序
     * 时间复杂度：O(NlogN)； 空间复杂度：O(N)， 稳定性排序
     * @param arr list
     * @param reverseFlag: true：升序；false：降序
     */
    public static void mergeSort(Integer[] arr, boolean reverseFlag) {
        if (arr == null || arr.length < 2) {
            return;
        }
        partition(arr, 0, arr.length - 1, reverseFlag);
    }

    private static void partition(Integer[] arr, int L, int R, boolean reverseFlag) {
        if (L == R) {
            return;
        }
        int mid = L + ((R - L) >> 1);
        partition(arr, L, mid, reverseFlag);
        partition(arr, mid + 1, R, reverseFlag);
        mergeSorts(arr, L, R, mid, reverseFlag);
    }

    private static void mergeSorts(Integer[] arr, int L, int R, int mid, boolean reverseFlag) {
        int i = L;
        int j = mid + 1;
        Integer[] help = new Integer[R - L + 1];
        int index = 0;
        while (i <= mid && j <= R) {
            if (reverseFlag) {
                help[index++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
            } else {
                help[index++] = arr[i] > arr[j] ? arr[i++] : arr[j++];
            }
        }
        while (i <= mid) {
            help[index++] = arr[i++];
        }
        while (j <= R) {
            help[index++] = arr[j++];
        }
        for (int k = 0; k < help.length; k++) {
            arr[L + k] = help[k];
        }
    }

    public static void main(String[] args) {
        boolean flag = true;
        boolean reverseFlag = true;
        for (int i = 1; i < 5000 && flag; i++) {
            Integer[] arr = GenerateData.generateData(i, 0, 100);
            Integer[] arrcopy = GenerateData.copyData(arr);
            mergeSort(arr, reverseFlag);
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
            mergeSort(arr, reverseFlag);
            GenerateData.printData(arr);
        } else {
            System.out.println("排序OK！！！");
            Integer[] arr = GenerateData.generateData(20, 0, 100);
            GenerateData.printData(arr);
            mergeSort(arr, reverseFlag);
            GenerateData.printData(arr);
        }
    }


}
