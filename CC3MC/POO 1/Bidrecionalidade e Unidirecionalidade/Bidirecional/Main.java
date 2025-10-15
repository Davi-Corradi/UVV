public class Main {
    public static void main(String[] args) {
        
        Estudante e1 = new Estudante("Davi");
        Estudante e2 = new Estudante("Daniel");
        
        Curso c1 = new Curso("POO");
        Curso c2 = new Curso("Engenharia de Software");
        
        e1.inscrever(c1);
        e1.inscrever(c2);
        e2.inscrever(c1);
        
        c1.imprimir();
        c2.imprimir();
        
        e1.imprimir();
        e2.imprimir();
    }
}