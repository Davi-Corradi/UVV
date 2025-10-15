
import java.util.List;
import java.util.ArrayList;

public class Curso {
    private String nome;
    private List<Estudante> estudantes;

    public Curso(String nome) {
        this.nome = nome;
        this.estudantes = new ArrayList<>();
    }

    public void adicionar(Estudante estudante){
        if (!estudantes.contains(estudante)){
            estudantes.add(estudante);
            estudante.inscrever(this);
        }
    }
    
    public List<Estudante> getEstudantes(){
        return estudantes;
    }
    
    public String getNome(){
        return nome;
    }
    
    public void imprimir(){
        System.out.println("Curso: " + nome);
        System.out.println("Número de estudantes: " + estudantes.size());
        
        for (Estudante e : estudantes)  {
            System.out.println("-" + e.getNome());
        }
        System.out.println();
    } 
}
