public class Main {

    public static void main(String[] args) {
        System.out.println("=".repeat(30));

        Evento evento = new Evento("Programação Orientada à Objetos\n");
        
        Participante p1 = new Participante("Davi", "davi@uvv.br");
        Participante p2 = new Participante("João", "joao@uvv.br");
        Participante p3 = new Participante("Pedro", "pedro@uvv.br");
        Participante p4 = new Participante("Cassio", "cassio@uvv.br");
        
        evento.adicionarParticipante(p1);
        evento.adicionarParticipante(p2);
        evento.adicionarParticipante(p3);
        
        evento.imprimir();
        
        //evento.adicionarParticipante(p4);
        
        evento.removerParticipante(p1);
        evento.removerParticipante(p1);
        
    }
}
