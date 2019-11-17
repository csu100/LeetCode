package class01;

import com.sun.xml.internal.ws.addressing.WsaTubeHelperImpl;

import java.util.Arrays;

/**
 * @author : Zheng Guoliang
 * @version V1.0
 * @Project: java
 * @Package class01
 * @Description:
 * @date Date : 2019年11月17日 22:35
 */


public class Code_04_QuickSort {

    public static void quickSort(Integer[] arr, boolean reverseFlag) {
        if (arr == null || arr.length < 2) {
            return;
        }
        quickSort(arr, 0, arr.length - 1, reverseFlag);
    }

    public static void quickSort(Integer[] arr, int L, int R, boolean reverseFlag) {
        if (L < R) {
            swap(arr, R, (int) (Math.random() * (R - L) + L));
            Integer[] temp = new Integer[2];
            if (reverseFlag) {
                temp = partionSortAsc(arr, L, R);
            } else {
                temp = partionSortDesc(arr, L, R);
            }
            quickSort(arr, L, temp[0] - 1, reverseFlag);
            quickSort(arr, temp[1] + 1, R, reverseFlag);
        }
    }

    public static Integer[] partionSortDesc(Integer[] arr, int L, int R) {
        int less = L - 1;
        int more = R + 1;
        int temp = arr[R];
        while (L < more) {
            if (arr[L] > temp) {
                swap(arr, ++less, L++);
            } else if (arr[L] == temp) {
                L++;
            } else {
                swap(arr, L, --more);
            }
        }
        return new Integer[]{less + 1, more - 1};
    }

    public static Integer[] partionSortAsc(Integer[] arr, int L, int R) {
        int less = L - 1;
        int more = R + 1;
        int temp = arr[R];
        while (L < more) {
            if (arr[L] < temp) {
                swap(arr, L++, ++less);
            } else if (arr[L] == temp) {
                L++;
            } else {
                swap(arr, L, --more);
            }
        }
        return new Integer[]{less + 1, more - 1};
    }

    public static void swap(Integer[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        boolean flag = true;
        boolean reverseFlag = false;
        for (int i = 1; i < 5000 && flag; i++) {
            Integer[] arr = GenerateData.generateData(i, 0, 100);
            Integer[] arrcopy = GenerateData.copyData(arr);
            quickSort(arr, reverseFlag);
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
            quickSort(arr, reverseFlag);
            GenerateData.printData(arr);
        } else {
            System.out.println("排序OK！！！");
            Integer[] arr = GenerateData.generateData(20, 0, 100);
            GenerateData.printData(arr);
            quickSort(arr, reverseFlag);
            GenerateData.printData(arr);
        }
    }

}
