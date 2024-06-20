import java.util.Scanner;
import java.util.Locale;

public class J1_07{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in).useLocale(Locale.US);

        final var localeAmericano = new Locale("en","US");

        Triangulo tri = new Triangulo();


        tri.a.x = scan.nextDouble();
        tri.a.y = scan.nextDouble();

        tri.b.x = scan.nextDouble();
        tri.b.y = scan.nextDouble();

        tri.c.x = scan.nextDouble();
        tri.c.y = scan.nextDouble();

        double perimetroTri = tri.perimetro();


        System.out.printf(localeAmericano,"%.5f\n",perimetroTri);

        scan.close();
        
    }
}