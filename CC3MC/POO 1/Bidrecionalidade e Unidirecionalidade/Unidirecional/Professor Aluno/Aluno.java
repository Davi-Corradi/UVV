public class Aluno {
    private String nome;
    private Professor professor;


    public Aluno(String nome) {
        this.nome = nome;
    }


    public void setProfessor(Professor professor) {
        this.professor = professor;
    }


    public String getNome() {
        return nome;
    }


    public Professor getProfessor() {
        return professor;
    }
}