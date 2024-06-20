import java.util.Scanner;

public class J1_06 {
    public static void main(String[] args) {
        Double matA[][] = new Double[5][4];
        Double matB[][] = new Double[4][6];
        Double matR[][] = new Double[5][6];

        Scanner scan = new Scanner(System.in);

        // leitura da matriz A
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4; j++) {
                matA[i][j] = scan.nextDouble();
            }
        }

        // leitura da matriz B
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 6; j++) {
                matB[i][j] = scan.nextDouble();
            }
        }

        // multiplicando as matrizes

        /*
         * r11 r12 r21 r22
         */

        Double aux=0.0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                aux = 0.0;
                for(int k =0;k<4;k++){
                    aux += matA[i][k]*matB[k][j];
                }
                matR[i][j] = aux;
            }
        }
        // imprimindo matriz resultante
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                System.out.printf("%.2f ", matR[i][j]);
            }
            System.out.printf("\n");
        }

        scan.close();
    }
}