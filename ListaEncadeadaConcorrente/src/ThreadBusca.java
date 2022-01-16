public class ThreadBusca extends Thread{
    private ListaEncadeada lista;
    private int elemento;

    public ThreadBusca(String nome, ListaEncadeada lista, int elemento){
        super(nome);
        this.lista = lista;
        this.elemento = elemento;
    }

    @Override
    public void run(){
        lista.buscaElemento(elemento, this.getName());
    }
}