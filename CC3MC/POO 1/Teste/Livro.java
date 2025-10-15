import java.util.ArrayList;
import java.util.List;

public class Livro {
    private String titulo;
    private int anoPublicação;
    private List<Autor> autores = new ArrayList<>();
    
    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public int getAnoPublicação() {
        return anoPublicação;
    }

    public void setAnoPublicação(int anoPublicação) {
        this.anoPublicação = anoPublicação;
    }
    
    public Livro(String titulo, int anoPublicação){
        this.titulo = titulo;        
        this.anoPublicação = anoPublicação;
    }

    public void adicicionarAutor(Autor autor){
        if(!autores.contains(autor)){
            autores.add(autor);
        }
    }

    public void exibir() {
        System.out.println("Título: " + titulo + " | Ano: " + anoPublicação);
        if (autores.isEmpty()) {
            System.out.println("  Nenhum autor cadastrado.");
        } else {
            System.out.println("  Autores:");
            for (Autor a : autores) {
                System.out.println("    - " + a.getNome());
            }
        }
    }
}
