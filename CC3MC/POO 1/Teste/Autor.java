    import java.util.ArrayList;
    import java.util.List;
    
    public class Autor {
        private String nome;
        private String abreviatura;
        private List<Contato> contatos = new ArrayList<>();
        
        public String getNome() {
            return nome;
        }
    
        public void setNome(String nome) {
            this.nome = nome;
        }
    
        public String getAbreviatura() {
            return abreviatura;
        }
    
        public void setAbreviatura(String abreviatura) {
            this.abreviatura = abreviatura;
        }
        
        public Autor(String nome, String abreviatura){
            this.nome = nome;
            this.abreviatura = abreviatura;
        }
        
       public void adicionarContato(String tipo, String contato) {
    
        
        Contato novo = new Contato(tipo, contato);
        
        boolean existe = false;
        for (Contato c : contatos) {
            if (c.getTipo().equalsIgnoreCase(tipo) && c.getContato().equalsIgnoreCase(contato)) {
                existe = true;
                break;
            }
        }
    
            if (!existe)    {
                contatos.add(novo);
            }
        }
       
        public void exibir() {
            System.out.println("Autor: " + nome + " (" + abreviatura + ")");
            if (contatos.isEmpty()) {
                System.out.println("  Sem contatos cadastrados.");
            } else {
                for (Contato c : contatos) {
                    System.out.println("  " + c.getTipo() + ": " + c.getContato());
                }
            }
        }
    }
