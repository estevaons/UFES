import java.util.ArrayList;

public class CarrinhoDeCompras {
	int qtdProdutosNoCarrinho;
	double precoCarrinho;
	ArrayList <ProdutoNoCarrinho> produtosCarrinho;
	
	public CarrinhoDeCompras(int qtd) {
		this.qtdProdutosNoCarrinho = qtd;
		this.produtosCarrinho = new ArrayList<>();
	}
	
	public void adicionar(String nome,Double preco,int qtd) {
		ProdutoNoCarrinho prod = new ProdutoNoCarrinho(qtd);
		prod.criaProduto(nome, preco);
		produtosCarrinho.add(prod);	
	}
	
	public void imprimir() {

		for (ProdutoNoCarrinho produtoNoCarrinho : produtosCarrinho) {
			precoCarrinho += produtoNoCarrinho.getPrecoTotal();
		}

		System.out.printf("No carrinho:\n");

		for(ProdutoNoCarrinho produtoNoCarrinho : produtosCarrinho) {
			
			System.out.printf("* %dx %s = R$ %.2f\n",produtoNoCarrinho.getQtd(),produtoNoCarrinho.prod.getNome(),produtoNoCarrinho.getPrecoTotal());
			
		}

		System.out.printf("Total: R$ %.2f\n",this.precoCarrinho);
	}
	
}
