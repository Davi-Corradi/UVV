import java.util.ArrayList;
import java.util.List;


public class Professor {
    private String nome;
    private List<Aluno> alunos;


    public Professor(String nome) {
        this.nome = nome;
        this.alunos = new ArrayList<>();
    }


    public void adicionarAluno(Aluno aluno) {
        boolean jaRegistrado = false;
        
        for (Aluno a : alunos) {
            if (a.getNome().equalsIgnoreCase(aluno.getNome())) {
                jaRegistrado = true;
                break;
            }
        }
        
        if (!jaRegistrado) {
            alunos.add(aluno);
            aluno.setProfessor(this);
            System.out.println("Aluno adicionado!");
        } else {
            System.out.println("Aluno já registrado!");
        }
    }


    public String getNome() {
        return nome;
    }


    public List<Aluno> getAlunos() {
        return alunos;
    }
}