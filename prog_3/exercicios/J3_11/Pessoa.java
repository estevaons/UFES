public class Pessoa  {
	String nome;
	int idade;
	double altura;
	
	public Pessoa(String nome,int idade,Double altura) {
		this.nome = nome;
		this.idade = idade;
		this.altura = altura;
	}

	
	public String getNome() {
		return this.nome;
	}
	public int getIdade() {
		return this.idade;
	}
	public double getAltura() {
		return this.altura;
	}
}
