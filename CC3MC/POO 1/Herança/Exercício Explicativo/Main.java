public class Main {

    public static void main(String[] args) {
        Eletronico e1 = new Eletronico("Celular", 75, 110);
        Livro l1 = new Livro("POO", 149.9, "Cássio", 300);
        
        l1.ehCaro();
        l1.ehGrande();
        
        e1.ehCaro();
        e1.ehCaro(74);
    }
}
