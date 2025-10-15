public class Livro extends Produto{
    private String autor;
    private int paginas;
    
    public Livro(String n, double p, String a, int pg){
        this.nome = n;
        this.preco = p;
        this.paginas = pg;
        this.autor = a;
    }
    
    public void ehGrande(){
        if(paginas > 200){
            System.out.println("O livro é grande!");
        }
    }
    
    @Override
    public void ehCaro(){
        if(preco > 50){
            System.out.println("O livro é caro!");
        }
    }
}