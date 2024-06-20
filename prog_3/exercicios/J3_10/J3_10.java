
import java.util.Scanner;
import java.util.ArrayList;

public class J3_10 {

	public static void main(String[] args) {
		ArrayList <Palavra> dicionario;
		
		dicionario = new ArrayList<>();
		
		Scanner scan = new Scanner(System.in);
		
		String palavra;
		String traducao;
		String entrada;
		String parts[];
		
		while(true) {

			entrada = scan.nextLine();
			parts = entrada.split(" = ");

			palavra = parts[0];
			
			if(palavra.equals(".")) {
				break;
			}
			
			
			traducao = parts[1];
			

			Palavra pal = new Palavra();
			pal.setPalavra(palavra);
			pal.setTraducao(traducao);

			dicionario.add(pal);

		}
		
		int achou = 0;
		
		while(true) {
			palavra = scan.next();
			
			if(palavra.equals(".")) {
				break;
			}
			
			for(Palavra pal : dicionario) {
				if(pal.comparaPalavra(palavra)) {
					System.out.println(pal.getTraducao());
					achou = 1;
				}
			}
			if(achou == 0) {
				System.out.printf("Termo nao encontrado: %s\n",palavra);
			}
			achou = 0;
		}
		
		scan.close();
		
		
	}

}
