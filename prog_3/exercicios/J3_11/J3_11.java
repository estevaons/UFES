import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Locale;



public class J3_11 {

	public static void main(String[] args) {
		Locale.setDefault(new Locale("pt","BR"));
		Scanner scan = new Scanner(System.in);
		
		
		ArrayList <Pessoa> pessoas;
		
		pessoas = new ArrayList<>();
		
		String entrada;
		String parts[];
		
		while(true) {
			entrada = scan.nextLine();
			
			if(entrada.equals(".")) {
				break;
			}
			
			parts = entrada.split(";");
			
			String nome = parts[0];
			int idade = Integer.parseInt(parts[1]);
			
			String alturaS = parts[2].replace(",", ".");
			
			
			double altura = Double.parseDouble(alturaS);
			
			Pessoa p = new Pessoa(nome,idade,altura);
			
			pessoas.add(p);
			

		}
		NomeComparator cNome = new NomeComparator();
		

		Collections.sort(pessoas,cNome);
		
		for(Pessoa pessoa : pessoas) {
			System.out.printf("%s (%d anos, %.2f metros)\n",pessoa.getNome(),pessoa.getIdade(),pessoa.getAltura());
		}
		
		System.out.printf("\n");
		
		IdadeComparator cIdade = new IdadeComparator();
		
		Collections.sort(pessoas,cIdade);

		for(Pessoa pessoa : pessoas) {
			System.out.printf("%s (%d anos, %.2f metros)\n",pessoa.getNome(),pessoa.getIdade(),pessoa.getAltura());
		}
		
		System.out.printf("\n");
		
		AlturaComparator cAltura = new AlturaComparator();
		
		Collections.sort(pessoas,cAltura);
		
		for(Pessoa pessoa : pessoas) {
			System.out.printf("%s (%d anos, %.2f metros)\n",pessoa.getNome(),pessoa.getIdade(),pessoa.getAltura());
		}
		
		scan.close();

	}
}