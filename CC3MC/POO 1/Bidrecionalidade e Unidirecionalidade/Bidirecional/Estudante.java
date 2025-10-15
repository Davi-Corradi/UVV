import java.util.List;
import java.util.ArrayList;


public class Estudante{
    private String nome;
    private List<Curso> cursos;
    
    public Estudante(String nome){
        this.nome = nome;
        this.cursos = new ArrayList<>();
    }

    public String getNome(){
        return nome;
    }
    
    public void inscrever(Curso curso){
        if (!cursos.contains(curso)){
            cursos.add(curso);
            curso.adicionar(this);
        }
    }
    public List<Curso> getCursos(){
        return cursos;
    }
    
    public void imprimir(){
        System.out.println("Estudante: " + nome);
        System.out.println("Cursando: " + cursos.size() + " curso(s)");
        
        for (Curso c : cursos)  {
            System.out.println("-" + c.getNome());
        }
        System.out.println();
    } 
}


