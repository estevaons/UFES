import java.util.Scanner;

public class J1_03 {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int num1 = scan.nextInt();
        int num2 = scan.nextInt();

        int maxDivisor = 0;
        if(num1>=num2){
            for(int i=1;i<=num1;i++){
                if(num1%i == 0 && num2%i == 0){
                    maxDivisor = i;
                }
            }
        }
        if(num2>num1){
            for(int i=1;i<num2;i++){
                if(num1%i == 0 && num2%i == 0){
                    maxDivisor = i;
                }
            }
        }

        System.out.println(maxDivisor);
        scan.close();
    }
}