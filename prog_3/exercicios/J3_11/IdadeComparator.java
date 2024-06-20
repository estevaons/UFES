

import java.util.Comparator;

public class IdadeComparator implements Comparator<Pessoa> {
	public int compare(Pessoa pessoa, Pessoa outraPessoa) {
		if(pessoa.getIdade() > outraPessoa.getIdade()) {
			return -1;
		}
		if(pessoa.getIdade() < outraPessoa.getIdade()) {
			return 1;
		}
		return 0;
	}
}
