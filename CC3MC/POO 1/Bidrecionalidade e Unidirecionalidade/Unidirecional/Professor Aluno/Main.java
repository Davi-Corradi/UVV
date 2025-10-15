public class Main {
    public static void main(String[] args) {
        Aluno aluno1 = new Aluno("Davi");
        Aluno aluno2 = new Aluno("João");
        Aluno aluno3 = new Aluno("DAVI");


        Professor professor = new Professor("Cássio");


        professor.adicionarAluno(aluno1);
        professor.adicionarAluno(aluno2);
        professor.adicionarAluno(aluno3); 


        System.out.println("\nProfessor da Turma: " + professor.getNome());
        System.out.println("Alunos:");
        for (Aluno aluno : professor.getAlunos()) {
            System.out.println("- " + aluno.getNome());
        }
    }
}