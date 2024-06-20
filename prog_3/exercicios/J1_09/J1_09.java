import java.util.Scanner;
import java.util.Locale;

public class J1_09{
    public static void main(String[] args){

        Scanner scan = new Scanner(System.in).useLocale(Locale.US);

        // final var localeAmericano = new Locale("en","US");

        int n = scan.nextInt();
        

        Aluno[] als = new Aluno[n];
        

        for(int i=0;i<n;i++){
            als[i] = new Aluno();
            als[i].nome = scan.next();
            als[i].p1 = scan.nextDouble();
            als[i].p2 = scan.nextDouble();
            als[i].p3 = scan.nextDouble();
        }

        double mediaTurma = 0;

        for(int i=0;i<n;i++){
            mediaTurma += als[i].getMedia();
        }

        mediaTurma = mediaTurma/n;

        for(int i=0;i<n;i++){
            if(als[i].getMedia() > mediaTurma){
                als[i].setMediaTurmaAcima("Acima");
            }
            if(als[i].getMedia() == mediaTurma){
                als[i].setMediaTurmaNaMedia("Na media");
            }
            if(als[i].getMedia() < mediaTurma){
                als[i].setMediaTurmaAbaixo("Abaixo");
            }
        }

        System.out.printf("Nome,Nota,Situacao,Media\n");

        for(int i=0;i<n;i++){
            if(als[i].getMedia() >= 7.0){
                System.out.printf("%s,%.1f,Aprovado,%s\n",als[i].getNome(),als[i].getMedia(),als[i].getMediaTurma());
            }else{
                System.out.printf("%s,%.1f,Prova Final,%s\n",als[i].getNome(),als[i].getMedia(),als[i].getMediaTurma());
            }
        }

        scan.close();
    }
}