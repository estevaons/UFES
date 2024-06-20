import java.util.Comparator;

public class AlturaComparator implements Comparator<Pessoa> {

	public int compare(Pessoa pessoa,Pessoa outraPessoa) {
		if(pessoa.getAltura() > outraPessoa.getAltura()) {
			return 1;
		}
		if(pessoa.getAltura() < outraPessoa.getAltura()) {
			return -1;
		}
		return 0;
	}
}
