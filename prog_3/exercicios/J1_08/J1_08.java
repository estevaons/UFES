import java.util.Scanner;
import java.util.Locale;



public class J1_08{
    public static void main(String[] args){

        Scanner scan = new Scanner(System.in).useLocale(Locale.US);

        Locale local = new Locale("pt","BR");

        String nomeDaEmpresa = scan.next();
        String cnpjDaEmpresa = scan.next();
        int numDepEmpresa = scan.nextInt();

        Empresa empresa = new Empresa(nomeDaEmpresa,cnpjDaEmpresa,numDepEmpresa);
        empresa.criaDepartamentos(scan);

        empresa.departamentos.get(0).darAumentoAoFunc();

        // empresa.departamentos.get(0).retornaPrimFuncDep().nome;

        empresa.departamentos.get(1).funcionarios.add(empresa.departamentos.get(0).retornaPrimFuncDep());
        empresa.departamentos.get(0).funcionarios.remove(empresa.departamentos.get(0).retornaPrimFuncDep());

        // System.out.println(empresa.departamentos.get(1).somaSalarioDepartamento());

        for(int i=0;i<numDepEmpresa;i++){
            System.out.printf(local,"%s R$ %.2f\n",empresa.departamentos.get(i).getNome(),empresa.departamentos.get(i).somaSalarioDepartamento());
        }


        // empresa.departamentos.get(1).imprimeFuncionariosDoDep();

     
    }
}