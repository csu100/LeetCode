/**
 * @author : Zheng Guoliang
 * @version V1.0
 * @Project: java
 * @Package PACKAGE_NAME
 * @Description:
 * @date Date : 2019年11月17日 17:51
 */


public class pl {
    pm shili = new pm();
    programer xiaohuang = new programer();
    public pl() {
        System.out.println("我是PL！");
    }
    public void angeramentTaskFromPm(){
        shili.analysisTaskFromPD();
        System.out.println("我是PL，我需要将任务进行安排！");
        for (int i=1;i<=100;i++){
            xiaohuang.saySomeWords();
            if (i==50){
                saySomeWords();
            }
        }
    }
    public void saySomeWords(){
        System.out.println("你可以回家啦！");
    }

    public static void main(String[] args) {
        pl xiaomingPl = new pl();
        xiaomingPl.angeramentTaskFromPm();
    }
}
