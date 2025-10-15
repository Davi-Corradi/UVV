public class Main {

    public static void main(String[] args) {
        System.out.println("CONTAS: ");
        
        Cliente cliente = new Cliente("Davi", "111.222.333-44");
        
        cliente.CriarConta(200, 1);
        cliente.CriarConta(300, 1);
        cliente.CriarConta(500, 2); 
        
        for(Conta c : cliente.getContas()){
            c.AplicarRendimento();
        }
        
        cliente.mostrarSaldo();
        
        cliente.getContas().get(0).Sacar(50);
        cliente.getContas().get(1).Sacar(50);
        cliente.getContas().get(2).Sacar(50);
        cliente.mostrarSaldo();
        
        for(Conta c: cliente.getContas()){
            if(c instanceof ContaCorrente){
                ((ContaCorrente) c).ReceberPix(100);
            }     
        }
        
        cliente.mostrarSaldo();
        
    }
}