import java.util.Comparator;
import java.text.Collator;
import java.util.Locale;

public class NomeComparator implements Comparator<Pessoa> {
	public int compare(Pessoa pessoa,Pessoa outraPessoa) {
		Collator collator = Collator.getInstance(new Locale("pt", "BR"));
		return collator.compare(pessoa.getNome(), outraPessoa.getNome());
	}
}
