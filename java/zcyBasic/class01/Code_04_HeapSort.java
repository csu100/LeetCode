package class01;

import java.util.Arrays;

/**
 * @author : Zheng Guoliang
 * @version V1.0
 * @Project: java
 * @Package class01
 * @Description:
 * @date Date : 2019年11月17日 21:36
 */


public class Code_04_HeapSort {
    /**
     * 堆排序 升序
     * 时间复杂度：O(NlogN) 空间复杂度：O(1); 不稳定性排序
     *
     * @param arr list
     */
    public static void heapSort(Integer[] arr) {
        if (arr == null || arr.length < 2) {
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            heapInsert(arr, i);
        }
        int len = arr.length;
        swap(arr, 0, --len);
        while (len > 0) {
            heapfy(arr, 0, len);
            swap(arr, 0, --len);
        }
    }

    /**
     * 堆排序 逆序
     *时间复杂度：O(NlogN) 空间复杂度：O(1); 不稳定性排序
     *
     * @param arr
     */
    public static void heapSortDesc(Integer[] arr) {
        if (arr == null || arr.length < 2) {
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            heapInsertDesc(arr, i);
        }
        int len = arr.length;
        swap(arr, 0, --len);
        while (len > 0) {
            heapfyDesc(arr, 0, len);
            swap(arr, 0, --len);
        }
    }

    /**
     * 建立小根堆
     *
     * @param arr
     * @param index
     */
    public static void heapInsertDesc(Integer[] arr, int index) {
        while (arr[(index - 1) / 2] > arr[index]) {
            swap(arr, index, (index - 1) / 2);
            index = (int) ((index - 1) / 2);
        }
    }

    public static void heapfyDesc(Integer[] arr, int index, int length) {
        int left = 2 * index + 1;
        while (left < length) {
            int smallindex = left + 1 < length && arr[left + 1] < arr[left] ? left + 1 : left;
            smallindex = arr[smallindex] < arr[index] ? smallindex : index;
            if (smallindex == index) {
                return;
            }
            swap(arr, smallindex, index);
            index = smallindex;
            left = 2 * index + 1;
        }
    }

    public static void heapfy(Integer[] arr, int index, int length) {
        int left = index * 2 + 1;
        while (left < length) {
            int lagestIndex = left + 1 < length && arr[left + 1] > arr[left] ? left + 1 : left;
            lagestIndex = arr[lagestIndex] > arr[index] ? lagestIndex : index;
            if (lagestIndex == index) {
                return;
            }
            swap(arr, index, lagestIndex);
            index = lagestIndex;
            left = index * 2 + 1;
        }
    }

    public static void heapInsert(Integer[] arr, int index) {
        while (arr[(index - 1) / 2] < arr[index]) {
            swap(arr, index, (index - 1) / 2);
            index = (int) ((index - 1) / 2);
        }
    }

    public static void swap(Integer[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        boolean flag = true;
        for (int i = 1; i < 1000 && flag; i++) {
            Integer[] arr = GenerateData.generateData(i, 0, 100);
            Integer[] arrcopy = GenerateData.copyData(arr);
            heapSortDesc(arr);
            Arrays.sort(arrcopy, new MyComparatorDesc());
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
            heapSortDesc(arr);
            GenerateData.printData(arr);
        } else {
            System.out.println("排序OK！！！");
            Integer[] arr = GenerateData.generateData(20, 0, 100);
            GenerateData.printData(arr);
            heapSortDesc(arr);
            GenerateData.printData(arr);
        }
    }

}
