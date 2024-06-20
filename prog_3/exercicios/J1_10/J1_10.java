import java.util.Scanner;

public class J1_10{
    public static void main(String[] args){

        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();

        if(n == 0 || n<0 || n>47){
            System.out.printf("\n");
            System.exit(0);
        }

        if(n == 1){
            System.out.printf("0 \n");
            System.exit(0);
        }

        int vet[] = new int[n];

        vet[0] = 0;
        vet[1] = 1;

        for(int i=2;i<n;i++){
            vet[i] = vet[i-2]+vet[i-1];
        }

        for(int j=0;j<n;j++){
            System.out.printf("%d ",vet[j]);
        }
        System.out.printf("\n");
        scan.close();
    }
}