import java.util.ArrayList;
import java.util.List;

public class Cliente {
    
    private String nome;
    private String cpf;
    private List<Conta> contas = new ArrayList<>();
    
    public Cliente(String nome, String cpf){
        this.nome = nome;
        this.cpf = cpf;
    }
    
    public void mostrarSaldo(){
        for(Conta c: contas){
            System.out.println(c.TipoConta() + ": " + String.format("%.2f", c.getSaldo()));
        }
    }

    public void CriarConta(double saldo, int i){
        if(i == 1){
            ContaCorrente c1 = new ContaCorrente(saldo);
            contas.add(c1);
        }
        else if(i == 2){
            ContaPoupanca c2 = new ContaPoupanca(saldo);
            contas.add(c2);
        }
        else{
            System.out.println("Número inválido!");
        }
    }

    public String getNome() {
       return nome; 
    }
    
    public List<Conta> getContas(){
        return contas;
    }
}