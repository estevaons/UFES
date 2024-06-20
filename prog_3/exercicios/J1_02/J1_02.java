public class J1_02 {
    public static void main(String[] args){

        int ab=0,cd=0,ef=0,result=0;

        for(int i=1000;i<9999;i++){
            ab = i/100;
            cd = i%100;
            ef = ab+cd;
            result = ef*ef;
            if(i == result){
                System.out.println(i);
            }
        }
    }
}