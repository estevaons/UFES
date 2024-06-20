import java.util.ArrayList;
import java.util.Scanner;

public class Empresa {
    String nome;
    String cnpj;
    int numeroDeDepartamentos;

    ArrayList <Departamento> departamentos;

    public Empresa(String nome, String cnpj, int NumDep){
        this.nome = nome;
        this.cnpj = cnpj;
        this.numeroDeDepartamentos = NumDep;
        this.departamentos = new ArrayList <>();      
    }

    public void criaDepartamentos(Scanner scan){
        Departamento departamentoVet[] = new Departamento[this.numeroDeDepartamentos];
        for(int i=0;i<this.numeroDeDepartamentos;i++){
            departamentoVet[i] = new Departamento(scan.next(),scan.nextInt());
            departamentoVet[i].criaFuncionarios(scan);
            departamentos.add(i,departamentoVet[i]);
        }
    }


    public void setNome(String data){
        this.nome = data;
    }
    public void setCnpj(String data){
        this.cnpj = data;
    }

}
