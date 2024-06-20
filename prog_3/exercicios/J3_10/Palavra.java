

public class Palavra {
	String palavra;
	String traducao;
	
	public void setPalavra(String data) {
		this.palavra = data;
	}
	
	public void setTraducao(String data) {
		this.traducao = data;
	}
	
	public String getPalavra() {
		return this.palavra;
	}
	
	public String getTraducao() {
		return this.traducao;
	}
	
	public boolean comparaPalavra(String data) {
		if(this.palavra.equals(data)) {
			return true;
		}
		return false;
	}
}
