package class01;

import java.util.Comparator;

/**
 * @author : Zheng Guoliang
 * @version V1.0
 * @Project: java
 * @Package class01
 * @Description:
 * @date Date : 2019年11月17日 21:02
 */


public class MyComparatorAsc implements Comparator<Integer> {
    @Override
    public int compare(Integer o1, Integer o2) {
        return o1 - o2;
    }
}
