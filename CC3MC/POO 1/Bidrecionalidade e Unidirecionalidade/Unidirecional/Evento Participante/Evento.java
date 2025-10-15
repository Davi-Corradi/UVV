import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Evento {
    private String nome;
    Set<Participante> participantes;
    
    public Evento(String nome){
        this.nome = nome;
        this.participantes = new HashSet<>();
    }
    
    public void imprimir(){
        if(participantes.isEmpty()){
            System.out.println("Evento vazio.");
        }
        else{
            System.out.println("\nEvento: " + this.nome);
            
            for(Participante temp: participantes){
                System.out.println(temp);
            }
        }
    }
    
    public void adicionarParticipante(Participante p){

        boolean retorno = participantes.add(p); 
        if(retorno == true){
            System.out.println("\nParticipante adicionado!");
        }
        else{
            System.out.println("\nParticipante já cadastrado");
        }   
    }
    
    public void removerParticipante(Participante p){
        boolean retorno = participantes.remove(p); 
        if(retorno == true){
            System.out.println("\nParticipante removido!");
        }
        else{
            System.out.println("\nParticipante não encontrado");
        }      
    }
}
