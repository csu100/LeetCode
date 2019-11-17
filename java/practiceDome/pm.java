/**
 * @author : Zheng Guoliang
 * @version V1.0
 * @Project: java
 * @Package PACKAGE_NAME
 * @Description:
 * @date Date : 2019年11月17日 17:51
 */


public class pm {
    pd wangzhi = new pd();
    public pm() {
        System.out.println("我是PM！！");
    }
    public void analysisTaskFromPD(){
        wangzhi.arrangementTaskToPM();
        System.out.println("我是PM，我需要对PD安排的任务进行分解，然后进行任务下发！");
    }
}
