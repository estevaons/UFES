import java.util.Scanner;
public class J1_05 {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        
        int vet[] = new int[10];
        int check =1;

        for(int i=0;i<10;i++){
            vet[i] = scan.nextInt();
        }

        int razao = vet[1]-vet[0];

        for(int i=0;i<9;i++){
            if(!(vet[i+1]-vet[i]==razao)){
                check = 0;
            }
        }
        if(check == 1){
            System.out.printf("Sim %d %d\n",vet[0],razao);
        }
        else{
            System.out.printf("Nao\n");
        }

        scan.close();
    }
}