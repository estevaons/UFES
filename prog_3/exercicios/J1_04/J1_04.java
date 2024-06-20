import java.util.Scanner;

public class J1_04 {
    public static void main(String[] args) {
        int vet[] = new int[10];
        int x = 0, a = 0, b = 1, maiorDistancia = 0;
        int maiorQueX = 0, menorQueX = 0, igualX = 0;
        Scanner scan = new Scanner(System.in);
        int cres = 1, decres = 1;
        for (int i = 0; i < 10; i++) {
            vet[i] = scan.nextInt();
        }
        x = scan.nextInt();

        for (int i = 0; i < 9; i++) {

            if (vet[i + 1] < vet[i]) {
                cres = 0;
            }

            if (vet[i + 1] > vet[i]) {
                decres = 0;
            }

            if (vet[i + 1] - vet[i] < 0) {
                if ((vet[i + 1] - vet[i]) * -1 == maiorDistancia) {
                    continue;
                }
                if ((vet[i + 1] - vet[i]) * -1 > maiorDistancia) {
                    maiorDistancia = (vet[i + 1] - vet[i]) * -1;
                    a = i;
                    b = i + 1;
                }
            } else {
                if (vet[i + 1] - vet[i] == maiorDistancia) {
                    continue;
                }
                if (vet[i + 1] - vet[i] > maiorDistancia) {
                    maiorDistancia = vet[i + 1] - vet[i];
                    a = i;
                    b = i + 1;
                }
            }
        }

        for (int j = 0; j < 10; j++) {
            if (vet[j] > x) {
                maiorQueX++;
            }
            if (vet[j] < x) {
                menorQueX++;
            }
            if (vet[j] == x) {
                igualX++;
            }
        }
        // System.out.print(a);
        // System.out.print(b);
        System.out.printf("%d %d ", a, b);

        if (cres == 1 && decres == 1) {
            System.out.print("Nao ordenado ");
        }

        if (cres == 0 && decres == 0) {
            System.out.print("Nao ordenado ");
        }
        if (cres == 1 && decres == 0) {
            System.out.print("Crescente ");
        }
        if (decres == 1 && cres == 0) {
            System.out.print("Decrescente ");
        }

        System.out.printf("%d %d %d\n", maiorQueX, menorQueX, igualX);

        // System.out.print(maiorQueX);
        // System.out.print(menorQueX);
        // System.out.print(igualX);

        scan.close();
    }
}