public class ContaCorrente extends Conta implements Pix{

    public ContaCorrente(double saldo) {
        super(saldo);
    }
    
    @Override
    public void Sacar(double valor){
        if(getSaldo()>=(valor+5)){
            setSaldo(getSaldo()-(valor+5));
        }else{
            System.out.println("Saldo insuficiente!");
        }
    }
    
    @Override
    public void AplicarRendimento(){
        super.setSaldo(getSaldo()*1.012);
    }
    
    @Override
    public String TipoConta(){
        return "Conta Corrente";
    }
    
    @Override
    public void ReceberPix(double v){
        setSaldo(getSaldo() + v);
    }
}