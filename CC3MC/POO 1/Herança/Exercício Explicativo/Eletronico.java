public class Eletronico extends Produto{
    private int voltagem;
    
    public Eletronico(String n, double p, int v){
        this.nome = n;
        this.preco = p;
        this.voltagem = v;  
    }
     public void ehCaro(int valor){
        if (preco > valor){
            System.out.println("Produto caro!");
        }
        else{
            System.out.println("Produto barato!");
        }
    } 

}