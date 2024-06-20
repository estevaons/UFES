public class Funcionario {
    String nome;
    double salario;
    String dataAdimissao;


    public Funcionario(String nome, Double salario, String adm){
        this.nome = nome;
        this.salario = salario;
        this.dataAdimissao = adm;
    }

    public String getDataAdimissao(){
        return this.dataAdimissao;
    }
    public double getSalario(){
        return this.salario;
    }
    public String getNomeFuncionario(){
        return this.nome;
    }

    public void setAumentoSalario(){
        this.salario = this.salario *1.1;
    }
}
