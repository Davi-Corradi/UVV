public class Main {

    public static void main(String[] args) {
        System.out.println("AGENDA");
        
        Agenda ag = new Agenda(); // Corrigido: era AgendaTelefonica
        
        ag.inserir("Cassio", "1111111");
        ag.inserir("Pedro", "2222222");
        ag.inserir("Joao", "3333333");
        
        ag.imprimir();
        System.out.println("Quantidade de contatos: " + ag.tamanho());
        
        ag.remover("Cassio");
        System.out.println("Quantidade após remover Cassio: " + ag.tamanho());
    }
}
