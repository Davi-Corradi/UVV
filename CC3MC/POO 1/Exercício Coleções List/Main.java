public class Main {
    public static void main(String[] args) {
        AgendaTelefonica agenda = new AgendaTelefonica();
        
        agenda.inserir("João", "(27) 91234-5678");
        agenda.inserir("Manassés", "(27) 99762-5678");
        agenda.inserir("Arthur", "(27) 99123-5678");
        agenda.inserir("Cássio", "(27) 99999-5678");
        agenda.inserir("Davi", "(27) 99888-5678");
        
        System.out.println("Buscando João:");
        Contato resultado = agenda.buscar("João");
        if (resultado != null) {
            System.out.println(resultado);
        } else {
            System.out.println("Contato não encontrado.");
        }

        System.out.println("\n=== Lista de Contatos ===");
        agenda.imprimir();
        
        System.out.println("\nContatos cadastrados: " + agenda.quantidade());
        
        System.out.println("\nRemovendo Cássio...");
        agenda.remover("Cássio");
        agenda.imprimir();
        System.out.println("\nContatos restantes: " + agenda.quantidade());
    }
}
