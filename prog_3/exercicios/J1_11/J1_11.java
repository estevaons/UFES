import java.util.Scanner;
import java.util.Locale;

public class J1_11 {

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in).useLocale(Locale.US);
		
		int num = scanner.nextInt(); // ler a quantidade de produtos a serem lidos
		scanner.nextLine(); // Despreza o \n.
		
		CarrinhoDeCompras c = new CarrinhoDeCompras(num);
		
		for (int i = 0; i < num; i++) {
			String nome = scanner.nextLine();
			
			double preco = scanner.nextDouble();
			
			scanner.nextLine(); // Despreza o \n.
			
			int qtd = scanner.nextInt();
			
			scanner.nextLine(); // Despreza o \n.
			
			c.adicionar(nome, preco, qtd);
		}
		
		c.imprimir();
		
		scanner.close();
		
	}

}
