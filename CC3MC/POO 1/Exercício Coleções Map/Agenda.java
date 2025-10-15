import java.util.Map;
import java.util.HashMap;

public class Agenda {
    
    Map<String, String> map = new HashMap<>();
     
    public void imprimir() {
        for (String key : map.keySet()) {
            System.out.println("Nome: " + key + ", Número: " + map.get(key));
        }
    }
    
    public void inserir(String nome, String numero) {
        map.put(nome, numero);
    }
    
    public String buscarNumero(String nome) {
        return map.get(nome);
    }
    
    public void remover(String nome) {
        map.remove(nome);
    }
    
    public int tamanho() {
        return map.size();
    }
}
