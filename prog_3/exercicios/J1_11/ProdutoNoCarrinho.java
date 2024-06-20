

public class ProdutoNoCarrinho {
	int qtd;
	double precoTotal;
	Produto prod;
	
	public ProdutoNoCarrinho(int qtd) {
		this.qtd = qtd;
	}
	
	public void criaProduto(String nome,Double preco) {
		this.prod = new Produto();
		prod.setNome(nome);
		prod.setPreco(preco);
	}
	
	public int getQtd() {
		return this.qtd;
	}
	
	public Double getPrecoTotal() {
		this.precoTotal = this.qtd * prod.getPreco();
		return this.precoTotal;
	}
}
