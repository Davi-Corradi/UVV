public class Produto {
    public String nome;
    public double preco;
    
    public Produto(){
        
    }
    
    public Produto(String nome, double preco){
        this.nome = nome; 
        this.preco = preco;
    }
    
    public void ehCaro(){
        if (preco > 100){
            System.out.println("Produto caro!");
        }
        else{
            System.out.println("Produto barato!");
        }
    } 
}