import java.lang.Math;

public class Triangulo {
    Ponto a = new Ponto();
    Ponto b = new Ponto();
    Ponto c = new Ponto();

    public double calculaDistanciaDoisPontos(Ponto A,Ponto B){
        double deltaX = B.x-A.x;
        double deltaY = B.y-A.y;

        return Math.sqrt(Math.pow(deltaX, 2) + Math.pow(deltaY, 2));
    }

    public double perimetro(){
        double perimetro;
        double distAB;
        double distBC;
        double distAC;

        distAB = calculaDistanciaDoisPontos(this.a, this.b);
        distBC = calculaDistanciaDoisPontos(this.b, this.c);
        distAC = calculaDistanciaDoisPontos(this.a, this.c);

        perimetro = distAB + distBC + distAC;

        return perimetro;
    }

}
