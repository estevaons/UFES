public class Aluno {
    String nome;
    double p1;
    double p2;
    double p3;
    String mediaTurma;

    public String getMediaTurma(){
        return this.mediaTurma;
    }

    public String getNome(){
        return this.nome;
    }
    public double getMedia(){
        return (p1+p2+p3)/3;
    }
    public void setMediaTurmaAcima(String data){
        this.mediaTurma = data;
    }
    public void setMediaTurmaAbaixo(String data){
        this.mediaTurma = data;
    }
    public void setMediaTurmaNaMedia(String data){
        this.mediaTurma = data;
    }
    


}
