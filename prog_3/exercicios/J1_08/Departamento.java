import java.util.ArrayList;
import java.util.Scanner;

public class Departamento {
    String nome;
    int numeroDeFuncionarios;

    double somaSalarioDep;

    ArrayList <Funcionario> funcionarios;

    public Departamento(String nome,int numFunc){
        this.nome = nome;
        this.numeroDeFuncionarios = numFunc;
        this.funcionarios = new ArrayList<>();
    }
 
    public void criaFuncionarios(Scanner scan){
        Funcionario funcionariosVet[] = new Funcionario[this.numeroDeFuncionarios];

        for(int i=0;i<this.numeroDeFuncionarios;i++){
            funcionariosVet[i] = new Funcionario(scan.next(),scan.nextDouble(),scan.next());
            funcionarios.add(i,funcionariosVet[i]);
        }
    }

    public Double somaSalarioDepartamento(){
    
        for (Funcionario funcionario : funcionarios) {
            this.somaSalarioDep += funcionario.getSalario();
        }
        return this.somaSalarioDep;
    }

    public Funcionario retornaPrimFuncDep(){
        return this.funcionarios.get(0);
    }

    public void darAumentoAoFunc(){
        for (Funcionario funcionario : funcionarios) {
            funcionario.setAumentoSalario();
        }
    }

    public String getNome(){
        return this.nome;
    }

    public void imprimeFuncionariosDoDep(){
        for (Funcionario funcionario : funcionarios) {
            System.out.println(funcionario.nome);
            System.out.println(funcionario.salario);
        }
    }



    public int getNumeroDeFuncDep(){
        return this.numeroDeFuncionarios; 
    }
    


}
