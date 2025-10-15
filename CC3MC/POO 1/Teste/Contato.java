public class Contato {
   private String tipo;
   private String contato;

    public String getTipo() {
        return tipo;
    }

    public String getContato() {
        return contato;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public void setContato(String contato) {
        this.contato = contato;
    }
   
    public Contato(String tipo, String contato){
        this.contato = contato;
        this.tipo = tipo;
    }
}
