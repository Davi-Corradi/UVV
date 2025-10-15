import java.util.ArrayList;
import java.util.List;

public class AgendaTelefonica {
    private List<Contato> colecao;

    public AgendaTelefonica() {
        this.colecao = new ArrayList<>();
    }

    public void inserir(String nome, String telefone) {
        Contato temp = new Contato(nome, telefone);
        this.colecao.add(temp);
    }

    public Contato buscar(String nome) {
        for (Contato aux : this.colecao) {
            if (aux.getNome().equalsIgnoreCase(nome)) {
                return aux;
            }
        }
        return null;
    }

    public int quantidade() {
        return this.colecao.size();
    }

    public void remover(String nome) {
        Contato deletar = this.buscar(nome);
        if (deletar != null) {
            this.colecao.remove(deletar);
            System.out.println("Deletado");
        } else {
            System.out.println("Nao encontrado");
        }
    }

    public void imprimir() {
        if (this.colecao.isEmpty()) {
            System.out.println("Agenda Vazia");
        } else {
            for (Contato aux : this.colecao) {
                System.out.println(aux.toString());
            }
        }
    }
}
