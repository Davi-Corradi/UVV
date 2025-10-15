public class Main {

    public static void main(String[] args) {
        Editora editora = new Editora("Cassio Editora" , "cassio@uvv.com");
        
        Livro l1 = new Livro("O Hobbit", 1988);
        Livro l2 = new Livro("O Cássio", 1998);
        
        Autor a1 = new Autor("Cássio", "C");
        Autor a2 = new Autor("José de Alencar", "Jedi");

        a1.adicionarContato("Email", "cassio@gmail.com");
        a1.adicionarContato("Telefone", "(27) 99999-9999");
        a2.adicionarContato("Email", "jose@gmail.com");

        l1.adicicionarAutor(a2);
        l2.adicicionarAutor(a1);

        System.out.println("=== Editora ===");
        editora.exibir();
        System.out.println();

        System.out.println("=== Livros ===");
        l1.exibir();
        l2.exibir();
        System.out.println();

        System.out.println("=== Autores ===");
        a1.exibir();
        a2.exibir();

        System.out.println("\nPrograma executado com sucesso!");
    }
}
