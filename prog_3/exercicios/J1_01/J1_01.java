public class J1_01 {
    public static void main(String[] args) {
        double S1 = 0, S2 = 0, S3 = 0, num, denom;

        for(int i=0;i<50;i++){
            num = 2*i +1;
            denom = i+1;
            S1 += (num/denom);
        }
        System.out.println("S1 = " + S1);

        num = 1;

        for(int i = 50;i>0;i--){
            num *= 2;
            denom = i;
            S2 += (num/denom);
        }
        System.out.println("S2 = " + S2);

        for(int i=0;i<10;i++){
            num = ((i % 2) == 0)? i + 1 : - (i+1);
            denom = num * num;
            S3 += (num/denom);
        }
        System.out.println("S3 = " + S3);
    }
}